#include "Image.h"
#include "gtest/gtest.h"
#include <iostream>

using namespace std;

Image i1({1, 1, 1, 1, 1, 1}, 2, 3);
Image i2({4, 3, 2, 1, 0, -1}, 2, 3);

TEST(RMSE, SameImage) {
    // i1.getRMSE(i1); <-- must be close to 0
    ASSERT_NEAR(i1.getRMSE(i1), 0.0, 1e-6);
    i1.save("fiji-01.txt");
}

TEST(RMSE, ImageByThree) {
    // i1.getRMSE(i1 * 3); must be close to sqrt(1/6 * 6 * (1 - 3)^2), i.e. 2
    ASSERT_NEAR(i1.getRMSE(i1 * 3), 2.0, 1e-5);
}

TEST(RMSE, ImageByNine) {
    // i1.getRMSE(i1 * 9); must be close to sqrt(1/6 * 6 * (1 - 9)^2), i.e. 8
    ASSERT_NEAR(i1.getRMSE(i1 * 9), 8.0, 1e-5);
}

TEST(RMSE, InverseImage) {
    // Greater than 0 as not the same images
    ASSERT_NEAR(i1.getRMSE(!i1), 2, 1e-5);
}

TEST(RMSE, DiffImages) {
    // Greater than 0 as not the same images
    ASSERT_GT(i1.getRMSE(i2), 0);
}

TEST(RMSE, DiffImagesByThree) {
    // Greater than 0 as not the same images
    ASSERT_GT(i1.getRMSE(i2 * 3), 0);
}
