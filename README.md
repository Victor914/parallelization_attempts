# parallelization_attempts

*Запускаем реализацию с обычным разделением на потоки:*
```
...\thread_naive_gridsearch>naive_gridsearch.exe 1 7.5 50
Value: 0.900167; point: 1;
Value: 0.809304; point: 1.1383;
Value: 0.661868; point: 1.2766;
Value: 0.434843; point: 1.41489;
Value: 0.0997203; point: 1.55319;
Value: -0.378077; point: 1.69149;
Value: -1.03975; point: 1.82979;
Value: -1.93368; point: 1.96809;
Value: -2.11595; point: 2.10638;
Value: -3.65093; point: 2.24468;
Value: -5.61172; point: 2.38298;
Value: -8.08072; point: 2.52128;
Value: -11.1501; point: 2.65957;
Value: -14.9223; point: 2.79787;
Value: -19.5104; point: 2.93617;
Value: -21.0387; point: 3.07447;
Value: -27.6433; point: 3.21277;
Value: -35.472; point: 3.35106;
Value: -44.6852; point: 3.48936;
Value: -55.4561; point: 3.62766;
Value: -67.9712; point: 3.76596;
Value: -82.4303; point: 3.90426;
Value: -81.0473; point: 4.04255;
Value: -100.05; point: 4.18085;
Value: -121.681; point: 4.31915;
Value: -146.197; point: 4.45745;
Value: -173.871; point: 4.59574;
Value: -204.99; point: 4.73404;
Value: -239.856; point: 4.87234;
Value: -182.788; point: 5.01064;
Value: -226.119; point: 5.14894;
Value: -274.2; point: 5.28723;
Value: -327.396; point: 5.42553;
Value: -386.088; point: 5.56383;
Value: -450.676; point: 5.70213;
Value: -521.572; point: 5.84043;
Value: -599.207; point: 5.97872;
Value: -84.0256; point: 6.11702;
Value: -176.491; point: 6.25532;
Value: -277.081; point: 6.39362;
Value: -386.289; point: 6.53191;
Value: -504.624; point: 6.67021;
Value: -632.611; point: 6.80851;
Value: -770.79; point: 6.94681;
Value: 3400.28; point: 7.08511;
Value: 3240.04; point: 7.2234;
Value: 3067.9; point: 7.3617;
Value: 2883.25; point: 7.5;
Best params: 7.08511
Time execution: 0.066
```

*Запускаем реализацию с распараллеливанием по технологии MPI:*
```
...\mpi_naive_gridsearch>mpiexec -n 10 mpi_naive_gridsearch.exe 1 7.5 50
Value: 0.900167; point: 1;
Value: 0.813982; point: 1.13265;
Value: 0.676541; point: 1.26531;
Value: 0.467822; point: 1.39796;
Value: 0.163186; point: 1.53061;
Value: -0.267078; point: 1.66327;
Value: -0.858215; point: 1.79592;
Value: -1.65145; point: 1.92857;
Value: -1.69442; point: 2.06122;
Value: -3.04165; point: 2.19388;
Value: -4.7549; point: 2.32653;
Value: -6.90366; point: 2.45918;
Value: -9.56551; point: 2.59184;
Value: -12.8265; point: 2.72449;
Value: -16.7817; point: 2.85714;
Value: -21.5352; point: 2.9898;
Value: -23.2009; point: 3.12245;
Value: -29.9026; point: 3.2551;
Value: -37.7745; point: 3.38776;
Value: -46.9611; point: 3.52041;
Value: -57.6183; point: 3.65306;
Value: -69.9129; point: 3.78571;
Value: -84.0233; point: 3.91837;
Value: -82.1397; point: 4.05102;
Value: -100.464; point: 4.18367;
Value: -121.212; point: 4.31633;
Value: -144.608; point: 4.44898;
Value: -170.894; point: 4.58163;
Value: -200.322; point: 4.71429;
Value: -233.157; point: 4.84694;
Value: -269.677; point: 4.97959;
Value: -214.175; point: 5.11224;
Value: -258.955; point: 5.2449;
Value: -308.337; point: 5.37755;
Value: -362.653; point: 5.5102;
Value: -422.248; point: 5.64286;
Value: -487.482; point: 5.77551;
Value: -558.728; point: 5.90816;
Value: -36.3726; point: 6.04082;
Value: -120.816; point: 6.17347;
Value: -212.473; point: 6.30612;
Value: -311.769; point: 6.43878;
Value: -419.145; point: 6.57143;
Value: -535.055; point: 6.70408;
Value: -659.965; point: 6.83673;
Value: -794.355; point: 6.96939;
Value: 3381.28; point: 7.10204;
Value: 3226.44; point: 7.23469;
Value: 3060.61; point: 7.36735;
Value: 2883.25; point: 7.5;
Best params: 7.10204
Time execution: 0.00374
```