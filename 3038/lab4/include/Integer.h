#ifndef __Integer_h
#define __Integer_h

#include <iostream>

class Integer;
std::ostream& operator<<(std::ostream& aStream, const Integer& aValue);
std::istream& operator>>(std::istream& aStream, Integer& aValue);

class Integer {
    
public:
    Integer();
    Integer(const Integer& aValue);
    Integer(int aValue);

    
    ~Integer();
    
    Integer& operator=(const Integer& anInteger);
    Integer& operator=(int anInteger);

    friend std::ostream& operator<<(std::ostream& aStream, const Integer& aValue);
    friend std::istream& operator>>(std::istream& aStream, Integer& aValue);
    
protected:
    int m_data;
};

#endif // __Integer_h
