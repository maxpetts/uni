#include "Image.h"
#include "gtest/gtest.h"

using namespace std;

TEST(Gaussian, ImageJComparison) {
    Image inp_img({
        10, 10, 10, 50, 50, 50,
        10, 10, 10, 50, 50, 50,
        10, 10, 10, 50, 50, 50,
        10, 10, 10, 50, 50, 50,
        10, 10, 10, 50, 50, 50,
        10, 10, 10, 50, 50, 50,
        10, 10, 10, 50, 50, 50,
        10, 10, 10, 50, 50, 50,
        10, 10, 10, 50, 50, 50
    }, 6, 9);
    cout << "inp_img: " << endl << inp_img << endl << endl;

    inp_img = inp_img.gaussianFilter();
    cout << "inp_img: " << endl << inp_img << endl << endl;

    Image test_img({
        10, 10, 20, 40, 50, 50,
        10, 10, 20, 40, 50, 50,
        10, 10, 20, 40, 50, 50,
        10, 10, 20, 40, 50, 50,
        10, 10, 20, 40, 50, 50,
        10, 10, 20, 40, 50, 50,
        10, 10, 20, 40, 50, 50,
        10, 10, 20, 40, 50, 50,
        10, 10, 20, 40, 50, 50
    }, 6, 9);
    cout << "test_img: " << endl << test_img << endl << endl;

    for(size_t image_x = 0; image_x < inp_img.getWidth(); ++image_x) {
        for(size_t image_y = 0; image_y < inp_img.getHeight(); ++image_y) {
            ASSERT_NEAR( inp_img(image_x, image_y), test_img(image_x, image_y), 1 );
        }
    }
}

TEST(Gaussian, ZNCCTest) {
    Image before("../tulips.png");
    Image after(before.boxFilter());
    Image comparison("../test-box.png");
    float rmse = after.getRMSE(comparison);
    cout<<rmse<<endl<<endl;
    ASSERT_GT(rmse, 0.0);
}
