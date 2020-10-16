#include <iostream>

using namespace std;

int main()
{

    int a = 5.0;
    int divisor = 3.0;
    float division = a / divisor;
    float remainder = a % divisor;
    float b = division * divisor + remainder;
    
    cout << a << " / " << divisor << " = " << division << endl;
    cout << a << " % " << divisor << " = " << remainder << endl;

    cout << division << " * " << divisor << " + " << remainder<< " = " << b << endl;

    return 0;
}
