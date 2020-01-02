import numpy as np
import time

runs = 5
#p=96; q=363; r=3072;
n=1250; p=n; q=n; r=n;
alpha=1.0; beta=1.0;
for _ in range(runs):
  A=np.random.randn(p,q)
  B=np.random.randn(q,r)
  C=np.random.randn(p,r)
  start=time.time()
  R=alpha*A.dot(B)+beta*C
  elapsed=time.time()-start
  print('ans =  %f' % ((2*p*q*r+3*p*r)/elapsed*1e-9))

