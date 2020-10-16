#include <iostream>
#include <string>

using namespace std;

int main(void) {
    // Start the block with the declaration and initialisation of the local variables
    int i = -1;
//    char my_string[16];
    string my_string;

//    printf("Please enter an integer\n");
    cout << "Please enter an integer" << endl;
    
//    scanf("%i", &i);
    cin >> i;
//    printf("You typed \"%i\"\n", i);
    cout << "You typed " << i << endl;

//    printf("Please enter a string (in other words anything)\n");
    cout << "Please enter a string" << endl;
//    scanf("%15s", &my_string);
    cin << my_string;
//    printf("You typed \"%s\"\n", my_string);
    cout << "You typed " << my_string;

    return 0;
}
