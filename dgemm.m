runs = 5;
%p=96; q=363; r=3072;
n=1250; p=n; q=n; r=n;
alpha=1.0; beta=1.0;
for i = 1 : runs
  A=randn(p,q); B=randn(q,r); C=randn(p,r);
  tic;
    R=alpha*A*B+beta*C;
  elapsed=toc;
  (2*p*q*r+3*p*r)/elapsed*1e-9
end;
