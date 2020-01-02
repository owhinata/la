# la
benchmark of several blas library

## spec
```
Core i7-5500U @2.40GHz Broadwell
Hynix H9CCNNNBLTALAR-NUD 1600MHz 64bits 4GiBx2
Ubuntu 16.04.6 LTS
4.15.0-72-generic

153.6 GFLOPS = (2.4GHz * 16 * 4 core)
25.6GB/s
```

## misc
```
lsb_release -a
uname -r
lspci
sudo lshw
sudo dmidecode
ldconfig --print-cache
lsof -p `pidof octave-cli`
sudo i7z
```
### install
```
sudo apt-get install gfortran g++ libblas-dev liblapack-dev liblapacke-dev
sudo apt-get install libopenblas-base libopenblas-dev
```
https://software.intel.com/en-us/articles/installing-intel-free-libs-and-python-apt-repo
https://askubuntu.com/questions/891189/octave-4-2-1-and-intel-mkl

### turbo boost, cpufreq
```
sudo wrmsr -a 0x1a0 0x4000850089
for i in `seq 0 3`; do sudo cpufreq-set -c $i -g performance; done
```

## dgemm (GFLOPS, 5times)
|octave(ref)|octave(openblas)|octave(mkl)|python(ref)|python(openblas)|python(mkl)|eigen|eigen(mkl)|
|--:|--:|--:|--:|--:|--:|--:|--:|
|2.0002|31.465|32.135|2.023207|30.374393|33.365595|8.76898|54.6184|
|1.9987|34.528|45.662|2.020598|33.338267|46.075110|8.76576|57.3386|
|2.0553|39.531|53.798|2.043077|37.810654|52.547204|8.78007|57.3722|
|1.9733|36.404|50.526|2.059465|35.151355|49.166192|8.77701|57.3402|
|1.9301|40.848|55.455|2.030061|40.728836|50.206630|8.77992|57.3311|

## Octave bench (ref, openblas, mkl)
```
   Octave Benchmark
   ================
Number of times each test is run__________________________: 3

   I. Matrix calculation
   ---------------------
Creation, transp., deformation of a 1200x1200 matrix (sec): 0.064555 0.057264  0.06425
1250x1250 normal distributed random matrix ^1000____ (sec): 0.033353 0.029674  0.033452
Sorting of 1,100,000 random values__________________ (sec): 0.1726   0.17134   0.17267
550x550 cross-product matrix (b = a' * a)___________ (sec): 0.107    0.0068047 0.017446
Linear regression over a 700x700 matrix (c = a \\ b') (sec): 0.11999 0.022059  0.022675
                      --------------------------------------------
                      Trimmed mean (2 extremes eliminated): 0.097181 0.036332  0.040126

   II. Matrix functions
   --------------------
FFT over 900,000 random values______________________ (sec): 0.034822 0.015438 0.036677
Eigenvalues of a 220x220 random matrix______________ (sec): 0.069273 0.078135 0.033562
Determinant of a 750x750 random matrix______________ (sec): 0.12893  0.022435 0.012352
Cholesky decomposition of a 1000x1000 matrix________ (sec): 0.21287  0.016782 0.01011
Inverse of a 500x500 random matrix__________________ (sec): 0.10893  0.017818 0.016523
                      --------------------------------------------
                      Trimmed mean (2 extremes eliminated): 0.10238  0.019012 0.020812

   III. Programmation
   ------------------
225,000 Fibonacci numbers calculation (vector calc)_ (sec): 0.040739  0.053228 0.057519
Creation of a 1500x1500 Hilbert matrix (matrix calc) (sec): 0.040508  0.046181 0.029939
Grand common divisors of 35,000 pairs (recursion)___ (sec): 0.0060977 0.011761 0.010433
Creation of a 220x220 Toeplitz matrix (loops)_______ (sec): 0.61772   0.61863  0.61015
Escoufier's method on a 22x22 matrix (mixed)________ (sec): 0.3356    0.31542  0.33973
                      --------------------------------------------
                      Trimmed mean (2 extremes eliminated): 0.13895   0.13861  0.1424


Total time for all 15 tests_________________________ (sec): 2.093     1.484    1.4675
Overall mean (sum of I, II and III trimmed means/3)_ (sec): 0.11284   0.064651 0.067778
                      --- End of test ---
```

# Jetson Nano

## stream
```
Function    Best Rate MB/s  Avg time     Min time     Max time
Copy:            7528.0     0.021455     0.021254     0.022899
Scale:           7549.0     0.021417     0.021195     0.022787
Add:             7415.5     0.032612     0.032365     0.034122
Triad:           7387.5     0.032673     0.032487     0.033583
```
## dgemm (GFLOPS, 5times)
|eigen|eigen(ref)|eigen(openblas)|
|--:|--:|--:|
|2.43073|0.931087|6.18770|
|2.42891|0.931081|6.18625|
|2.42796|0.928404|6.17801|
|2.43156|0.931045|6.18769|
|2.43026|0.931116|6.17863|
