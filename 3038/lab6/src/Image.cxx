#include "Image.h"
#include <sstream>
#include <stdexcept>
#include <algorithm> // For std::min
#include <cstring> // For toupper
#include <fstream> // For ofstream and ifstream
#include <cmath>

#ifdef HAS_OPENCV
#include <opencv2/opencv.hpp>
#endif

// Constructors

Image::Image():
m_pixel_data(),
m_width(0),
m_height(0),
m_min_pixel_value(0),
m_max_pixel_value(0),
m_average_pixel_value(0),
m_stddev_pixel_value(0),
m_stats_up_to_date(true)
{}

Image::Image(const Image& anImage):
m_pixel_data(anImage.m_pixel_data),
m_width(anImage.m_width),
m_height(anImage.m_height),
m_min_pixel_value(anImage.m_min_pixel_value),
m_max_pixel_value(anImage.m_max_pixel_value),
m_average_pixel_value(anImage.m_average_pixel_value),
m_stddev_pixel_value(anImage.m_stddev_pixel_value),
m_stats_up_to_date(anImage.m_stats_up_to_date)
{}

Image::Image(const float* anImage, size_t aWidth, size_t aHeight):
m_pixel_data(anImage, anImage + aWidth * aHeight),
m_width(aWidth),
m_height(aHeight),
m_min_pixel_value(0),
m_max_pixel_value(0),
m_average_pixel_value(0),
m_stddev_pixel_value(0),
m_stats_up_to_date(false)
{}

Image::Image(const vector<float>& anImage, size_t aWidth, size_t aHeight):
m_pixel_data(anImage),
m_width(aWidth),
m_height(aHeight),
m_min_pixel_value(0),
m_max_pixel_value(0),
m_average_pixel_value(0),
m_stddev_pixel_value(0),
m_stats_up_to_date(false)
{}

Image::Image(float aConstant, size_t aWidth, size_t aHeight):
m_pixel_data(aWidth * aHeight, aConstant),
m_width(aWidth),
m_height(aHeight),
m_min_pixel_value(aConstant),
m_max_pixel_value(aConstant),
m_average_pixel_value(aConstant),
m_stddev_pixel_value(0),
m_stats_up_to_date(true)
{}

Image::Image(const char* aFileName):
m_width(0),
m_height(0),
m_min_pixel_value(0),
m_max_pixel_value(0),
m_average_pixel_value(0),
m_stddev_pixel_value(0),
m_stats_up_to_date(true)
//---------------------------
{
    load(aFileName);
}


//-----------------------------------------
Image::Image(const string& aFileName):
//-----------------------------------------
m_width(0),
m_height(0),
m_min_pixel_value(0),
m_max_pixel_value(0),
m_average_pixel_value(0),
m_stddev_pixel_value(0),
m_stats_up_to_date(true)
//-----------------------------------------
{
    load(aFileName);
}

ostream& operator<<(ostream& anOutStream, const Image& anImage) {
    
    for (size_t row = 0; row < anImage.getHeight(); row++) {
        for (size_t col = 0; col < anImage.getWidth(); col++) {
            anOutStream << anImage(col, row);
            
            if (col < anImage.getWidth() - 1) {
                anOutStream << " ";
            }
        }
        
        if (row < anImage.getHeight() - 1) {
            anOutStream << endl;
        }
    }
    
    return anOutStream;
}

const float& Image::operator()(size_t col, size_t row) const {
    if (col < 0 || col >= m_width || row < 0 || row >= m_height) {
        stringstream err_msg;
        err_msg << "ERROR:";
        err_msg << "\tin File:" << __FILE__ << endl;
        err_msg << "\tin Function:" << __FUNCTION__ << endl;
        err_msg << "\tat Line:" << __LINE__ << endl;
        err_msg << "\tMESSAGE: Pixel(" << col << ", " << row << ") does not exist. The image size is: " << m_width << "x" << m_height << endl;
        
        // Throw an exception
        throw out_of_range(err_msg.str());
    }
    
    return m_pixel_data[row * m_width + col];
}

