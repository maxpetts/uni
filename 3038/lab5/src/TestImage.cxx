#include "Image.h"

using namespace std;

int main() {
	// default constructor
	Image def_const;
    
    // construct from c & c++ array
    float c_arr[] = {1, 2, 5, 6, 8, 9};
    vector<float> cxx_arr = {9, 8, 6, 5, 2, 1};
    
    Image c_image(c_arr, 3, 2);
    Image cxx_image(cxx_arr, 2, 3);
    
    // construct from constant
    Image const_image(5.5, 3, 3);
    
    // construct from copy
    Image copy_image = const_image;

	// constructors from string - load from file
	const char* c_name = "file.jpg";
	string cxx_name = c_name;
    
    Image c_fileName(c_name);
    Image cxx_fileName(cxx_name);
    
    cout << def_const.getWidth() << " " << def_const.getHeight() << " " << def_const.getPixelPointer() << endl << endl;
    cout << c_fileName << endl << endl;
    cout << cxx_fileName << endl << endl;
    cout << c_image << endl << endl;
    cout << cxx_image << endl << endl;
    cout << const_image << endl;
    cout << copy_image << endl;
}
