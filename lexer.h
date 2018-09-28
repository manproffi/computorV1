#ifndef LEXER_H
#define LEXER_H

#include <iostream>

class lexer
{
public:
    lexer(std::string input);
    void    lexChecking();
    void    findToken();
private:
    std::string input;
};

#endif // LEXER_H