float& Image::operator()(size_t col, size_t row) {
    // Check if the coordinates are valid, if not throw an error
    if (col < 0 || col >= m_width || row < 0 || row >= m_height) {
        // Format a nice error message
        stringstream error_message;
        error_message << "ERROR:" << endl;
        error_message << "\tin File:" << __FILE__ << endl;
        error_message << "\tin Function:" << __FUNCTION__ << endl;
        error_message << "\tat Line:" << __LINE__ << endl;
        error_message << "\tMESSAGE: Pixel(" << col << ", " << row << ") does not exist. The image size is: " << m_width << "x" << m_height << endl;
        
        // Throw an exception
        throw out_of_range(error_message.str());
    }
    
    // To be on the safe side, turn the flag off
    m_stats_up_to_date = false;
    
    return m_pixel_data[row * m_width + col];
}

Image& Image::operator=(const Image& anInputImage) {
    m_pixel_data = anInputImage.m_pixel_data;
    m_width = anInputImage.m_width;
    m_height = anInputImage.m_height;
    m_min_pixel_value = anInputImage.m_min_pixel_value;
    m_max_pixel_value = anInputImage.m_max_pixel_value;
    m_average_pixel_value = anInputImage.m_average_pixel_value;
    m_stddev_pixel_value = anInputImage.m_stddev_pixel_value;
    m_stats_up_to_date = anInputImage.m_stats_up_to_date;
    return *this;
}

Image& Image::operator=(const char* aFileName)
{
    load(aFileName);
    return *this;
}

Image& Image::operator=(const string& aFileName)
{
    load(aFileName);
    return *this;
}

// floating point to image operators. e.g 3 * image_1

Image operator*(float aValue, const Image& anInputImage) {
    Image tmp = anInputImage;
    
    float* p_data = tmp.getPixelPointer();
    size_t pixels = tmp.getWidth() * tmp.getHeight();
    
    for (size_t i = 0; i < pixels; ++i) {
        *p_data++ *= aValue;
    }
    
    return tmp;
}

Image operator+(float aValue, const Image& anInputImage) {
    Image tmp = anInputImage;
    
    float* p_data = tmp.getPixelPointer();
    size_t pixels = tmp.getWidth() * tmp.getHeight();
    
    for (size_t i = 0; i < pixels; ++i) {
        *p_data++ += aValue;
    }
    
    return tmp;
}

Image operator-(float aValue, const Image& anInputImage) {
    // Create a black image of the right size:
    Image temp(0.0, anInputImage.getWidth(), anInputImage.getHeight());
    
    // Create two pointers on the raw pixel data of the input and output respectively:
    const float* p_input_data = anInputImage.getPixelPointer();
    float* p_output_data = temp.getPixelPointer();
    
    // Process all the pixels in a for loop:
    size_t number_of_pixels = temp.getWidth() * temp.getHeight();
    for (size_t i = 0; i < number_of_pixels; ++i)
    {
        *p_output_data++ += aValue - *p_input_data++;
    }
    
    // Return the new image
    return temp;
}

// Modify an image by a floating point number. e.g image_1 + 5.6

Image Image::operator+(float aValue) const {
    Image tmp = *this;
    
    tmp.m_stats_up_to_date = false;
    
    for (size_t i = 0; i < m_width * m_height; ++i)
    {
        tmp.m_pixel_data[i] += aValue;
    }
    
    return tmp;
}

Image Image::operator-(float aValue) const {
    Image tmp = *this;
    
    tmp.m_stats_up_to_date = false;
    
    for (size_t i = 0; i < m_width * m_height; ++i)
    {
        tmp.m_pixel_data[i] -= aValue;
    }
    
    return tmp;
}

Image Image::operator*(float aValue) const {
    Image tmp = *this;
    
    tmp.m_stats_up_to_date = false;
    
    for (size_t i = 0; i < m_width * m_height; ++i)
    {
        tmp.m_pixel_data[i] *= aValue;
    }
    
    return tmp;
}

