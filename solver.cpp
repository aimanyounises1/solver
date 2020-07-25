#include <iostream>
#include "solver.hpp"
#include <cmath>
#include <exception>
#include <complex>
using namespace std;
using namespace std::complex_literals;
using solver::RealVariable; solver::ComplexVariable;
 solver::solve;

RealVariable solver::operator+(const RealVariable &r, const RealVariable &rr)
{
  RealVariable c;
  c.a = r.a + rr.a;
  c.b = r.b + rr.b;
  c.c = r.c + rr.c;

  return c;
}

RealVariable solver::operator-(const RealVariable &r, const RealVariable &rr)
{
  RealVariable c;
  c.a = r.a - rr.a;
  c.b = r.b - rr.b;
  c.c = r.c - rr.c;

  return c;
}

RealVariable solver::operator*(const RealVariable &r, const RealVariable &rr)
{
  if ((r.a != 0 && rr.a != 0) || (r.a != 0 && rr.b != 0) || (r.b != 0 && rr.a != 0))
    throw runtime_error("not allowed more than the power of 2");
  RealVariable x;
  if ((r.a == 0 && r.b == 0 && r.c == 0) || (rr.a == 0 && rr.b == 0 && rr.c == 0))
  {
    x.a = 0;
    x.b = 0;
    x.c = 0;
  }

  double a, b, c;

  /* a=r.b*rr.b;
  b=r.b*rr.c+r.c*rr.b;
  c=r.c*rr.c;
  if(r.a!=0)
  a=a+r.a;
  else
  a=a+r.b;
  
  
  x.a=a;
  x.b=b;
  x.c=c;*/
  x.a = r.b * rr.b + r.a * rr.c + r.c * rr.a;
  x.b = r.b * rr.c + r.c * rr.b;
  x.c = r.c * rr.c;
  return x;
}

RealVariable solver::operator==(const RealVariable &r, const RealVariable &rr)
{

  return r - rr;
}

RealVariable solver::operator/(const RealVariable &r, const RealVariable &rr)
{

  RealVariable c;
  c.a = r.a / rr.c;
  c.b = r.b / rr.c;
  c.c = r.c / rr.c;

  return c;
}

RealVariable solver::operator^(const RealVariable &r, const int d)
{
  RealVariable x;
  if (d < 0 && d > 2)
    throw runtime_error("not allowed more than the power of 2");

  if (d == 0)
  {
    x.a = 0;
    x.b = 0;
    x.c = 1;
  }
  if (d == 2 && r.a != 0)
  {
    throw runtime_error("not allowed more than the power of 2");
  }
  if (d == 2)
  {
    x.a = pow(r.b, 2);

    x.b = 2 * r.b * r.c;
    x.c = pow(r.c, 2);
  }
  else
  {
    x.a = r.a;
    x.b = r.b;
    x.c = r.c;
  }
  return x;
}

double solver::solve(const RealVariable &r)
{
  double x;

  if (r.a == 0 && r.b == 0 && r.c != 0)
    throw runtime_error("no solution");
  if (r.a != 0)
  {
    x = (-(r.b) + sqrt(pow(r.b, 2) - (4 * r.a * r.c))) / (2 * r.a);
  }
  else
    x = r.c / -(r.b);
  if (isnan(x))
    throw runtime_error("no solution");

  return x;
}

ComplexVariable solver::operator+(const ComplexVariable &r, const ComplexVariable &rr)
{
  ComplexVariable c;
  c.a = r.a + rr.a;
  c.b = r.b + rr.b;
  c.c = r.c + rr.c;
  return c;
}
ComplexVariable solver::operator-(const ComplexVariable &r, const ComplexVariable &rr)
{

  ComplexVariable c;
  c.a = r.a - rr.a;
  c.b = r.b - rr.b;
  c.c = r.c - rr.c;
  return c;
}

ComplexVariable solver::operator*(const ComplexVariable &r, const ComplexVariable &rr)
{
  double z = 0;
  if ((r.a != z && rr.a != z) || (r.a != z && rr.b != z) || (r.b != z && rr.a != z))
    throw runtime_error("not allowed more than the power of 2");

  ComplexVariable x;
  complex<double> a, b, c;

  x.a = r.b * rr.b + r.a * rr.c + r.c * rr.a;
  x.b = r.b * rr.c + r.c * rr.b;
  x.c = r.c * rr.c;
  return x;
}
ComplexVariable solver::operator/(const ComplexVariable &r, const ComplexVariable &rr)
{
  ComplexVariable c;
  c.a = r.a / rr.c;
  c.b = r.b / rr.c;
  c.c = r.c / rr.c;

  return c;
}

ComplexVariable solver::operator^(const ComplexVariable &r, const int d)
{
  double z = 0;
  ComplexVariable x;
  if (d < 0 && d > 2)
    throw runtime_error("not allowed more than the power of 2");

  if (d == 0)
  {
    x.a = 0;
    x.b = 0;
    x.c = 1;
    return x;
  }
  if (d == 2 && r.a != z)
  {
    throw runtime_error("not allowed more than the power of 2");
  }
  if (d == 2)
  {
    x.a = pow(r.b, 2);

    x.b = 2.0 * r.b * r.c;
    x.c = pow(r.c, 2);
  }
  else
  {
    x.a = r.a;
    x.b = r.b;
    x.c = r.c;
  }
  return x;
}

ComplexVariable solver::operator==(const ComplexVariable &r, const ComplexVariable &rr)
{
  return r - rr;
}

complex<double> solver::solve(const ComplexVariable &r)
{
  double z = 0;
  complex<double> x(0, 0);
  double y, discrement1 = 0, discrement2 = 0;
  discrement1 = pow(r.b.real(), 2) - (4.0 * r.a.real() * r.c.real());
  discrement2 = pow(r.b.imag(), 2) - (4.0 * r.a.imag() * r.c.imag());

  if (r.a.real() != 0)
  {
    if (discrement1 >= 0)
      x += (-(r.b.real()) + sqrt(discrement1)) / (2 * r.a.real());
    else
      x += ((-(r.b.real()) + sqrt(-discrement1)) / (2 * r.a.real()) * 1i);
  }

  if (r.a.imag() != 0)
  {
    if (discrement2 >= 0)
      x += ((-(r.b.imag()) + sqrt(discrement1)) / (2 * r.a.imag()) * 1i);
    else
      x += (-(r.b.imag()) + sqrt(-discrement1)) / (2 * r.a.imag());
  }

  else if (r.a.real() == 0)
    x += r.c / -(r.b);

  if (r.b.real() == 0 && r.a.real() == 0 && r.a.imag() == 0 && r.b.imag() == 0 && (r.c.real() != 0 || r.c.imag() != 0))
    throw runtime_error("no solution");

  return x;
}
