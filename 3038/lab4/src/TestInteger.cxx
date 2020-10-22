#include "Integer.h"

using namespace std;

int main()
{
    int i = 10;

    Integer j;      // Default constructor no
    Integer k = 20; // Initialise from an int
    Integer l = i;  // Initialise from an int
    Integer m = k;  // Initialise from another object Integer

    cout << i << endl;
    cout << j << endl;
    cout << k << endl;
    cout << l << endl;
    cout << m << endl;

    cout << "Enter an int: " << endl;
    cin >> m;
    cout << "The value was: " << m << endl;
    
    m = 30;
    cout << m << endl;
    
    system("pause");
    return 0;
}
