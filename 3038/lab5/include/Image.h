#ifndef __Image_h
#define __Image_h

#include <vector>
#include <iostream>

using namespace std;

class Image;
ostream& operator<<(ostream& anOutStream, const Image& anImage);

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
     * @param aFilename: The name of the file to load
     * @return the new image
    */
    Image& operator=(const char* aFileName);


    /// Assignment operator
    /**
     * @param aFilename: The name of the file to load
     * @return the new image
    */
    Image& operator=(const std::string& aFileName);
    
private:
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
