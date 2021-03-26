pt foo(pt a, pt b, pt c)
{
  a -= b, c -= b;
  return cconj(a*cexp(-I*carg(c)))*cexp(I*carg(c)) + b;
}
