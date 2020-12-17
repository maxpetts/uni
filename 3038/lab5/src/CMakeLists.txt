CMAKE_MINIMUM_REQUIRED (VERSION 3.10)

PROJECT (lab5 VERSION 1.0)

# Turn on C++ 11 (required for CLang on Apple computers)
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)

ADD_EXECUTABLE (Image Image.cxx ../include/Image.h)
ADD_EXECUTABLE (Test-Constructors TestImage.cxx Image.cxx ../include/Image.h)

INCLUDE_DIRECTORIES (../include) # Cmake 2.x
TARGET_INCLUDE_DIRECTORIES(Image PRIVATE ../include)
TARGET_INCLUDE_DIRECTORIES(Test-Constructors PRIVATE ../include)