Image Image::operator/(float aValue) const {
    Image tmp = *this;
    
    tmp.m_stats_up_to_date = false;
    
    for (size_t i = 0; i < m_width * m_height; ++i)
    {
        tmp.m_pixel_data[i] /= aValue;
    }
    
    return tmp;
}

// Image by Image arithmatic. E.G image_1 * image_2

Image Image::operator+(const Image& img) const {
    Image tmp(0.0, min(m_width, img.m_width), min(m_height, img.m_height));
    
    for (size_t j = 0; j < tmp.m_height; ++j)
    {
        for (size_t i = 0; i < tmp.m_width; ++i)
        {
            tmp(i,j) = (*this)(i, j) + img(i, j);
        }
    }
    tmp.m_stats_up_to_date = false;

    return tmp;
}

Image Image::operator-(const Image& img) const {
    Image tmp(0.0, min(m_width, img.m_width), min(m_height, img.m_height));
    
    for (size_t j = 0; j < tmp.m_height; ++j)
    {
        for (size_t i = 0; i < tmp.m_width; ++i)
        {
            tmp(i,j) = (*this)(i, j) - img(i, j);
        }
    }
    tmp.m_stats_up_to_date = false;
    
    return tmp;
}

Image Image::operator*(const Image& img) const {
    Image tmp(0.0, min(m_width, img.m_width), min(m_height, img.m_height));
    
    for (size_t j = 0; j < tmp.m_height; ++j) {
        for (size_t i = 0; i < tmp.m_width; ++i) {
            tmp(i,j) = (*this)(i, j) * img(i, j);
        }
    }
    tmp.m_stats_up_to_date = false;

    return tmp;
}

Image Image::operator/(const Image& img) const {
    Image tmp(0.0, min(m_width, img.m_width), min(m_height, img.m_height));
    
    for (size_t j = 0; j < tmp.m_height; ++j) {
        for (size_t i = 0; i < tmp.m_width; ++i) {
            tmp(i,j) = (*this)(i, j) / img(i, j);
        }
    }
    tmp.m_stats_up_to_date = false;

    return tmp;
}

Image& Image::operator+=(const Image& img) {
    for (size_t j = 0; j < min((*this).m_height, img.getHeight()); ++j) {
        for (size_t i = 0; i < min((*this).m_width, img.getWidth()); ++i) {
            (*this)(i,j) = (*this)(i, j) += img(i, j);
        }
    }
    m_stats_up_to_date = false;

    return *this;
}

Image& Image::operator-=(const Image& img) {
    for (size_t j = 0; j < min((*this).m_height, img.getHeight()); ++j) {
        for (size_t i = 0; i < min((*this).m_width, img.getWidth()); ++i) {
            (*this)(i,j) = (*this)(i, j) -= img(i, j);
        }
    }
    m_stats_up_to_date = false;

    return *this;
}

Image& Image::operator*=(const Image& img) {
    for (size_t j = 0; j < min((*this).m_height, img.getHeight()); ++j) {
        for (size_t i = 0; i < min((*this).m_width, img.getWidth()); ++i) {
            (*this)(i,j) = (*this)(i, j) *= img(i, j);
        }
    }
    m_stats_up_to_date = false;

    return *this;
}

Image& Image::operator/=(const Image& img) {
    for (size_t j = 0; j < min((*this).m_height, img.getHeight()); ++j) {
        for (size_t i = 0; i < min((*this).m_width, img.getWidth()); ++i) {
            (*this)(i,j) = (*this)(i, j) /= img(i, j);
        }
    }
    m_stats_up_to_date = false;
    
    return *this;
}

Image Image::operator!() {
    return m_min_pixel_value + m_max_pixel_value - *this;
}

