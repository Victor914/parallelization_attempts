#include <iostream>
#include <mpi.h>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <vector>


using namespace std;

struct Info {
    double point, value;
};

void test_funct(double x, double & v) {
    double fac = 1;
    for (int i = 1; i < x; ++i) {
        fac *= i;
    }
     v = fac + pow(x, 4) * sin(-x / 10);
}

void print_vec(vector<Info> v) {
    for (Info el: v) 
        cout << "Value: " << el.value << "; point: " << el.point << ";=" << endl;
}

int main(int argc, char** argv) {
    int count_points = 48;
    double min = 1.0, max = 7.5;

    if (argc == 4) {
        min = atof(argv[1]);
        max = atof(argv[2]);
        count_points = atoi(argv[3]);
    }

    int root = 0;
    double step = (max - min) / (count_points - 1.0);
    vector<Info> mass(count_points);
    MPI_Init(NULL, NULL);
    
    MPI_Datatype InfoType;
    MPI_Datatype type[2] = { MPI_DOUBLE, MPI_DOUBLE };
    int blocklen[2] = { 1, 1 };
    MPI_Aint disp[2] = { 0, sizeof(double) };

  
    MPI_Type_create_struct(2, blocklen, disp, type, &InfoType);
    MPI_Type_commit(&InfoType);


    int rank, proc_num;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &proc_num);

    if (count_points % proc_num) {
        if (rank == 0) {
            cout << "The number of points is not a multiple of the number of processes" << endl;
            fflush(stdout);
        }
        MPI_Abort(MPI_COMM_WORLD, MPI_ERR_OTHER);
    }
    
    if (!rank) {
        double point = min;
        for (int i = 0; i < count_points; ++i) {
            mass[i].point = point;
            point += step;
        }
    }
    
    int sub_count_points = count_points / proc_num;
    vector<Info> part(sub_count_points);

    MPI_Scatter(mass.data(), sub_count_points, InfoType, part.data(), sub_count_points, InfoType, root, MPI_COMM_WORLD);
    
    for (int i = 0; i < sub_count_points; ++i) {
        test_funct(part[i].point, part[i].value);
    }

    MPI_Gather(part.data(), sub_count_points, InfoType, mass.data(), sub_count_points, InfoType, root, MPI_COMM_WORLD);

    if (!rank) {
        int i_max = 0;
        for (int i = 0; i < count_points; ++i) {
            cout << "Value: " << mass[i].value << "; point: " << mass[i].point << ";" << endl;
            if (mass[i].value > mass[i_max].value)
                i_max = i;
        }
        cout << "Best params: " << mass[i_max].point << endl;
    }

    MPI_Finalize();
    
    return 0;
}

//MPI_Send(info.data(), 343, InfoType, 1, 123, MPI_COMM_WORLD);
//MPI_Status status;
//MPI_Recv(info.data(), 343, InfoType, 0, 123, MPI_COMM_WORLD, &status);