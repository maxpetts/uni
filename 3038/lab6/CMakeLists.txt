CMAKE_MINIMUM_REQUIRED (VERSION 3.10)

PROJECT (ICP3038-img-class VERSION 0.2)

# Turn on C++ 11 (required for CLang on Apple computers)
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)

INCLUDE(cmake/External_GTest.cmake)

enable_testing()


# Find OpenCV

# Add where OpenCV might be installed (look in D: first, then in C:)
IF (WIN32)
    SET (CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "D:/opencv/build")
    SET (CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "C:/opencv/build")
ENDIF (WIN32)

FIND_PACKAGE(OpenCV REQUIRED)
IF(OpenCV_FOUND)
    add_definitions(-DHAS_OPENCV)

    # If windows is used, copy the dlls into the project directory
    SET (CV_VERSION_STRING ${OpenCV_VERSION_MAJOR}${OpenCV_VERSION_MINOR}${OpenCV_VERSION_PATCH})
    IF (WIN32)
        IF ( ${OpenCV_VERSION_MAJOR} EQUAL 4)
            IF (EXISTS "${OpenCV_DIR}/x64/vc15/bin/opencv_videoio_ffmpeg${CV_VERSION_STRING}_64.dll")
                FILE (COPY        "${OpenCV_DIR}/x64/vc15/bin/opencv_videoio_ffmpeg${CV_VERSION_STRING}_64.dll"
                      DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/")
            ELSE ()
    			MESSAGE (WARNING "opencv_videoio_ffmpeg${CV_VERSION_STRING}_64.dll is not in ${OpenCV_DIR}/x64/vc15/bin/, you have to make sure is it in the PATH or to copy it manually in your project binary directory")
            ENDIF ()
    	ELSE ()
            IF (EXISTS "${OpenCV_DIR}/x64/vc15/bin/opencv_ffmpeg${CV_VERSION_STRING}_64.dll")
                FILE (COPY        "${OpenCV_DIR}/x64/vc15/bin/opencv_ffmpeg${CV_VERSION_STRING}_64.dll"
                      DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/")
            ELSE ()
    			MESSAGE (WARNING "opencv_ffmpeg${CV_VERSION_STRING}_64.dll is not in ${OpenCV_DIR}/x64/vc15/bin/, you have to make sure is it in the PATH or to copy it manually in your project binary directory")
            ENDIF ()
    	ENDIF ()

        IF (EXISTS "${OpenCV_DIR}/x64/vc15/bin/opencv_world${CV_VERSION_STRING}.dll")
            FILE (COPY        "${OpenCV_DIR}/x64/vc15/bin/opencv_world${CV_VERSION_STRING}.dll"
                  DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/")
        ELSE ()
    	    MESSAGE (WARNING "opencv_world${CV_VERSION_STRING}.dll is not in ${OpenCV_DIR}/x64/vc15/bin/, you have to make sure is it in the PATH or to copy it manually in your project binary directory")
        ENDIF ()

        IF (EXISTS "${OpenCV_DIR}/x64/vc15/bin/opencv_world${CV_VERSION_STRING}d.dll")
            FILE (COPY        "${OpenCV_DIR}/x64/vc15/bin/opencv_world${CV_VERSION_STRING}d.dll"
                  DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/")
        ELSE ()
    	    MESSAGE (WARNING "opencv_world${CV_VERSION_STRING}d.dll is not in ${OpenCV_DIR}/x64/vc15/bin/, you have to make sure is it in the PATH or to copy it manually in your project binary directory")
        ENDIF ()
    ENDIF (WIN32)    
ELSE(OpenCV_FOUND)
    MESSAGE(WARNING "OpenCV not found.")
ENDIF(OpenCV_FOUND)


# The documentation build is an option. Set it to ON by default
option(BUILD_DOC "Build documentation" ON)

# Check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)

    # Set some variables
    SET (PROJECT_NAME ICP3038-img-class)
    SET (PROJECT_DESCRIPTION "An Image class used in ICP3038 at Bangor University")

    # Set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # Configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    # Add a custom target
    add_custom_target( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
    message(WARNING "Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)


ADD_EXECUTABLE (Test-Constructors src/test-constructors.cxx src/Image.cxx include/Image.h)
ADD_EXECUTABLE (Test-Operators src/test-operators.cxx src/Image.cxx include/Image.h)
ADD_EXECUTABLE (Test-Load-Save src/test-load-save.cxx src/Image.cxx include/Image.h)
ADD_EXECUTABLE (Contrast-Enhance src/contrast-enhance.cxx src/Image.cxx include/Image.h)
ADD_EXECUTABLE (Negative src/negative.cxx src/Image.cxx include/Image.h)
ADD_EXECUTABLE (Blending src/blending.cxx src/Image.cxx include/Image.h)
ADD_EXECUTABLE (Display src/display.cxx src/Image.cxx include/Image.h)
ADD_EXECUTABLE (Test-ZNCC src/test-zncc.cxx src/Image.cxx include/Image.h)
ADD_EXECUTABLE (Test-RMSE src/test-rmse.cxx src/Image.cxx include/Image.h)
ADD_EXECUTABLE (Gaussian-Filter src/gaussian-filter.cxx src/Image.cxx include/Image.h)
ADD_EXECUTABLE (Test-Gaussian src/test-gaussian.cxx src/Image.cxx include/Image.h)
ADD_EXECUTABLE (Box-Filter src/box-filter.cxx src/Image.cxx include/Image.h)
ADD_EXECUTABLE (Laplacian-Filter src/laplacian-filter.cxx src/Image.cxx include/Image.h)
ADD_EXECUTABLE (Gradient-Magnitude src/gradient-magnitude.cxx src/Image.cxx include/Image.h)
ADD_EXECUTABLE (Sharpen src/sharpen.cxx src/Image.cxx include/Image.h)
ADD_EXECUTABLE (Threshold src/threshold.cxx src/Image.cxx include/Image.h)

TARGET_INCLUDE_DIRECTORIES(Test-Constructors PUBLIC include)
TARGET_INCLUDE_DIRECTORIES(Test-Constructors PUBLIC ${GTEST_INCLUDE_DIRS})
TARGET_INCLUDE_DIRECTORIES(Test-Operators PUBLIC include)
TARGET_INCLUDE_DIRECTORIES(Test-Operators PUBLIC ${OpenCV_INCLUDE_DIRS} ${GTEST_INCLUDE_DIRS})
TARGET_INCLUDE_DIRECTORIES(Contrast-Enhance PUBLIC include)
TARGET_INCLUDE_DIRECTORIES(Contrast-Enhance PUBLIC ${OpenCV_INCLUDE_DIRS})
TARGET_INCLUDE_DIRECTORIES(Test-Load-Save PUBLIC include)
TARGET_INCLUDE_DIRECTORIES(Test-Load-Save PUBLIC ${OpenCV_INCLUDE_DIRS} ${GTEST_INCLUDE_DIRS})
TARGET_INCLUDE_DIRECTORIES(Negative PUBLIC include)
TARGET_INCLUDE_DIRECTORIES(Negative PUBLIC ${OpenCV_INCLUDE_DIRS})
TARGET_INCLUDE_DIRECTORIES(Blending PUBLIC include)
TARGET_INCLUDE_DIRECTORIES(Blending PUBLIC ${OpenCV_INCLUDE_DIRS})
TARGET_INCLUDE_DIRECTORIES(Display PUBLIC include)
TARGET_INCLUDE_DIRECTORIES(Display PUBLIC ${OpenCV_INCLUDE_DIRS})
TARGET_INCLUDE_DIRECTORIES(Test-ZNCC PUBLIC include)
TARGET_INCLUDE_DIRECTORIES(Test-ZNCC PUBLIC ${OpenCV_INCLUDE_DIRS} ${GTEST_INCLUDE_DIRS})
TARGET_INCLUDE_DIRECTORIES(Test-RMSE PUBLIC include)
TARGET_INCLUDE_DIRECTORIES(Test-RMSE PUBLIC ${OpenCV_INCLUDE_DIRS} ${GTEST_INCLUDE_DIRS})
TARGET_INCLUDE_DIRECTORIES(Gaussian-Filter PUBLIC include)
TARGET_INCLUDE_DIRECTORIES(Gaussian-Filter PUBLIC ${OpenCV_INCLUDE_DIRS}) 
TARGET_INCLUDE_DIRECTORIES(Test-Gaussian PUBLIC include)
TARGET_INCLUDE_DIRECTORIES(Test-Gaussian PUBLIC ${OpenCV_INCLUDE_DIRS} ${GTEST_INCLUDE_DIRS})
TARGET_INCLUDE_DIRECTORIES(Box-Filter PUBLIC include)
TARGET_INCLUDE_DIRECTORIES(Box-Filter PUBLIC ${OpenCV_INCLUDE_DIRS})
TARGET_INCLUDE_DIRECTORIES(Laplacian-Filter PUBLIC include)
TARGET_INCLUDE_DIRECTORIES(Laplacian-Filter PUBLIC ${OpenCV_INCLUDE_DIRS})
TARGET_INCLUDE_DIRECTORIES(Gradient-Magnitude PUBLIC include)
TARGET_INCLUDE_DIRECTORIES(Gradient-Magnitude PUBLIC ${OPENCV_INCLUDE_DIRS})
TARGET_INCLUDE_DIRECTORIES(Sharpen PUBLIC include)
TARGET_INCLUDE_DIRECTORIES(Sharpen PUBLIC ${OPENCV_INCLUDE_DIRS})
TARGET_INCLUDE_DIRECTORIES(Threshold PUBLIC include)
TARGET_INCLUDE_DIRECTORIES(Threshold PUBLIC ${OPENCV_INCLUDE_DIRS})

# ADD IF OPENCV statement as to not throw error if opencv not installed

TARGET_LINK_DIRECTORIES(Test-Constructors PUBLIC ${GTEST_LIBS_DIR})
TARGET_LINK_LIBRARIES(Test-Constructors ${GTEST_LIBRARIES})
TARGET_LINK_DIRECTORIES(Test-Operators PUBLIC ${GTEST_LIBS_DIR})
TARGET_LINK_LIBRARIES(Test-Operators ${OpenCV_LIBS} ${GTEST_LIBRARIES})
TARGET_LINK_DIRECTORIES(Test-Load-Save PUBLIC ${GTEST_LIBS_DIR})
TARGET_LINK_LIBRARIES(Test-Load-Save ${OpenCV_LIBS} ${GTEST_LIBRARIES} )
TARGET_LINK_LIBRARIES(Contrast-Enhance ${OpenCV_LIBS})
TARGET_LINK_LIBRARIES(Negative ${OpenCV_LIBS})
TARGET_LINK_LIBRARIES(Blending ${OpenCV_LIBS})
TARGET_LINK_LIBRARIES(Display ${OpenCV_LIBS})
TARGET_LINK_DIRECTORIES(Test-ZNCC PUBLIC ${GTEST_LIBS_DIR})
TARGET_LINK_LIBRARIES(Test-ZNCC ${OpenCV_LIBS} ${GTEST_LIBRARIES})
TARGET_LINK_DIRECTORIES(Test-RMSE PUBLIC ${GTEST_LIBS_DIR})
TARGET_LINK_LIBRARIES(Test-RMSE ${OpenCV_LIBS} ${GTEST_LIBRARIES})
TARGET_LINK_LIBRARIES(Gaussian-Filter ${OpenCV_LIBS})
TARGET_LINK_DIRECTORIES(Test-Gaussian PUBLIC ${GTEST_LIBS_DIR})
TARGET_LINK_LIBRARIES(Test-Gaussian ${OpenCV_LIBS} ${GTEST_LIBRARIES})
TARGET_LINK_LIBRARIES(Box-Filter ${OpenCV_LIBS})
TARGET_LINK_LIBRARIES(Laplacian-Filter ${OpenCV_LIBS})
TARGET_LINK_LIBRARIES(Gradient-Magnitude ${OpenCV_LIBS})
TARGET_LINK_LIBRARIES(Sharpen ${OpenCV_LIBS})
TARGET_LINK_LIBRARIES(Threshold ${OpenCV_LIBS})

ADD_DEPENDENCIES(Test-Constructors googletest)
ADD_DEPENDENCIES(Test-Operators googletest)
ADD_DEPENDENCIES(Test-Load-Save googletest)
ADD_DEPENDENCIES(Test-ZNCC googletest)
ADD_DEPENDENCIES(Test-RMSE googletest)
ADD_DEPENDENCIES(Test-Gaussian googletest)

add_test (Constructors Test-Constructors)
add_test (Operators Test-Operators)
add_test (LoadSave Test-Load-Save)
add_test (ZNCC Test-ZNCC)
add_test (RMSE Test-RMSE)
add_test (RMSE Test-RMSE)
add_test (Gaussian Test-Gaussian)

FILE(COPY ${CMAKE_CURRENT_SOURCE_DIR}/imgs/tulips.png DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

