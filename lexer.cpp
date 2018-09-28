#include "lexer.h"
#include <regex>

lexer::lexer(std::string str): input(str)
{
    std::cout << "Constructor: " << input << std::endl;
}

void lexer::lexChecking()
{
    std::regex s_regex("\\d+\\s+[*]\\s+X\\^\\d+");
    std::copy(std::sregex_token_iterator(input.begin(), input.end(), s_regex, -1),
              std::sregex_token_iterator(),
              std::ostream_iterator<std::string>(std::cout, "\n"));
}

void lexer::findToken()
{
    std::string tmp(input);
    std::smatch m;
    std::regex  e("\\d+\\s+[*]\\s+X\\^\\d+");

    while(std::regex_search(tmp, m, e)) {
        for (auto x:m)
            std::cout << x << std::endl;
        tmp = m.suffix().str();
    }
}
