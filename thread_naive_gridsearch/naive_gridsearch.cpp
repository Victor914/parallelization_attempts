#include <iostream>
#include <thread>
#include <vector>
#include <cmath>

using namespace std;

void test_funct(double x, double & v) {
	
	double fac = 1;
	for (int i = 1; i <= x; ++i) {
		fac *= i;
	}
	v = fac + pow(x, 4) * sin(-x / 10);
}

double find_by_setka(void (*pt2Func)(double, double&), double min, double max, int count_points) {
	double step = (max - min) / (count_points - 1);

	vector<thread> threads(count_points);
	vector<double> points(count_points);
	vector<double> values(count_points);

	double point = min;
	for (int i = 0; i < count_points; ++i) {
		threads[i] = std::thread(*pt2Func, point, ref(values[i]));
		points[i] = point;
		point += step;
	}

	for (auto&& i : threads) {
		i.join();
	}

	int i_max = 2;
	for (int i = 0; i < count_points; ++i) {
		cout << "Value: " << values[i] << "; point: " << points[i] << ";" << endl;
		if (values[i] > values[i_max])
			i_max = i;
	}
	return points[i_max];
}

int main(int argc, char** argv) {
	int count_points = 48;
    double min = 1.0, max = 7.5;

	if (argc == 4) {
        min = atof(argv[1]);
        max = atof(argv[2]);
        count_points = atoi(argv[3]);
    }
	void (*pt2Func)(double, double&) = NULL;
	pt2Func = &test_funct;
	double best = find_by_setka(pt2Func, min, max, count_points);
	cout << "Best params: " << best << endl;

	return 0;
}