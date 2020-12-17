#include "Image.h"
#include "gtest/gtest.h"
#include <iostream>

using namespace std;

Image i1({1, 2, 3, 4, 5, 6}, 2, 3);
Image i2(!i1); // Negative of I1
Image i3({6, 6, 6, 0, 0, 0}, 2, 3); // A two-tone image

TEST(ZNCC, SameImage) {
    // Same image
    // I1.getZNCC(I1); <-- must be close to 1
    ASSERT_NEAR(i1.getZNCC(i1), 1.0, 1e-5);
}

TEST(ZNCC, InverseImage) {
    ASSERT_NEAR(i1.getZNCC(i2), -1.0, 1e-5);
}

TEST(ZNCC, Arith_i1) {
    // must be close to 1
    ASSERT_NEAR(i1.getZNCC(10. + 4. * i1), 1.0, 1e-5);
}

TEST(ZNCC, Arith_i2) {
    // must be close to -1
    ASSERT_NEAR(i1.getZNCC(10. + 4. * i2), -1.0, 1e-6);
}

TEST(ZNCC, DiffImages) {
    // must be between -1 and 1
    double value1 = i1.getZNCC(i3);
    ASSERT_GT(value1, -1.0);
    ASSERT_LT(value1, 1.0);
}

TEST(ZNCC, ArithDiffImages) {
    double value1 = i1.getZNCC(10. + 4. * i3);
    ASSERT_GT(value1, -1.0);
    ASSERT_LT(value1, 1.0);
}