Image& Image::operator+=(float aValue) {
    *this = *this + aValue;
    m_stats_up_to_date = false;
    
    return *this;
}
Image& Image::operator-=(float aValue) {
    *this = *this - aValue;
    m_stats_up_to_date = false;
    
    return *this;
}
Image& Image::operator*=(float aValue) {
    *this = *this * aValue;
    m_stats_up_to_date = false;
    
    return *this;
}
Image& Image::operator/=(float aValue) {
    *this = *this / aValue;
    m_stats_up_to_date = false;
    
    return *this;
}

Image blending(float alpha, const Image& img1, const Image& img2) {
    return (1.0f - alpha) * img1 + (alpha * img2);
}

Image Image::normalise() {
    return (*this - m_min_pixel_value) / (m_max_pixel_value - m_min_pixel_value);
}

float Image::getMinValue() {
    if (!m_stats_up_to_date) updateStats();
    
    return m_min_pixel_value;
}

float Image::getMaxValue() {
    if (!m_stats_up_to_date) updateStats();
    
    return m_max_pixel_value;
}

float Image::getMean() {
    if (!m_stats_up_to_date) updateStats();
    
    return m_average_pixel_value;
}

float Image::getStdDev() {
    if (!m_stats_up_to_date) updateStats();
    
    return m_stddev_pixel_value;
}

size_t Image::getWidth() const {
    return m_width;
}

size_t Image::getHeight() const {
    return m_height;
}

const float* Image::getPixelPointer() const {
    // There are pixels
    if (m_pixel_data.size() && m_width && m_height)
        return &m_pixel_data[0];
    // There is no pixel
    else
        return 0;
}

float* Image::getPixelPointer() {
    // To be on the safe side, turn the flag off
    m_stats_up_to_date = false;
    
    // There are pixels
    if (m_pixel_data.size() && m_width && m_height)
        return &m_pixel_data[0];
    // There is no pixel
    else
        return 0;
}

void Image::updateStats() {
    // Need to update the stats
    if (!m_stats_up_to_date && m_width * m_height) {
        m_min_pixel_value = m_pixel_data[0];
        m_max_pixel_value = m_pixel_data[0];
        m_average_pixel_value = m_pixel_data[0];
        
        for (size_t i = 1; i < m_width * m_height; ++i) {
            if (m_min_pixel_value > m_pixel_data[i]) m_min_pixel_value = m_pixel_data[i];
            if (m_max_pixel_value < m_pixel_data[i]) m_max_pixel_value = m_pixel_data[i];
            
            m_average_pixel_value += m_pixel_data[i];
        }
        m_average_pixel_value /= m_width * m_height;
        
        m_stddev_pixel_value = 0;
        for (size_t i = 0; i < m_width * m_height; ++i) {
            m_stddev_pixel_value += (m_pixel_data[i] - m_average_pixel_value) * (m_pixel_data[i] - m_average_pixel_value);
        }
        m_stddev_pixel_value /= m_width * m_height;
        m_stddev_pixel_value = sqrt(m_stddev_pixel_value);
        
        m_stats_up_to_date = true;
    }
}

Image Image::square() const {
    Image base_image(*this);
    
    base_image *= base_image;
    
    return base_image;
}

Image Image::squareRoot() const {
    Image base_image(*this);
    
    for (size_t x = 0; x < base_image.m_width; ++x) {
        for (size_t y = 0; y < base_image.m_height; ++y) {
            base_image(x, y) = sqrt(float(base_image(x, y)));
        }
    }
    
    return base_image;
}

