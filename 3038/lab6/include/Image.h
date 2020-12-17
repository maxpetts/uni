#ifndef __Image_h
#define __Image_h

#include <vector>
#include <iostream>

using namespace std;

class Image;
ostream& operator<<(ostream& anOutStream, const Image& anImage);
Image operator*(float aValue, const Image&);
Image operator+(float aValue, const Image&);
Image operator-(float aValue, const Image&);
Image blending(float alpha, const Image& img1, const Image& img2);

class Image {
    
public:
    /// Default constuctor: Create empty image
    Image();
    
    /// Default destructor: empty array etc etc
   // ~Image();
    
    /// Copy constructor: Copy an existing image.
    /**
     * @param anImage: The image to copy
     */
    Image(const Image& anImage);
    
    /// Constructor: Copy a 1D array stored within another Image instance into this image
    /**
     * @param anImage: The pixel data
     * @param aWidth: The image
     * @param aHeight: The image height
     */
    Image(const float* anImage, size_t aWidth, size_t aHeight);
    
    /// Constructor: Copy a 1D array to the image
    /**
     * @param anImage: The pixel data
     * @param aWidth: The image width
     * @param aHeight: The image height
     */
    Image(const vector<float>& anImage, size_t aWidth, size_t aHeight);
    
    /// Constructor: Copy an image consisting of one value
    /**
     * @param aConstant: The default pixel value
     * @param aWidth: The image width
     * @param aHeight: The image height
     */
    Image(float aConstant, size_t aWidth, size_t aHeight);
    
    /// Constructor: Load a file from the disk
    /**
     * @param aFilename: The name of the file to load
     */
    Image(const char* aFilename);
    
    /// Constructor: Load a file from the disk
    /**
     * @param aFilename: The name of the file to load
     */
    Image(const string& aFilename);
    
    /// Constructor: Load a file from the disk
    /**
     * @param aFilename: The name of the file to load
     */
    void load(const char* aFilename);

    /// Constructor: Load a file from the disk
    /**
     * @param aFilename: The name of the file to load
     */
    void load(const std::string& aFilename);
    
    /// Accessor on m_width
    /**
     * @return the image width in number of pixels
     */
    size_t getWidth() const;
    
    /// Accessor on m_height
    /**
     * @return the image height in number of pixels
     */
    size_t getHeight() const;
    
    /// Accessor on raw pixel data
    /**
     * @return the pointer on the raw pixel data
     */
    const float* getPixelPointer() const;
    /**
     * @return the pointer on the raw pixel data
     */
    float* getPixelPointer();
    
    /// Accessor on a given pixel
    /**
     * @param col: coordinate of the pixel along the horizontal axis
     * @param row: coordinate of the pixel along the vertical axis
     * @return the corresponding pixel value
    */
    const float& operator()(size_t col, size_t row) const;
    
    /// Accessor on a given pixel
    /**
     * @param col: coordinate of the pixel along the horizontal axis
     * @param row: coordinate of the pixel along the vertical axis
     * @return the corresponding pixel value
    */
    float& operator()(size_t col, size_t row);
    
    /// Assignment operator
    /**
     * @param anInputImage: The image to copy
     * @return the new image
    */
    Image& operator=(const Image& anInputImage);


    /// Assignment operator
    /**
     * @param aFileName: The name of the file to load
     * @return the new image
    */
    Image& operator=(const char* aFileName);


    /// Assignment operator
    /**
     * @param aFileName: The name of the file to load
     * @return the new image
    */
    Image& operator=(const std::string& aFileName);
    
    /// Add a constant value to all the pixels of an image
    /**
     * @param aValue: the value to add
     * @return the new image
    */
    Image operator+(float aValue) const;
    
    /// Subtract a constant value to all the pixels of an image
    /**
     * @param aValue: the value to subtract
     * @return the new image
    */
    Image operator-(float aValue) const;
    
    /// Multiply all the pixels of an image with a constant value
    /**
     * @param aValue: the value to multiply
     * @return the new image
    */
    Image operator*(float aValue) const;
    
    /// Divide all the pixels of an image by a constant value
    /**
     * @param aValue: the divisor
     * @return the new image
    */
    Image operator/(float aValue) const;
    
    /// Compute the negative image
    /**
     * @return the negative image
    */
    Image operator!();
    
    /// Add a value onto each pixel value within the image. Equivelant to image_1 = image_1 + value
    /**
     * @param aValue: the value to add to the image
     * @return the new image
     */
    Image& operator+=(float aValue);
    
    /// Subtract a value onto each pixel value within the image. Equivelant to image_1 = image_1 - value
    /**
     * @param aValue: the value to subtract from the image
     * @return the new image
     */
    Image& operator-=(float aValue);
    
    /// Multiply a value by each pixel value within the image. Equivelant to image_1 = image_1 * value
    /**
     * @param aValue: the value to multiply the image by
     * @return the new image
     */
    Image& operator*=(float aValue);
    
    /// Divide each pixel within the image by a value. Equivelant to image_1 = image_1 / value
    /**
     * @param aValue: the value to divide the image by
     * @return the new image
     */
    Image& operator/=(float aValue);
    
    /// Image by Image pixel-wise addition.
    /**
     * @param img: the image to add to the image
     * @return the new image
     */
    Image operator+(const Image& img) const;
    
    /// Image by Image pixel-wise subtraction.
    /**
     * @param img: the image to subtract from the image
     * @return the new image
     */
    Image operator-(const Image& img) const;
    
