CMAKE_MINIMUM_REQUIRED (VERSION 3.10)

PROJECT (lab4 VERSION 1.0)

ADD_EXECUTABLE (TestInteger TestInteger.cxx Integer.cxx)
ADD_EXECUTABLE (TestStringInv TestStringInverter.cxx StringInverter.cxx)

INCLUDE_DIRECTORIES (../include) # Cmake 2.x
TARGET_INCLUDE_DIRECTORIES(TestInteger PRIVATE ../include)