void Image::load(const char* aFileName) {
    string tmp_name = aFileName;
    string capital_name;
    
    // Capitalise
    for (int i = 0; i < tmp_name.size(); ++i)
        capital_name += toupper(tmp_name[i]);
    
    if (string(aFileName).size() > 4) {
        // Load a text file
        if(capital_name.substr(capital_name.length() - 4 ) == ".TXT") {
            // Open the file
            ifstream input_file (aFileName);
            
            // The file is not open
            if (!input_file.is_open()) {
                // Format a nice error message
                stringstream error_message;
                error_message << "ERROR:" << endl;
                error_message << "\tin File:" << __FILE__ << endl;
                error_message << "\tin Function:" << __FUNCTION__ << endl;
                error_message << "\tat Line:" << __LINE__ << endl;
                error_message << "\tMESSAGE: Can't open " << aFileName << endl;
                throw runtime_error(error_message.str());
            }
            
            // Empty the image
            m_pixel_data.clear();
            m_width = 0;
            m_height = 0;
            
            // Load the data into a vector
            string line;
            int number_of_rows(0);
            int number_of_columns(0);
            
            // Read evely line
            while (getline(input_file, line)) {
                number_of_columns = 0;
                float intensity;
                stringstream line_parser;
                line_parser << line;
                while (line_parser >> intensity)
                {
                    m_pixel_data.push_back(intensity);
                    ++number_of_columns;
                }
                ++number_of_rows;
            }
            
            // Wrong number of pixels
            if (number_of_rows * number_of_columns != m_pixel_data.size()) {
                // Format a nice error message
                stringstream error_message;
                error_message << "ERROR:" << endl;
                error_message << "\tin File:" << __FILE__ << endl;
                error_message << "\tin Function:" << __FUNCTION__ << endl;
                error_message << "\tat Line:" << __LINE__ << endl;
                error_message << "\tMESSAGE: The file " << aFileName << " is invalid" << endl;
                throw runtime_error(error_message.str());
            }
            
            // Allocate memory for file content
            m_width = number_of_columns;
            m_height = number_of_rows;
            m_stats_up_to_date = false;
        }
        // Use OpenCV
        else {
#ifdef HAS_OPENCV
            // Open the image in greyscale
            cv::Mat temp_image = cv::imread(aFileName, cv::IMREAD_GRAYSCALE);
            
            // The image did not load
            if ( !temp_image.data ) {
                // Format a nice error message
                stringstream error_message;
                error_message << "ERROR:" << endl;
                error_message << "\tin File:" << __FILE__ << endl;
                error_message << "\tin Function:" << __FUNCTION__ << endl;
                error_message << "\tat Line:" << __LINE__ << endl;
                error_message << "\tMESSAGE: Can't open " << aFileName << endl;
                throw runtime_error(error_message.str());
            }
            
            // Save the size of the image
            m_width = temp_image.cols;
            m_height = temp_image.rows;
            m_pixel_data.resize(m_width * m_height);
            
            // Copy the pixel data
            cv::Mat img_float;
            temp_image.convertTo(img_float, CV_32F);
            for (int i = 0; i < m_width * m_height; ++i) {
                int x = i / m_width;
                int y = i % m_width;
                
                m_pixel_data[i] = img_float.at<float>(x, y);
            }
            
            
            // The statistics is not up-to-date
            m_stats_up_to_date = false;
#else
            // Format a nice error message
            stringstream error_message;
            error_message << "ERROR:" << endl;
            error_message << "\tin File:" << __FILE__ << endl;
            error_message << "\tin Function:" << __FUNCTION__ << endl;
            error_message << "\tat Line:" << __LINE__ << endl;
            error_message << "\tMESSAGE: OpenCV not supported" << endl;
            throw runtime_error(error_message.str());
#endif
        }
    }
    // Don't know the file type
    else {
        // Format a nice error message
        stringstream error_message;
        error_message << "ERROR:" << endl;
        error_message << "\tin File:" << __FILE__ << endl;
        error_message << "\tin Function:" << __FUNCTION__ << endl;
        error_message << "\tat Line:" << __LINE__ << endl;
        error_message << "\tMESSAGE: Can't open " << aFileName << ", I don't understand the file type." << endl;
        throw runtime_error(error_message.str());
    }
}

void Image::load(const string& aFileName) {
    load(aFileName.c_str());
}

