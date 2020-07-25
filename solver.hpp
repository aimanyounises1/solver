#pragma once
#include <iostream>
#include <complex>
#include <cmath>
using namespace std;
using namespace std::complex_literals;

namespace solver
{
    class RealVariable
    {
    public:
        double a, b, c;

        RealVariable(double a) : a(0), b(0), c(a) {}
        RealVariable() : a(0), b(1), c(0) {}
    };
    class ComplexVariable
    {

    public:
        complex<double> a, b, c;
        ComplexVariable() : a(0), b(1), c(0) {}
        ComplexVariable(double aa) : a(0), b(0), c(aa) {}
        ComplexVariable(complex<double> aa) : a(0), b(0), c(aa) {}
    };
    RealVariable operator+(const RealVariable &r, const RealVariable &rr);

    RealVariable operator-(const RealVariable &r, const RealVariable &rr);

    RealVariable operator*(const RealVariable &r, const RealVariable &rr);

    RealVariable operator==(const RealVariable &r, const RealVariable &rr);

    RealVariable operator/(const RealVariable &r, const RealVariable &);

    RealVariable operator^(const RealVariable &, const int);
    ComplexVariable operator+(const ComplexVariable &, const ComplexVariable &);
    ComplexVariable operator-(const ComplexVariable &, const ComplexVariable &);
    ComplexVariable operator*(const ComplexVariable &, const ComplexVariable &);
    ComplexVariable operator/(const ComplexVariable &, const ComplexVariable &);
    ComplexVariable operator^(const ComplexVariable &, const int);
    ComplexVariable operator==(const ComplexVariable &, const ComplexVariable &);
    double solve(const RealVariable &);
    complex<double> solve(const ComplexVariable &);

} // namespace solver