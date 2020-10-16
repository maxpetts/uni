#include <iostream>
#include <string>

using namespace std;

float cels;
float fahr;

int main(int argc, char** argv) {
    if (argc == 2) {
        cels = stof(argv[1]);
    } else if (argc > 2) {
        cerr << "Improper usage. Wrong number of args." << endl;
        cerr << "Usage: $ " << argv[0] << " (temp in C) OR $ " << argv[0] << endl;
        return 1;
    } else {
        cout << "Please enter a temperature in Celsius : ";
        cin >> cels;
    }
    
    float fahr = cels * 1.8 + 32;
    cout << cels << " degrees Celcius is the same as " << fahr << " degrees Fahrenheit." << endl;
    return 0;
}