void Image::save(const char *aFileName) {
    string temp_filename = aFileName;
    string capital_filename;
    
    // Capitalise
    for (int i = 0; i < temp_filename.size(); ++i)
    capital_filename += toupper(temp_filename[i]);
    
    if (string(aFileName).size() > 4) {
        // Load a text file
        if(capital_filename.substr( capital_filename.length() - 4 ) == ".TXT") {
            // Open the file
            ofstream output_file (aFileName);
            
            // The file is not open
            if (!output_file.is_open()) {
                // Format a nice error message
                stringstream error_message;
                error_message << "ERROR:" << endl;
                error_message << "\tin File:" << __FILE__ << endl;
                error_message << "\tin Function:" << __FUNCTION__ << endl;
                error_message << "\tat Line:" << __LINE__ << endl;
                error_message << "\tMESSAGE: Can't open " << aFileName << endl;
                throw runtime_error(error_message.str());
            }
            
            // Write content to file
            float* p_data(getPixelPointer());
            for (unsigned int j(0); j < m_height; ++j) {
                for (unsigned int i(0); i < m_width; ++i) {
                    output_file << *p_data++;
                    
                    // This is not the last pixel of the line
                    if (i < m_width - 1) {
                        output_file << " ";
                    }
                }
                
                // This is not the last line
                if (j < m_height - 1) {
                    output_file << endl;
                }
            }
        }
        // Use OpenCV
        else {
#ifdef HAS_OPENCV
            // Convert the data into an OpenCV Mat instance.
            cv::Mat temp_image(m_height, m_width, CV_32FC1, (float*)getPixelPointer());
            
            // Write the data
            cv::imwrite(aFileName, temp_image);
            
#else
            // Format a nice error message
            stringstream error_message;
            error_message << "ERROR:" << endl;
            error_message << "\tin File:" << __FILE__ << endl;
            error_message << "\tin Function:" << __FUNCTION__ << endl;
            error_message << "\tat Line:" << __LINE__ << endl;
            error_message << "\tMESSAGE: OpenCV not supported" << endl;
            throw runtime_error(error_message.str());
#endif
        }
    }
    // Don't know the file type
    else {
        // Format a nice error message
        stringstream error_message;
        error_message << "ERROR:" << endl;
        error_message << "\tin File:" << __FILE__ << endl;
        error_message << "\tin Function:" << __FUNCTION__ << endl;
        error_message << "\tat Line:" << __LINE__ << endl;
        error_message << "\tMESSAGE: Can't save " << aFileName << ", I don't understand the file type." << endl;
        throw runtime_error(error_message.str());
    }
}

void Image::save(const string& aFileName) {
    save(aFileName.c_str());
}

void Image::display(string windowName, bool aNormaliseFlag) const {
#ifdef HAS_OPENCV
    Image display_image = *this;
    
    if (!display_image.m_stats_up_to_date)
        display_image.updateStats();
    
    // Normalise the image if needed
    if (aNormaliseFlag)
        display_image = display_image.normalise();
    
    // Convert the data into an OpenCV Mat instance.
    cv::Mat cv_image(display_image.getHeight(), display_image.getWidth(), CV_32FC1, (float*) display_image.getPixelPointer());
    
    // Display the image
    imshow(windowName, cv_image);
    
    // Wait for a keystroke in the window
    cv::waitKey(0);
    
#else
    cout << "OpenCV cannot be found" << endl << endl;
#endif // HAS_OPENCV
    
}

