
#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{
    // Start the block with the declaration and initialisation of the local variables
    int i = -1;
    unsigned int ui = -1;

    short s = -2;
    unsigned short us = -2;

    char c = 255;
    unsigned char uc = 255;

    float f = -1.2;
    double d = -1.4;

    char* string = "Hey you!";

//    printf("To print an int in C, I need: %i\n", i);
    cout << "To print and int in C, i need" << i << endl;
//    printf("To print an unsigned int in C, I need: %u\n", ui);
    cout << "To print an unsigned int in C, I need: " << ui << endl;

//    printf("To print a short in C, I need: %i\n", s);
    cout << "To print a short in C, I need: " << s << endl;
//    printf("To print an unsigned short in C, I need: %u\n", us);
    cout << "to print an unsigned short in C, I need: " << us << endl;
    
//    printf("To print a char in C, I need: %i\n", c);
    cout << "To print a char in C, I need: " << c << endl;
//    printf("To print an unsigned char in C, I need: %u\n", uc);
    cout << "To print an unsigned char in C, I need: " << uc << endl;
    
//    printf("To print a float in C, I need: %f\n", f);
    cout << "To print a float in C, I need: " << f << endl;
//    printf("To print a double in C, I need: %f\n", d);
    cout << "To print a double in C, I need: " << d << endl;

//    printf("To print a string in C, I need: %s\n", string);
    cout << "To print a string in C, I need: " << string << endl;

    return 0;
}
