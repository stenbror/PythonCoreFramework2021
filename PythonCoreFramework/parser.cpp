//
//  parser.cpp
//  PythonCoreFramework
//
//  Created by Richard Magnor Stenbro on 17/01/2021.
//

#include "parser.hpp"

using namespace PythonCoreFramework::Runtime;


Token::Token(uint32_t start, uint32_t end, uint32_t rawStart, uint32_t rawEnd, TokenKind kind)
{
    
}




PythonCoreParser::PythonCoreParser(std::shared_ptr<SourceCode> buf, uint8_t tabSize)
{
    m_buf = buf;
    m_tabSize = tabSize;
}

PythonCoreParser::~PythonCoreParser()
{}

void PythonCoreParser::advance()
{
    m_curSymbolStartPosition = m_buf->getPosition();
    m_rawCurSymbolStartPosition = m_buf->getRawPosition();
    char32_t ch = m_buf->getChar();
    
    
    
    
    /* Operators or delimiters */
    switch (ch)
    {
        case '+':
            if (m_buf->peekChar() == '=')
            {
                m_buf->getChar();
                m_curSymbol = std::make_shared<Token>(m_curSymbolStartPosition, m_buf->getPosition(),
                                                      m_rawCurSymbolStartPosition, m_buf->getRawPosition(),
                                                      TokenKind::PyPlusAssign);
                return;
            }
            m_curSymbol = std::make_shared<Token>(m_curSymbolStartPosition, m_buf->getPosition(),
                                                  m_rawCurSymbolStartPosition, m_buf->getRawPosition(),
                                                  TokenKind::PyPlus);
            return;
        case '-':
            if (m_buf->peekChar() == '=')
            {
                m_buf->getChar();
                m_curSymbol = std::make_shared<Token>(m_curSymbolStartPosition, m_buf->getPosition(),
                                                      m_rawCurSymbolStartPosition, m_buf->getRawPosition(),
                                                      TokenKind::PyMinusAssign);
                return;
            }
            else if (m_buf->peekChar() == '>')
            {
                m_buf->getChar();
                m_curSymbol = std::make_shared<Token>(m_curSymbolStartPosition, m_buf->getPosition(),
                                                      m_rawCurSymbolStartPosition, m_buf->getRawPosition(),
                                                      TokenKind::PyArrow);
                return;
            }
            m_curSymbol = std::make_shared<Token>(m_curSymbolStartPosition, m_buf->getPosition(),
                                                  m_rawCurSymbolStartPosition, m_buf->getRawPosition(),
                                                  TokenKind::PyMinus);
            return;
        default:
            break;
    }
}