double Image::getRMSE(const Image& image_2) const {
    Image image_1 = *this;
    
    if (!image_1.m_stats_up_to_date)
        image_1.updateStats();
    
    // check image size is equivelant, if not throw an error
    if (image_1.m_width == image_2.m_width || image_1.m_height == image_2.m_height) {
        double sse;
        double total_pixels = image_1.m_width * image_1.m_height;
                
        for (size_t y = 0; y < image_1.m_height; ++y) {
            for (size_t x = 0; x < image_1.m_width; ++x) {
                sse += pow((double)image_1(x, y) - (double)image_2(x, y), 2);
            }
        }
        
//        image_1 -= image_2;
//        image_1.square();
//        return sqrt(image_1.getMean());
        
        sse /= total_pixels;
        return sqrt(sse);
        
    } else {
        // throw error
        stringstream error_message;
        error_message << "ERROR:" << endl;
        error_message << "\tin File:" << __FILE__ << endl;
        error_message << "\tin Function:" << __FUNCTION__ << endl;
        error_message << "\tat Line:" << __LINE__ << endl;
        error_message << "\tMESSAGE: The size of the images are different." << endl << endl;
        throw runtime_error(error_message.str());
    }
}

double Image::getZNCC(const Image& anImage) const {
    Image image_1 = *this; // is this more expensive ???
    Image image_2 = anImage;
    
    // Check image size matches, if not throw error
    if (image_1.m_width == image_2.m_width || image_1.m_height == image_2.m_height) {
        size_t total_pixels = image_1.m_width * image_1.m_height;
        double denominator = image_1.m_stddev_pixel_value * image_2.m_stddev_pixel_value;
        double numerator = 0;
        double result = 0;
        
        for (size_t y = 0; y < image_1.m_height; ++y) {
            for (size_t x = 0; x < image_1.m_width; ++x) {
                numerator = (image_1(x, y) - image_1.getMean()) * (image_2(x, y) - image_2.getMean());
                
                result += numerator / denominator;
            }
        }
        
        result /= total_pixels;
        return result;
    } else {
        // throw error
        stringstream error_message;
        error_message << "ERROR:" << endl;
        error_message << "\tin File:" << __FILE__ << endl;
        error_message << "\tin Function:" << __FUNCTION__ << endl;
        error_message << "\tat Line:" << __LINE__ << endl;
        error_message << "\tMESSAGE: The size of the images are different." << endl << endl;
        throw runtime_error(error_message.str());
    }
}

Image Image::conv2d(const Image &aKernel) const {
    // Check kernel size
    if (aKernel.m_width % 2 == 0 || aKernel.m_height % 2 == 0) {
        // throw error
        stringstream error_message;
        error_message << "ERROR:" << endl;
        error_message << "\tin File:" << __FILE__ << endl;
        error_message << "\tin Function:" << __FUNCTION__ << endl;
        error_message << "\tat Line:" << __LINE__ << endl;
        error_message << "\tMESSAGE: Kernel sizes should be odd: 3x3, 5x5, 7x7 etc." << endl << endl;
        throw runtime_error(error_message.str());
    } else {
        Image base_image = *this;
        Image out_image(0.0, base_image.m_width,  base_image.m_height);
        
        for(size_t image_x = 0; image_x < base_image.m_width; ++image_x) {
            for(size_t image_y = 0; image_y < base_image.m_height; ++image_y) {
                float accumulator = 0;
                unsigned check_x = 0;
                unsigned check_y = 0;
                
                for(size_t kernel_x = 0; kernel_x < aKernel.m_width; ++kernel_x) {
                    for(size_t kernel_y = 0; kernel_y < aKernel.m_height; ++kernel_y) {
                        // Check borders
                        check_x = image_x - (aKernel.m_width / 2) + kernel_x;
                        check_y = image_y - (aKernel.m_height / 2) + kernel_y;
                        
                        if (check_x < 0) {
                            check_x = 0;
                        } else if (check_x >= base_image.m_width) {
                            check_x = base_image.m_width - 1;
                        }
                        
                        if (check_y < 0) {
                            check_y = 0;
                        } else if (check_y >= base_image.m_height) {
                            check_y = base_image.m_height - 1;
                        }
                        
                        accumulator += aKernel(kernel_x, kernel_y) * base_image(check_x, check_y);
                    }
                }
                out_image(image_x, image_y) = accumulator;
            }
        }
        
//        // preserve range
//        out_image.clamp(max(out_image.getMinValue(), base_image.getMinValue()), max(out_image.getMaxValue(), base_image.getMaxValue()));
//
//        out_image.normalise() * 255;
        
        return out_image;
    }
}

