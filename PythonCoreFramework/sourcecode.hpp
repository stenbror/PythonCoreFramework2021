//
//  sourcecode.hpp
//  PythonCoreFramework
//
//  Created by Richard Magnor Stenbro on 17/01/2021.
//

#ifndef sourcecode_hpp
#define sourcecode_hpp

#include <locale>

namespace PythonCoreFramework::Runtime
{
    enum class Encoding
    {
        ENC_UTF8
    };

    class SourceCode
    {
    private:
        const char *pBufferStart;
        const char *p;
        Encoding m_encoding;
        uint8_t m_steps;
        uint32_t m_index; // Unicode decoded char index.
        uint32_t m_rawIndex; // Raw undecoded characters in raw char buffer index.
        uint32_t m_size;
        
    private:
        char32_t decode_unicode_utf8_char();
        
    public:
        SourceCode(const char *pInitBuffer, Encoding enc);
        
        char32_t getChar();
        char32_t peekChar();
        //uint32_t size();
        //char32_t at(uint32_t index);
        uint32_t getPosition() { return m_index; };
        uint32_t getRawPosition() { return m_rawIndex; };

    };
}

#endif /* sourcecode_hpp */
