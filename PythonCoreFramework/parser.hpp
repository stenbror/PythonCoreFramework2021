//
//  parser.hpp
//  PythonCoreFramework
//
//  Created by Richard Magnor Stenbro on 17/01/2021.
//

#ifndef parser_hpp
#define parser_hpp

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
        PyComma, PyDot, PyElipsis, PyColon, PySemiColon, PyAssign, Py_Arrow, PyPlusAssign, PyMinusAssign,
        PyMulAssign, PyPowerAssign, PyDivAssign, PyFloorDivAssign, PyModuloAssign, PyMatriceAssign, PyBitAndAssign,
        PyBitXorAssign, PyBitOrAssign, PyShiftLeftAssign, PyShiftRightAssign, Name, Number, String, EndOfFile
    };
}

#endif /* parser_hpp */
