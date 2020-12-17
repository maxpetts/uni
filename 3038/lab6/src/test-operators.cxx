//
//  TestOperators.cpp
//  googletest-dow
//
//  Created by mp on 24/11/2020.
//

#include <stdio.h>
#include "Image.h"
#include "gtest/gtest.h"

Image input_image({0, 1, 2, 3, 4, 5, 6, 7}, 4, 2);

TEST(Operators, ImageMultiply) {

    Image image_product = 2 * input_image;
    ASSERT_EQ(image_product.getWidth(), input_image.getWidth());
    ASSERT_EQ(image_product.getHeight(), input_image.getHeight());

    size_t k = 0;
    
    for (size_t j = 0; j < image_product.getHeight(); ++j) {
        for (size_t i = 0; i < image_product.getWidth(); ++i, ++k) {
            ASSERT_NEAR(image_product(i, j), k * 2, 1e-6);
        }
    }
}

TEST(Operators, ImageDivision) {
    Image image_div = input_image / 2;
    
    ASSERT_EQ(image_div.getWidth(), input_image.getWidth());
    ASSERT_EQ(image_div.getHeight(), input_image.getHeight());
    
    float k = 0;
    
    for (size_t j = 0; j < image_div.getHeight(); ++j) {
        for (size_t i = 0; i < image_div.getWidth(); ++i, ++k) {
            ASSERT_NEAR(image_div(i, j), k / 2, 1e-6);
        }
    }
}


TEST(Operators, ImageAddition) {
    Image image_sum = 2 + input_image;
    ASSERT_EQ(image_sum.getWidth(), input_image.getWidth());
    ASSERT_EQ(image_sum.getHeight(), input_image.getHeight());
    
    size_t k = 0;
    
    for (size_t j = 0; j < image_sum.getHeight(); ++j) {
        for (size_t i = 0; i < image_sum.getWidth(); ++i, ++k) {
            ASSERT_NEAR(image_sum(i, j), k + 2, 1e-6);
        }
    }
}

TEST(Operators, ImageSubtraction) {
    Image image_sub = input_image - 2;
    ASSERT_EQ(image_sub.getWidth(), input_image.getWidth());
    ASSERT_EQ(image_sub.getHeight(), input_image.getHeight());
    
    int k = 0;
    
    for (size_t j = 0; j < image_sub.getHeight(); ++j) {
        for (size_t i = 0; i < image_sub.getWidth(); ++i, ++k) {
            ASSERT_NEAR(image_sub(i, j), k - 2, 1e-6);
        }
    }
}

TEST(Operators, ImageNegative) {
    Image image_negative = !input_image;
    
    ASSERT_EQ(image_negative.getWidth(), input_image.getWidth());
    ASSERT_EQ(image_negative.getHeight(), input_image.getHeight());
    
    int k = 0;
    
    for (size_t j = 0; j < image_negative.getHeight(); ++j) {
        for (size_t i = 0; i < image_negative.getWidth(); ++i, ++k) {
            ASSERT_NEAR(image_negative(i, j), k * -1, 1e-6);
        }
    }
}
