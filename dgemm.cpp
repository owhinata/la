/*
g++ dgemm.cpp -o dgemm -std=c++11 -O3 -isystem /usr/include/eigen3 \
-DEIGEN_USE_BLAS -I/opt/intel/mkl/include -lblas
*/

#include <iostream>
#include <chrono>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std::chrono;

int main(int argc, char* argv[]) {
  int runs = 5;
  //int p = 96, q = 363, r = 3072;
  long n = 2500, p = n, q = n, r = n;
  double alpha = 1.0, beta = 1.0;

  for (int i = 0; i < runs; ++i) {
    MatrixXd A = MatrixXd::Random(p,q);
    MatrixXd B = MatrixXd::Random(q,r);
    MatrixXd C = MatrixXd::Random(p,r);

    auto t1 = steady_clock::now();
    C = alpha*A*B + beta*C;
    auto t2 = steady_clock::now();

    double elapsed = duration_cast<nanoseconds>(t2-t1).count() * 1e-9;

    std::cout << "ans =  "
      << (2*p*q*r + 3*p*r) / elapsed * 1e-9
      << std::endl;
  }
}
