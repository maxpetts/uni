#include <iostream>
#include <string>

using namespace std;

void printArray(const string& aName, float* anArray, unsigned int aNumberOfElements);


int main()
{
    // write your own code here
    float a[5] = {1.0, 2.0, 3.3, 40.0, 16.0};
    printArray("a", a, sizeof(a)/sizeof(a[0]));
    return 0;
}


void printArray(const string& aName, float* anArray, unsigned int aNumberOfElements)
{
    // write your own code here
    for (int i = 0; i < aNumberOfElements; i++) {
        cout << aName << "[" << i << "]:" << anArray[i] << endl;
    }
}
