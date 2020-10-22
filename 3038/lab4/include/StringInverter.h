#ifndef __StringInverter_h
#define __StringInverter_h

#include <iostream>

class StringInverter;

class StringInverter {
    
public:
    StringInverter();
    StringInverter(const StringInverter& aString);
    StringInverter(const char* aString);
    StringInverter(const std::string& aString);
    
    StringInverter& operator=(const StringInverter& aString);
    StringInverter& operator=(const char* aString);
    StringInverter& operator=(const std::string& aString);
    
    const std::string& getInvertedString() const;
    
    bool operator==(const StringInverter& aString) const;
    bool operator==(const char* aString) const;
    bool operator==(const std::string& aString) const;
    
    bool operator!=(const StringInverter& aString) const;
    bool operator!=(const char* aString) const;
    bool operator!=(const std::string& aString) const;
    
    ~StringInverter();
    
protected:
    std::string m_data;
};

#endif // __StringInverter_h
