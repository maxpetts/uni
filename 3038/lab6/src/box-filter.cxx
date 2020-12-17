#include <iostream>
#include <exception>
#include <string>

#include "Image.h"

using namespace std;

int main(int argc, char** argv) {
    try {
        switch (argc) {
            case 4: {
                Image input(argv[2]);
                Image output(input.boxFilter());
                output.save(argv[3]);
                
                if (strcmp(argv[1], "-display") == 0) {
                    input.display("input");
                    output.display("output");
                } else {
                    string error_message = "Are you sure you typed the correct option?";
                    error_message += " Potential options:  -display";
                    throw error_message;
                }
                break;
            }
            case 3: {
                cout << "case 3 ";
                Image input(argv[1]);
                Image output(input.boxFilter());
                output.save(argv[2]);
                break;
            }
            default:
                string error_message = "Usage: ";
                error_message += argv[0];
                error_message += "  input_image output_image [options]";
                throw error_message;
                break;
        }
    }
    catch (const exception& e) {
        cerr << "An error occured, see the message below." << endl;
        cerr << e.what() << endl;
        return 1;
    }
    catch (const string& e) {
        cerr << "An error occured, see the message below." << endl;
        cerr << e << endl;
        return 2;
    }
    catch (const char* e) {
        cerr << "An error occured, see the message below." << endl;
        cerr << e << endl;
        return 3;
    }
    
    return 0;
}
