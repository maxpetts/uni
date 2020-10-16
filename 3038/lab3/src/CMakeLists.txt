CMAKE_MINIMUM_REQUIRED (VERSION 3.10)

# set the project name
PROJECT (lab3 VERSION 1.0)

# add the executable
ADD_EXECUTABLE (lab3-1-cxx lab3-1.cxx)
ADD_EXECUTABLE (lab3-2-cxx lab3-2.cxx)
ADD_EXECUTABLE (lab3-3-cxx lab3-3.cxx)
ADD_EXECUTABLE (lab3-4-cxx lab3-4.cxx)
ADD_EXECUTABLE (lab3-5-cxx lab3-5.cxx)
ADD_EXECUTABLE (celsius2fahrenheit celsius2fahrenheit.cxx)

enable_testing()

add_test(NAME no_args COMMAND celsius2fahrenheit)
add_test(NAME 1_arg COMMAND celsius2fahrenheit 5)
add_test(NAME float_arg COMMAND celsius2fahrenheit 5.5)
add_test(NAME 2_args COMMAND celsius2fahrenheit 5 9)
add_test(NAME float_2_args COMMAND celsius2fahrenheit 5.5 9.9)
set_tests_properties(2_args float_2_args PROPERTIES WILL_FAIL TRUE)

add_test(NAME correct COMMAND celsius2fahrenheit 20)
set_tests_properties(correct PROPERTIES PASS_REGULAR_EXPRESSION "20 degrees Celcius is the same as 68 degrees Fahrenheit.")

add_test(NAME correct2 COMMAND celsius2fahrenheit 25)
set_tests_properties(correct2 PROPERTIES PASS_REGULAR_EXPRESSION "25 degrees Celcius is the same as 77 degrees Fahrenheit.")

add_test(NAME correct3 COMMAND celsius2fahrenheit 30.8)
set_tests_properties(correct3 PROPERTIES PASS_REGULAR_EXPRESSION "30.8 degrees Celcius is the same as 87.44 degrees Fahrenheit.")
