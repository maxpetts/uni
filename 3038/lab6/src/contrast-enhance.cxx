#include <iostream>
#include <exception>
#include <string>

#include "Image.h"

using namespace std;

int main(int argc, char** argv)
{
    try {
        if (argc == 4) {
            if (strcmp(argv[1], "-display") == 0) {
                Image input(argv[2]);
                Image output = 255 * input.normalise();
                output.save(argv[3]);
                
                input.display("input");
                output.display("output");
            } else {
                string error_message = "Are you sure you typed the correct option? \nOr did you type them in the wrong order?\n";
                error_message += " Potential options:  -display";
                error_message += "\nUsage: ";
                error_message += argv[0];
                error_message += " [options] input_image output_image";
                throw error_message;
            }
        } else if (argc == 3) {
            Image input(argv[1]);
            Image output = 255 * input.normalise();
            output.save(argv[2]);
        }
    } catch (const exception& e) {
        cerr << "An error occured, see the message below." << endl;
        cerr << e.what() << endl;
        return 1;
    } catch (const string& e) {
        cerr << "An error occured, see the message below." << endl;
        cerr << e << endl;
        return 2;
    } catch (const char* e) {
        cerr << "An error occured, see the message below." << endl;
        cerr << e << endl;
        return 3;
    }
    
    return 0;
}
