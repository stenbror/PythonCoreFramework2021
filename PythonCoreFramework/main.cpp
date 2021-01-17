//
//  main.cpp
//  PythonCoreFramework
//
//  Created by Richard Magnor Stenbro on 14/01/2021.
//

#include <iostream>

#include "sourcecode.hpp"

using namespace PythonCoreFramework::Runtime;


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    auto *px = reinterpret_cast<const char*>(+u8"z\u00df\u6c34\U0001f34c");
    
    auto cool = new SourceCode(px, Encoding::ENC_UTF8);
    
    auto cx1 = cool->getChar();
    auto cx2 = cool->getChar();
    auto cx3 = cool->getChar();
    auto cx4 = cool->getChar();
    auto cx5 = cool->getChar();
    
    return 0;
}
