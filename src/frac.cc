// MIT License
//
// Copyright (c) 2021 wsbky
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "frac.hh"

#include <iostream>
#include <stdexcept>

namespace extypes {

namespace err_msg {

constexpr char rerr_frac_0div[23] = "0 in denominator. NaN.";

}  // namespace err_msg

frac::frac() : nan(false) {}
frac::frac(int a) : num(a), den(1), nan(false) {}
frac::frac(int num, int den) : num(num), den(den), nan(den == 0) {}
frac::frac(const frac& f) : num(f.num), den(f.den), nan(f.nan) {}

frac frac::reciprocal() const { return frac(den, num); }
frac frac::reduce() const {
    int g = std::gcd(num, den);
    return frac(num / g, den / g);
}
bool frac::isnan() const { return nan; }

frac frac::operator+() const { return *this; }
frac frac::operator-() const { return frac(-num, den); }

frac::operator int() const {
    if (nan) throw std::runtime_error(err_msg::rerr_frac_0div);
    return int(num / den);
}
frac::operator float() const {
    if (nan) throw std::runtime_error(err_msg::rerr_frac_0div);
    return float(num) / float(den);
}
frac::operator double() const {
    if (nan) throw std::runtime_error(err_msg::rerr_frac_0div);
    return double(num) / double(den);
}
frac::operator long() const {
    if (nan) throw std::runtime_error(err_msg::rerr_frac_0div);
    return long(num / den);
}

frac& frac::operator+=(const frac& a) {
    nan |= a.nan;
    int l = std::lcm(den, a.den);
    num *= l / den;
    num += a.num * l / a.den;
    den = l;
    *this = (*this).reduce();
    return *this;
}
frac& frac::operator+=(int a) { return *this += frac(a, 1); }
frac& frac::operator+=(long a) { return *this += frac(a, 1); }

frac& frac::operator-=(const frac& a) {
    nan |= a.nan;
    return *this += -a;
}
frac& frac::operator-=(int a) { return *this -= frac(a, 1); }
frac& frac::operator-=(long a) { return *this -= frac(a, 1); }

frac& frac::operator*=(const frac& a) {
    nan |= a.nan;
    num *= a.num;
    den *= a.den;
    *this = (*this).reduce();
    return *this;
}
frac& frac::operator*=(int a) { return *this *= frac(a, 1); }
frac& frac::operator*=(long a) { return *this *= frac(a, 1); }

frac& frac::operator/=(const frac& a) {
    nan |= a.nan;
    return *this *= a.reciprocal();
}
frac& frac::operator/=(int a) { return *this /= frac(a, 1); }
frac& frac::operator/=(long a) { return *this /= frac(a, 1); }

frac frac::operator+(const frac& a) const {
    frac t = *this;
    return t += a;
}
frac frac::operator+(int a) const {
    frac t = *this;
    return t += a;
}
frac frac::operator+(long a) const {
    frac t = *this;
    return t += a;
}
float frac::operator+(float a) const {
    if (nan) throw std::runtime_error(err_msg::rerr_frac_0div);
    frac t = *this;
    return float(t) + a;
}
double frac::operator+(double a) const {
    if (nan) throw std::runtime_error(err_msg::rerr_frac_0div);
    frac t = *this;
    return double(t) + a;
}
frac operator+(int a, const frac& b) { return b + a; }
frac operator+(long a, const frac& b) { return b + a; }
float operator+(float a, const frac& b) {
    if (b.nan) throw std::runtime_error(err_msg::rerr_frac_0div);
    return b + a;
}
double operator+(double a, const frac& b) {
    if (b.nan) throw std::runtime_error(err_msg::rerr_frac_0div);
    return b + a;
}

frac frac::operator-(const frac& a) const {
    frac t = *this;
    return t -= a;
}
frac frac::operator-(int a) const {
    frac t = *this;
    return t -= a;
}
frac frac::operator-(long a) const {
    frac t = *this;
    return t -= a;
}
float frac::operator-(float a) const {
    if (nan) throw std::runtime_error(err_msg::rerr_frac_0div);
    frac t = *this;
    return float(t) - a;
}
double frac::operator-(double a) const {
    if (nan) throw std::runtime_error(err_msg::rerr_frac_0div);
    frac t = *this;
    return double(t) - a;
}
frac operator-(int a, const frac& b) { return -b + a; }
frac operator-(long a, const frac& b) { return -b + a; }
float operator-(float a, const frac& b) {
    if (b.nan) throw std::runtime_error(err_msg::rerr_frac_0div);
    return -b + a;
}
double operator-(double a, const frac& b) {
    if (b.nan) throw std::runtime_error(err_msg::rerr_frac_0div);
    return -b + a;
}

frac frac::operator*(const frac& a) const {
    frac t = *this;
    return t *= a;
}
frac frac::operator*(int a) const {
    frac t = *this;
    return t *= a;
}
frac frac::operator*(long a) const {
    frac t = *this;
    return t *= a;
}
float frac::operator*(float a) const {
    if (nan) throw std::runtime_error(err_msg::rerr_frac_0div);
    frac t = *this;
    return float(t) * a;
}
double frac::operator*(double a) const {
    if (nan) throw std::runtime_error(err_msg::rerr_frac_0div);
    frac t = *this;
    return double(t) * a;
}
frac operator*(int a, const frac& b) { return b * a; }
frac operator*(long a, const frac& b) { return b * a; }
float operator*(float a, const frac& b) {
    if (b.nan) throw std::runtime_error(err_msg::rerr_frac_0div);
    return b * a;
}
double operator*(double a, const frac& b) {
    if (b.nan) throw std::runtime_error(err_msg::rerr_frac_0div);
    return b * a;
}

frac frac::operator/(const frac& a) const {
    frac t = *this;
    return t /= a;
}
frac frac::operator/(int a) const {
    frac t = *this;
    return t /= a;
}
frac frac::operator/(long a) const {
    frac t = *this;
    return t /= a;
}
float frac::operator/(float a) const {
    if (nan) throw std::runtime_error(err_msg::rerr_frac_0div);
    frac t = *this;
    return float(t) / a;
}
double frac::operator/(double a) const {
    if (nan) throw std::runtime_error(err_msg::rerr_frac_0div);
    frac t = *this;
    return double(t) / a;
}
frac operator/(int a, const frac& b) { return frac(a) / b; }
frac operator/(long a, const frac& b) { return frac(a) / b; }
float operator/(float a, const frac& b) {
    if (b.nan) throw std::runtime_error(err_msg::rerr_frac_0div);
    return a / float(b);
}
double operator/(double a, const frac& b) {
    if (b.nan) throw std::runtime_error(err_msg::rerr_frac_0div);
    return a / double(b);
}

frac frac::operator%(const frac& a) const {
    return *this - floor(*this / a) * a;
}
frac frac::operator%(int a) const { return *this % frac(a); }
frac frac::operator%(long a) const { return *this % frac(a); }

frac frac::operator=(const frac& a) const noexcept { return frac(a); }
frac frac::operator=(int a) const noexcept { return frac(a, 1); }

bool frac::operator==(frac a) const {
    frac t = *this;
    t = t.reduce();
    a = a.reduce();
    return !t.nan && !a.nan && (t.num == a.num) && (t.den == a.den);
}
bool frac::operator==(int a) const { return *this == frac(a); }
bool frac::operator==(long a) const {
    frac t = *this;
    t.reduce();
    return !t.nan && (t.num == a) && (t.den == 1);
}
bool frac::operator==(float a) const { return float(*this) == a; }
bool frac::operator==(double a) const { return double(*this) == a; }
bool operator==(int a, const frac& b) { return b == a; }
bool operator==(long a, const frac& b) { return b == a; }
bool operator==(float a, const frac& b) { return b == a; }
bool operator==(double a, const frac& b) { return b == a; }

bool frac::operator!=(frac a) const { return !(*this == a); }
bool frac::operator!=(int a) const { return !(*this == a); }
bool frac::operator!=(long a) const { return !(*this == a); }
bool frac::operator!=(float a) const { return !(*this == a); }
bool frac::operator!=(double a) const { return !(*this == a); }
bool operator!=(int a, const frac& b) { return b != a; }
bool operator!=(long a, const frac& b) { return b != a; }
bool operator!=(float a, const frac& b) { return b != a; }
bool operator!=(double a, const frac& b) { return b != a; }

bool frac::operator>(frac a) const {
    if (nan || a.isnan()) throw std::runtime_error(err_msg::rerr_frac_0div);
    return (*this - a).num > 0;
}
bool frac::operator>(int a) const { return *this > frac(a); }
bool frac::operator>(long a) const { return *this > frac(a); }
bool frac::operator>(float a) const { return *this - a > 0; }
bool frac::operator>(double a) const { return *this - a > 0; }
bool operator>(int a, const frac& b) { return b <= a; }
bool operator>(long a, const frac& b) { return b <= a; }
bool operator>(float a, const frac& b) { return b <= a; }
bool operator>(double a, const frac& b) { return b <= a; }

bool frac::operator>=(frac a) const {
    if (nan || a.isnan()) throw std::runtime_error(err_msg::rerr_frac_0div);
    return (*this - a).num >= 0;
}
bool frac::operator>=(int a) const { return *this >= frac(a); }
bool frac::operator>=(long a) const { return *this >= frac(a); }
bool frac::operator>=(float a) const { return *this - a >= 0; }
bool frac::operator>=(double a) const { return *this - a >= 0; }
bool operator>=(int a, const frac& b) { return b < a; }
bool operator>=(long a, const frac& b) { return b < a; }
bool operator>=(float a, const frac& b) { return b < a; }
bool operator>=(double a, const frac& b) { return b < a; }

bool frac::operator<(frac a) const {
    if (nan || a.isnan()) throw std::runtime_error(err_msg::rerr_frac_0div);
    return (*this - a).num < 0;
}
bool frac::operator<(int a) const { return *this < frac(a); }
bool frac::operator<(long a) const { return *this < frac(a); }
bool frac::operator<(float a) const { return *this - a < 0; }
bool frac::operator<(double a) const { return *this - a < 0; }
bool operator<(int a, const frac& b) { return b >= a; }
bool operator<(long a, const frac& b) { return b >= a; }
bool operator<(float a, const frac& b) { return b >= a; }
bool operator<(double a, const frac& b) { return b >= a; }

bool frac::operator<=(frac a) const {
    if (nan || a.isnan()) throw std::runtime_error(err_msg::rerr_frac_0div);
    return (*this - a).num <= 0;
}
bool frac::operator<=(int a) const { return *this <= frac(a); }
bool frac::operator<=(long a) const { return *this <= frac(a); }
bool frac::operator<=(float a) const { return *this - a <= 0; }
bool frac::operator<=(double a) const { return *this - a <= 0; }
bool operator<=(int a, const frac& b) { return b > a; }
bool operator<=(long a, const frac& b) { return b > a; }
bool operator<=(float a, const frac& b) { return b > a; }
bool operator<=(double a, const frac& b) { return b > a; }

std::ostream& operator<<(std::ostream& os, const frac& a) {
    if (a.nan) os << "NaN";
    else
        os << "frac(" << a.num << ", " << a.den << ")";
    return os;
}

frac pow(const frac& a, int p) {
    frac r((p >= 0) ? a : a.reciprocal());
    r.num = std::pow(r.num, std::abs(p));
    r.den = std::pow(r.den, std::abs(p));
    return r;
}
int floor(const frac& a) {
    if (a.num % a.den >= 0) return a.num / a.den;
    else
        return a.num / a.den - 1;
}
int ceil(const frac& a) {
    if (a.num % a.den <= 0) return a.num / a.den;
    else
        return a.num / a.den + 1;
}
frac abs(const frac& a) { return (a >= 0) ? a : -a; }

std::string to_string(const frac& a) {
    if (a.nan) return "NaN";
    else
        return "frac(" + std::to_string(a.num) + ", " + std::to_string(a.den) +
               ")";
}

}  // namespace extypes
