#include <iostream>
#include <string>
#include "smartptr-out.h"

using namespace std;

int main(int argc, char** argv) {
    cout << boolalpha;
    SmartPtr<double> sp1;
    cout << "sp1: " << sp1 << "\n";
    SmartPtr<double> sp2 {sp1};
    cout << "sp2: " << sp2 << "\n";
    return 0;
}
