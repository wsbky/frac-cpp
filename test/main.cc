#include <iostream>

#include "frac.hh"

using namespace std;
using namespace extypes;

int main() {
    frac a(2, 3);
    a += 1;
    cout << a << endl;
    return 0;
}