    /// Image by Image pixel-wise multiplication.
    /**
     * @param img: the image to multiply the image by
     * @return the new image
     */
    Image operator*(const Image& img) const;
    
    /// Image by Image pixel-wise division.
    /**
     * @param img: the image to divide the image by
     * @return the new image
     */
    Image operator/(const Image& img) const;
    
    /// Image by Image pixel-wise assigning and addition.
    /**
     * @param img: the image to add to the image
     * @return the new image
     */
    Image& operator+=(const Image& img);
    
    /// Image by Image pixel-wise assigning and subtraction.
    /**
     * @param img: the image to subtract from the image
     * @return the new image
     */
    Image& operator-=(const Image& img);
    
    /// Image by Image pixel-wise assigning and multiplication.
    /**
     * @param img: the image to multiply the image by
     * @return the new image
     */
    Image& operator*=(const Image& img);
    
    /// Image by Image pixel-wise assigning and division.
    /**
     * @param img: the image to divide the image by
     * @return the new image
     */
    Image& operator/=(const Image& img);
    
    /// Normalise an image.
    /**
     * @return the new, normalised image
     */
    Image normalise();
    
    /// Get the minimum value of the image.
    /**
     * @return the smallest floating point number in the image
     */
    float getMinValue();
    
    /// Get the maximum value of the image.
    /**
     * @return the largest floating point number in the image
     */
    float getMaxValue();
    
    /// Get the mean value of the image.
    /**
     * @return the average of all pixels of the image as a floating point number
     */
    float getMean();
    
    /// Get the standard deviation of the image.
    /**
     * @return the standard deviation of the image as a floating point number
     */
    float getStdDev();
    
    /// Get the Zero Mean Normalised-Cross Correlation
    /**
     * @param anImage: the image to compare to
    */
    double getRMSE(const Image& anImage) const;
    
    /// Get the Zero Mean Normalised-Cross Correlation
    /**
     * @param anImage: the image to compare to
    */
    double getZNCC(const Image& anImage) const;
    
    /// Save the image with the specified file name.
    /**
     * @param aFileName: The name to save the image by
     */
    void save(const char* aFileName);
    
    /// Save the image with the specified file name.
    /**
     * @param aFileName: The name to save the image by
     */
    void save(const string& aFileName);
    
    /// Display the image
    /**
     * @param aWindowName: Allows the window to have a custom name. (default value: "Display Window")
     * @param aNormaliseFlag: a flag used to optionally normalise the data first,
     *                        then display (default value: true)
    */
    void display(string aWindowName = "Display Window", bool aNormaliseFlag = true) const;
    
    /// Convolute the image by a given kernel.
    /**
     * @param aKernel: The kernel to 'slide' over the image
     * @return The filtered image.
     */
    Image conv2d(const Image& aKernel) const;
    
    /// Blur the image using convolution
    /**
     * @return a new blurred image
     */
    Image gaussianFilter() const;
    
    /// Removes the amount of variation throughout an image
    /**
     * @return The newly filtered image
     */
    Image meanFilter() const;
    
    /// Removes the amount of variation throughout an image - same as meanFilter()
    /**
     * @return The newly filtered image
     */
    Image averageFilter() const;
    
    /// Removes the amount of variation throughout an image - same as meanFilter()
    /**
     * @return The newly filtered image
     */
    Image boxFilter() const;
    
    /// Highlights regions of rapid intensity change - can be used for edge detection
    /**
     * @return The image with edges highlighted
     */
    Image laplacianFilter() const;
    
    /// Pixel-wise squaring of an Image
    /**
     * @return The original image muiltiplied by itself
     */
    Image square() const;
    
    /// Pixel-wise square root of an Image
    /**
     * @return The original image with all values square rootes
     */
    Image squareRoot() const;

    /// Edge detection using the Sobel operator
    /**
     * @return The gradient magnitude of the original image
     */
    Image gradientMagnitude() const;
    
    /// Sharpens the image
    /**
     * @param alpha: The opacity level of the overlayed sharpened image
     * @return The sharpened image
     */
    Image sharpen(double alpha);
    
    /// Clamp an image to two values
    /**
     * @param aLowerThreshold: The lowest value to set the pixel value by
     * @param anUpperThreshold: The upper value to set the pixel values by
     * @return The clamped image
     */
    Image clamp(float aLowerThreshold, float anUpperThreshold) const;
    
    /// Produce a binary image using a threshold value
    /**
     * @param aThreshold: The number to split the image by
     * @return The binary image
     */
    Image threshold(float aThreshold) const;
    
    /// Produce a binary image using two threshold values
    /**
     * @param aLowerThreshold: The lowest value to set the pixel value by
     * @param anUpperThreshold: The upper value to set the pixel values by
     * @return The binary image
     */
    Image threshold(float aLowerThreshold, float anUpperThreshold) const;
        
private:
    void updateStats();

    vector<float> m_pixel_data; //< The pixel data in greyscale as a 1D array (here STL vector)
    size_t m_width; //< The number of columns
    size_t m_height; //< The number of rows
    float m_min_pixel_value; //< The smallest pixel value
    float m_max_pixel_value; //< The largest pixel value
    float m_average_pixel_value; //< The average pixel value
    float m_stddev_pixel_value; //< The standard deviation of the pixel values
    
    bool m_stats_up_to_date; //< True if m_min_pixel_value, m_max_pixel_value, m_average_pixel_value and m_stddev_pixel_value are up-to-date, false otherwise
};

#endif // __Image_h
