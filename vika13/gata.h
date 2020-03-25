pt foo(pt a, pt b, pt c)
{
  a -= b, c -= b;
  return conj(a*exp(pt(0, -1)*arg(c)))*exp(pt(0, 1)*arg(c)) + b;
}
