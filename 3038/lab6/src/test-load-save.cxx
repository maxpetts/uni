#include "Image.h"
#include "gtest/gtest.h"

using namespace std;

TEST(LoadSave, LoadPNG) {
    Image inp_img("../tulips.png");
    
    ASSERT_EQ(inp_img.getWidth(), 768);
    ASSERT_EQ(inp_img.getHeight(), 512);
    ASSERT_EQ(inp_img.getWidth() * inp_img.getHeight(), 393216);
    
    ASSERT_NEAR(inp_img.getMean(), 101.540, 1);
    ASSERT_NEAR(inp_img.getStdDev(), 59.634, 1);
    ASSERT_NEAR(inp_img.getMinValue(), 3, 1);
    ASSERT_NEAR(inp_img.getMaxValue(), 242, 1);
}

TEST(LoadSave, SaveJPG) {
    Image inp_img("../tulips.png");
    inp_img.save("../output.jpg");
    
    Image out_img("../output.jpg");
    
    ASSERT_EQ(out_img.getWidth(), 768);
    ASSERT_EQ(out_img.getHeight(), 512);
    ASSERT_EQ(out_img.getWidth() * out_img.getHeight(), 393216);
    
    ASSERT_NEAR(out_img.getMean(), 101.540, 2);
    ASSERT_NEAR(out_img.getStdDev(), 59.634, 2);
    ASSERT_NEAR(out_img.getMinValue(), 3, 2);
    ASSERT_NEAR(out_img.getMaxValue(), 242, 2);
}

TEST(LoadSave, LoadSaveASCII) {
    Image inp_img({1, 2, 3, 4, 5, 6}, 3, 2);
    
    inp_img.save("output.txt");
    
    Image out_img("output.txt");
    
    // Check the image size
    ASSERT_EQ(out_img.getWidth(), 3);
    ASSERT_EQ(out_img.getHeight(), 2);
    ASSERT_EQ(out_img.getWidth() * out_img.getHeight(), 6);
    
    // Check the image stats
    ASSERT_NEAR(out_img.getMean(), (1 + 2 + 3 + 4 + 5 + 6) / 6.0, 1.0 / 6.0);
    ASSERT_NEAR(out_img.getMinValue(), 1, 1.0 / 6.0);
    ASSERT_NEAR(out_img.getMaxValue(), 6, 1.0 / 6.0);
    
    // Check all the pixel values
    ASSERT_NEAR(out_img(0, 0), 1, 1.0 / 6.0);
    ASSERT_NEAR(out_img(1, 0), 2, 1.0 / 6.0);
    ASSERT_NEAR(out_img(2, 0), 3, 1.0 / 6.0);
    ASSERT_NEAR(out_img(0, 1), 4, 1.0 / 6.0);
    ASSERT_NEAR(out_img(1, 1), 5, 1.0 / 6.0);
    ASSERT_NEAR(out_img(2, 1), 6, 1.0 / 6.0);
}
