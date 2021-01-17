//
//  parser.hpp
//  PythonCoreFramework
//
//  Created by Richard Magnor Stenbro on 17/01/2021.
//

#ifndef parser_hpp
#define parser_hpp

#include <memory>

#include "sourcecode.hpp"

namespace PythonCoreFramework::Runtime
{
    enum class TokenKind
    {
        Empty, Newline, Indent, Dedent, TypeComment, PyFalse, PyNone, PyTrue, PyAnd, PyAs, PyAssert, PyAsync, PyAwait,
        PyBreak, PyClass, PyContinue, PyDef, PyDel, PyElif, PyElse, PyExcept, PyFinally, PyFor, PyFrom, PyGlobal,
        PyIf, PyImport, PyIn, PyIs, PyLambda, PyNonlocal, PyNot, PyOr, PyPass, PyRaise, PyReturn, PyTry, PyWhile,
        PyWith, PyYield, PyPlus, PyMinus, PyMul, PyDiv, PyPower, PyFloorDiv, PyModulo, PyMatrice, PyShiftLeft,
        PyShiftRihght, PyBitAnd, PyBitOr, PyBitXor, PyBitInvert, PyLess, PyLessEqual, PyEqual, PyGreaterEqual,
        PyGreater, PyNotEqual, PyLeftParen, PyLeftBracket, PyLeftCurly, PyRightParen, PyRightBracket, PyRightCurly,
        PyComma, PyDot, PyElipsis, PyColon, PySemiColon, PyAssign, PyArrow, PyPlusAssign, PyMinusAssign,
        PyMulAssign, PyPowerAssign, PyDivAssign, PyFloorDivAssign, PyModuloAssign, PyMatriceAssign, PyBitAndAssign,
        PyBitXorAssign, PyBitOrAssign, PyShiftLeftAssign, PyShiftRightAssign, Name, Number, String, EndOfFile
    };

    class Token
    {
    private:
        TokenKind m_kind;
        uint32_t m_startPos;
        uint32_t m_endPos;
        uint32_t m_rawStartPos;
        uint32_t m_rawEndPos;
        
    public:
        Token(uint32_t start, uint32_t end, uint32_t rawStart, uint32_t rawEnd, TokenKind kind);
        TokenKind getKind();
    };


    class PythonCoreParser
    {
    public:
        PythonCoreParser(std::shared_ptr<SourceCode> buf, uint8_t tabSize);
        ~PythonCoreParser();
        void advance();
        
    private:
        std::shared_ptr<SourceCode> m_buf;
        uint8_t m_tabSize;
        std::shared_ptr<Token> m_curSymbol;
        uint32_t m_curSymbolStartPosition;
        uint32_t m_rawCurSymbolStartPosition;
    };
}

#endif /* parser_hpp */
