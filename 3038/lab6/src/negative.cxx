#include <iostream>
#include <exception>

#include "Image.h"

using namespace std;

int main(int argc, char** argv)
{
  try
  {
    Image input(argv[1]);
    (!input).save(argv[2]);
  }
  catch (const exception& e)
  {
    cerr << "An error occured, see the message below." << endl;
    cerr << e.what() << endl;
    return 1;
  }
  catch (const string& e)
  {
    cerr << "An error occured, see the message below." << endl;
    cerr << e << endl;
    return 2;
  }
  catch (const char* e)
  {
    cerr << "An error occured, see the message below." << endl;
    cerr << e << endl;
    return 3;
  }

  return 0;
}

