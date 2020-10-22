#include "Integer.h"

Integer::Integer():
    m_data(0)
{}

Integer::~Integer()
{}

Integer::Integer(const Integer& aValue):
    m_data(aValue.m_data)
{}

Integer::Integer(int aValue):
    m_data(aValue)
{}

Integer& Integer::operator=(const Integer& aValue)
{
    m_data = aValue.m_data;
    return (*this);
}

Integer& Integer::operator=(int aValue)
{
    m_data = aValue;
    return (*this);
}

std::ostream& operator<<(std::ostream& aStream, const Integer& aValue)
{
    aStream << aValue.m_data;
    return (aStream);
}


std::istream& operator>>(std::istream& aStream, Integer& aValue)
{
    aStream >> aValue.m_data;
    return (aStream);
}