Image Image::gaussianFilter() const {
    // create kernel
    Image kernel({
        1., 2., 1.,
        2., 4., 2.,
        1., 2., 1.
    }, 3, 3);
    
    // Normalise the kernel so that the sum of its coefficients is 1.
    kernel /= 16.0;
    
    // Filter the image
    return conv2d(kernel);
}

Image Image::meanFilter() const {
    // create kernel
    Image kernel(
                 {
        1., 1., 1.,
        1., 1., 1.,
        1., 1., 1.
    }, 3, 3);
    
    // Normalise the kernel so that the sum of its coefficients is 1.
    kernel /= 9.0;
    
    // Filter the image
    return conv2d(kernel);
}

Image Image::averageFilter() const {
    return meanFilter();
}

Image Image::boxFilter() const {
    return meanFilter();
}

Image Image::laplacianFilter() const {
    // create kernel
    Image kernel({
        1.,  1., 1.,
        1., -8., 1.,
        1.,  1., 1.
    }, 3, 3);
    
    // Filter the image
    return conv2d(kernel);
}

Image Image::gradientMagnitude() const {
    Image kernel_x({
        1., 0., -1.,
        2., 0., -2.,
        1., 0., -1.
    }, 3, 3);
    
    Image kernel_y({
        1., 2., 1.,
        0., 0., 0.,
        -1., -2., -1.
    }, 3, 3);
    
    Image vert_derivative = conv2d(kernel_x);
    Image horiz_derivative = conv2d(kernel_y);
    
    Image sobel_image = vert_derivative.square() + horiz_derivative.square();
    
    return sobel_image.squareRoot();
    
}

Image Image::sharpen(double alpha) {
    Image gaussian_kernel({
        1.,  4.,  7.,  4., 1.,
        4., 16., 26., 16., 4.,
        7., 26., 41., 26., 7.,
        4., 16., 26., 16., 4.,
        1.,  4.,  7.,  4., 1.
    }, 5, 5);
    
    gaussian_kernel /= 273.;
    
    // Create an image of the details
    Image blur = conv2d(gaussian_kernel);
    Image details = *this - blur;
    
    // Add details back into original
    Image output = *this + alpha * details;
    
    // Preserve dynamic range
    return output.clamp(getMinValue(), getMaxValue());
}

Image Image::clamp(float aLowerThreshold, float anUpperThreshold) const {
    Image base_image(*this);
    
    for (size_t x = 0; x < base_image.m_width; ++x) {
        for (size_t y = 0; y < base_image.m_height; ++y) {
            if (base_image(x, y) < aLowerThreshold)
                base_image(x, y) = aLowerThreshold;
            else if (base_image(x, y) > anUpperThreshold)
                base_image(x, y) = anUpperThreshold;
        }
    }
    
    return base_image;
}

Image Image::threshold(float aThreshold) const {
    Image base_image(*this);
    
    // TODO: Check threshold is within image range
    for (size_t x = 0; x < base_image.m_width; ++x) {
        for (size_t y = 0; y < base_image.m_height; ++y) {
            if (base_image(x, y) < aThreshold) {
                base_image(x, y) = 0;
            } else {
                base_image(x, y) = 1;
            }
        }
    }
    
    return base_image;
}

Image Image::threshold(float aLowerThreshold, float anUpperThreshold) const {
    Image base_image(*this);
    
    // TODO: Check threshold is within image range
    for (size_t x = 0; x < base_image.m_width; ++x) {
        for (size_t y = 0; y < base_image.m_height; ++y) {
            if (base_image(x, y) < aLowerThreshold) {
                base_image(x, y) = 0;
            } else if (base_image(x, y) > anUpperThreshold) {
                base_image(x, y) = 0;
            } else {
                base_image(x, y) = 1;
            }
        }
    }
    
    return base_image;
}
