//
//  sourcecode.cpp
//  PythonCoreFramework
//
//  Created by Richard Magnor Stenbro on 17/01/2021.
//

#include "sourcecode.hpp"

using namespace PythonCoreFramework::Runtime;

SourceCode::SourceCode(const char *pInitBuffer, Encoding enc)
{
    pBufferStart = pInitBuffer;
    p = pBufferStart;
    m_encoding = enc;
    m_steps = 0;
    m_index = 0;
    m_rawIndex = 0;
}

char32_t SourceCode::decode_unicode_utf8_char()
{
    if ((*p & 0b10000000) == 0)
    {
        m_steps = 1;
        return *p;
    }
    else if ((*p & 0b11100000) == 0b11000000)
    {
        if ((p[1] & 0b11000000) == 0b10000000)
        {
            m_steps = 2;
            return  static_cast<char32_t>(*p & 0b00011111) << 6 |
                    static_cast<char32_t>(p[1] & 0b00111111);
        }
        
    }
    else if ((*p & 0b11110000) == 0b11100000)
    {
        if ((p[1] & 0b11000000) == 0b10000000 && (p[2] & 0b11000000) == 0b10000000)
        {
            m_steps = 3;
            return  static_cast<char32_t>(*p & 0b00001111) << 12 |
                    static_cast<char32_t>(p[1] & 0b00111111) << 6 |
                    static_cast<char32_t>(p[2] & 0b00111111);
        }
    }
    else if ((*p & 0b11111000) == 0b11110000)
    {
        if ((p[1] & 0b11000000) == 0b10000000 && (p[2] & 0b11000000) == 0b10000000 && (p[3] & 0b11000000) == 0b10000000)
        {
            m_steps = 4;
            return  static_cast<char32_t>(*p & 0b00000111) << 18 |
                    static_cast<char32_t>(p[1] & 0b00111111) << 12 |
                    static_cast<char32_t>(p[2] & 0b00111111) << 6 |
                    static_cast<char32_t>(p[3] & 0b00111111);
        }
    }
    else if ((*p & 0b11111100) == 0b11111000)
    {
        if ((p[1] & 0b11000000) == 0b10000000 && (p[2] & 0b11000000) == 0b10000000 && (p[3] & 0b11000000) == 0b10000000 && (p[4] & 0b11000000) == 0b10000000)
        {
            m_steps = 5;
            return  static_cast<char32_t>(*p & 0b00000011) << 24 |
                    static_cast<char32_t>(p[1] & 0b00111111) << 18 |
                    static_cast<char32_t>(p[2] & 0b00111111) << 12 |
                    static_cast<char32_t>(p[3] & 0b00111111) << 6 |
                    static_cast<char32_t>(p[4] & 0b00111111);
        }
    }
    else if ((*p & 0b11111110) == 0b11111100)
    {
        if ((p[1] & 0b11000000) == 0b10000000 && (p[2] & 0b11000000) == 0b10000000 && (p[3] & 0b11000000) == 0b10000000 && (p[4] & 0b11000000) == 0b10000000 && (p[5] & 0b11000000) == 0b10000000)
        {
            m_steps = 6;
            return  static_cast<char32_t>(*p & 0b00000001) << 30 |
                    static_cast<char32_t>(p[1] & 0b00111111) << 24 |
                    static_cast<char32_t>(p[2] & 0b00111111) << 18 |
                    static_cast<char32_t>(p[3] & 0b00111111) << 12 |
                    static_cast<char32_t>(p[4] & 0b00111111) << 6 |
                    static_cast<char32_t>(p[5] & 0b00111111);
        }
    }
    
    return 0;

}

char32_t SourceCode::peekChar()
{
    if (*p != '\0')
    {
        switch (m_encoding)
        {
            case Encoding::ENC_UTF8:
                return decode_unicode_utf8_char();
        }
    }
    
    return 0x00;
}

char32_t SourceCode::getChar()
{
    char32_t ch = peekChar();
    if (ch != U'\0')
    {
        p = (p + m_steps);
        m_index++;
        m_rawIndex += m_steps;
        return ch;
    }
    
    return 0x00;
}
