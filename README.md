# Fraction Library for C++

[![Build](https://github.com/wsbky/frac-cpp/actions/workflows/build.yml/badge.svg)](https://github.com/wsbky/frac-cpp/actions/workflows/build.yml)

This library provides fraction computation features:

- `src/frac.hh` : header file
- `src/frac.cc` : implementation file

## Licence

MIT License. See `LICENSE` file for details.

## Class features

### Constructors

#### frac

```c++
extypes::frac a;
```

#### frac(int)

```c++
extypes::frac a(2);
cout << a;      // frac(2, 1) = 2 / 1
```

#### frac(int, int)

```c++
extypes::frac a(2, 3);
cout << a;      // frac(2, 3) = 2 / 3
```

#### frac(frac)

```c++
extypes::frac a(extypes::frac(2, 3));
cout << a;      // frac(2, 3) = 2 / 3
```

### Methods

#### reciprocal()

Returns the reciprocal of the original.

```c++
extypes::frac a(3, 2);
cout << a.reciprocal;   // frac(2, 3)
```

#### reduce()

Returns the reduced of the original.

```c++
extypes::frac a(10, 15);
cout << a.reduce();     // frac(2, 3)
```

#### isnan()

Returns whether the fraction is invalid.

```c++
extypes::frac a(1, 1);
extypes::frac b(1, 0);
cout << a.isnan();      // false
cout << b.isnan();      // true
```

### Functions

#### pow(frac, int) -> frac

Returns a frac powered by int.

```c++
extypes::frac a(2, 3);
cout << pow(a, 3);      // frac(8, 27)
```

#### floor(frac) -> int

Returns the floor.

```c++
extypes::frac a(3, 2);
cout << floor(a);       // 1
```

#### ceil(frac) -> int

Returns the ceil.

```c++
extypes::frac a(3, 2);
cout << ceil(a);       // 2
```

#### abs(frac) -> frac

Returns the abs.

```c++
extypes::frac a(3, 2);
extypes::frac b(-3, 2);
cout << a;             // frac(3, 2)
cout << b;             // frac(3, 2)
```

### Operators

#### Compound addition

```c++
frac += frac
frac += int
frac += long
```

#### Compound subtraction

```c++
frac -= frac
frac -= int
frac -= long
```

#### Compound multipication

```c++
frac *= frac
frac *= int
frac *= long
```

#### Compound division

```c++
frac /= frac
frac /= int
frac /= long
```

#### Addition

```c++
frac + frac -> frac
frac + int -> frac
frac + long -> frac
frac + float -> float
frac + double -> double
int + frac -> frac
long + frac -> frac
float + frac -> float
double + frac -> double
```

#### Subtraction

```c++
frac - frac -> frac
frac - int -> frac
frac - long -> frac
frac - float -> float
frac - double -> double
int - frac -> frac
long - frac -> frac
float - frac -> float
double - frac -> double
```

#### Multipication

```c++
frac * frac -> frac
frac * int -> frac
frac * long -> frac
frac * float -> float
frac * double -> double
int * frac -> frac
long * frac -> frac
float * frac -> float
double * frac -> double
```

#### Division

```c++
frac / frac -> frac
frac / int -> frac
frac / long -> frac
frac / float -> float
frac / double -> double
int / frac -> frac
long / frac -> frac
float / frac -> float
double / frac -> double
```

#### Modules

```c++
frac % frac -> frac
frac % int -> frac
frac % long -> frac
frac % float -> float
frac % double -> double
```

#### Assignment

```c++
frac = frac
frac = int
```

#### Relational Operator

##### equal

```c++
frac == frac
frac == int
frac == long
frac == float
frac == double
int == frac
long == frac
float == frac
double == frac
```

##### not equal

```c++
frac != frac
frac != int
frac != long
frac != float
frac != double
int != frac
long != frac
float != frac
double != frac
```

##### greater than (or equal)

```c++
frac >(=) frac
frac >(=) int
frac >(=) long
frac >(=) float
frac >(=) double
int >(=) frac
long >(=) frac
float >(=) frac
double >(=) frac
```

##### less than (or equal)

```c++
frac <(=) frac
frac <(=) int
frac <(=) long
frac <(=) float
frac <(=) double
int <(=) frac
long <(=) frac
float <(=) frac
double <(=) frac
```

#### Output

```c++
ostream << frac
