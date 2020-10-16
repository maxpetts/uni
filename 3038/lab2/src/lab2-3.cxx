#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int cels;
    
    cout << "Please enter a temperature in Celsius : ";
    cin >> cels;
    
    float fahr = cels * 1.8 + 32;
    
    cout << cels << " degrees Celcius is the same as " << fahr << " degrees Fahrenheit." << endl;
}
