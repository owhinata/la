#include <iostream>
#include <stdio.h>
#include <lapacke.h>

void printmat(int N, int M, double* A, int LDA) {
  double mtmp;
  printf("[ ");
  for (int i = 0; i < N; ++i) {
    printf("[ ");
    for (int j = 0; j < M; ++j) {
      mtmp = A[i + j * LDA];
      printf("%5.2e", mtmp);
      if (j < M -1) printf(", ");
    }
    if (i < N - 1) {
      printf("]; ");
    } else {
      printf("] ");
    }
  }
  printf("]");
}

int main() {
  int n = 3;
  double* A = new double[n*n];
  double* w = new double[n];

  A[0+0*n] = 1; A[0+1*n] = 2; A[0+2*n] = 3;
  A[1+0*n] = 2; A[1+1*n] = 5; A[1+2*n] = 4;
  A[2+0*n] = 3; A[2+1*n] = 4; A[2+2*n] = 6;

  printf("A ="); printmat(n,n,A,n); printf("\n");

  LAPACKE_dsyev(LAPACK_COL_MAJOR, 'V', 'U', n, A, n, w);

  printf("#eigenvalues \n");
  printf("w ="); printmat(n, 1, w, 1); printf("\n");
  printf("#eigenvecs \n");
  printf("U ="); printmat(n, n , A, n); printf("\n");
  printf("#check by Matlab/Octave by:\n");
  printf("eig(A)\n");
  printf("U'*A*U\n");

  delete[] w;
  delete[] A;
}

