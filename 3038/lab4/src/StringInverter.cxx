#include "StringInverter.h"

StringInverter::StringInverter():
        m_data("")
{}

StringInverter::StringInverter(const StringInverter& aString):
    m_data(aString.m_data)
{}

StringInverter::StringInverter(const char* aString):
    m_data(aString.m_data*)
{}
