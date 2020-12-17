#include "Image.h"
#include "gtest/gtest.h"

using namespace std;

TEST(Constructors, DefaultConstructor) {
    Image def_const;
    
    ASSERT_EQ(def_const.getWidth(), 0);
    ASSERT_EQ(def_const.getHeight(), 0);
    EXPECT_TRUE(def_const.getPixelPointer() == NULL);
}

TEST(Constructors, CArrayConstructor) {
    float c_arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9 };
    Image c_image(c_arr, 3, 2);

    ASSERT_EQ(c_image.getWidth(), 3);
    ASSERT_EQ(c_image.getHeight(), 2);
    
    size_t k = 0;
    for (size_t i = 0; i < c_image.getHeight(); ++i) {
        for (size_t j = 0; j < c_image.getWidth(); ++j, ++k) {
            ASSERT_EQ(c_image(j, i), c_arr[k]);
        }
    }
}

TEST(Constructors, CxxArrayConstructor) {
    vector<float> cxx_arr = {9, 8, 6, 5, 2, 1};
    Image cxx_image(cxx_arr, 3, 2);

    ASSERT_EQ(cxx_image.getWidth(), 3);
    ASSERT_EQ(cxx_image.getHeight(), 2);
    
    size_t k = 0;
    for (size_t i = 0; i < cxx_image.getHeight(); ++i) {
        for (size_t j = 0; j < cxx_image.getWidth(); ++j, ++k) {
            ASSERT_EQ(cxx_image(j, i), cxx_arr[k]);
        }
    }
}

TEST(Constructors, ConstantConstructor) {
    const float constant = 5.5;
    Image const_image(constant, 3, 5);

    ASSERT_EQ(const_image.getHeight(), 5);
    ASSERT_EQ(const_image.getWidth(), 3);
    
    for (size_t i = 0; i < const_image.getHeight(); ++i) {
        for (size_t j = 0; j < const_image.getWidth(); ++j) {
            ASSERT_EQ(const_image(j, i), constant);
        }
    }
}
