#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    cout << "The program is: " << argv[0] << endl;
    
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            cout << "Argument " << i << " is: " << argv[i] << endl;
        }
    } else {
        cout << "No other arguments were passed." << endl;
    }
    
    return 0;
}
