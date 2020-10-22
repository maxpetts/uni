CMAKE_MINIMUM_REQUIRED (VERSION 3.10)

PROJECT (lab4 VERSION 1.0)

ADD_EXECUTABLE (TestInteger src/TestInteger.cxx src/Integer.cxx)
ADD_EXECUTABLE (TestStringInv src/TestStringInverter.cxx src/StringInverter.cxx)

INCLUDE_DIRECTORIES (include) # Cmake 2.x
TARGET_INCLUDE_DIRECTORIES(TestInteger PRIVATE ../include)
