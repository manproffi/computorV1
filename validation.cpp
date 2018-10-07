#include <regex>
#include <stdlib.h>
#include <utility>
#include <sstream>
#include "validation.h"

#define REGEX "([-]?\\d+(.\\d+)?)\\s+[*]\\s+X\\^\\d+"

validation::validation(char *str): m_input(str)
{
    std::cout << "Constructor: " << m_input << std::endl;
}

bool validation::checking()
{
    checkOperators();
    takeToken();
    preparationReducedForm();
    moveAllTokenToLeftSide();
    printReducedForm();
    return true;
}

std::map<std::string, float> const & validation::getMap() const
{
    return m_map_token;
}

void validation::checkOperators()
{
    bool operatorEqualPresent = false;

    /*
     * create list with separator s_regex
     */

    std::regex s_regex(REGEX);
    std::list<std::string>  list(std::sregex_token_iterator(m_input.begin(),
                                                            m_input.end(),
                                                            s_regex,
                                                            -1),
                                 std::sregex_token_iterator());

    if (*list.begin() == "") {
        list.pop_front();
    }
    for (auto m:list) {
        if (!std::regex_match(m, std::regex("\\s+[+=-]\\s+"))) {
            std::cout << "Error: [" << m << "]" << std::endl;
            exit(1);
        } else if (std::regex_match(m, std::regex("\\s+[=]\\s+"))) {
            operatorEqualPresent = true;
        }
//        std::cout << m << std::endl; //delete
    }
    if (!operatorEqualPresent) {
        std::cout << "Error: missing equal operator" << std::endl;
        exit(1);
    }
    m_operator = list;
}

/*
 * take token in format "3 * X^0"
*/

void validation::takeToken()
{
    std::string tmp(m_input);
    std::smatch m;
    std::regex  e(REGEX);

    while(std::regex_search(tmp, m, e)) {
        m_token.push_back(*m.begin());
//        std::cout << *m.begin() << std::endl; //delete
        tmp = m.suffix().str();
    }
}

void validation::preparationReducedForm()
{
    /*
     * create m_vect_token witch include :
     * [0] - number : -3.12
     * [1] - X^n
     * [2] - operator : [+ - =]
     */
    std::vector<std::string> tmpVect;
    std::regex e("(.+)\\s+[*]\\s+(.+)");
    std::smatch m;

    m_operator.push_front(" + ");
    auto it = m_operator.begin();
    for (auto x : m_token) {
        std::regex_match(x, m, e);
        tmpVect.clear();
        tmpVect.push_back(m[1].str());
        tmpVect.push_back(m[2].str());
        tmpVect.push_back(it.operator*());
        ++it;
        m_vect_token.push_back(tmpVect);
    }
}

void validation::moveAllTokenToLeftSide()
{
    bool flagEqual = false;
    float   num = 0;
    for (auto x:m_vect_token) {
        try {
            auto y = x[2];
            if (std::regex_match(y, std::regex("\\s+[+]\\s+"))) {
                num = std::stof(x[0]) * (flagEqual ? -1 : 1);
            } else if (std::regex_match(y, std::regex("\\s+[-]\\s+"))) {
                num = std::stof(x[0]) * (flagEqual ? 1 : -1);
            } else if (std::regex_match(y, std::regex("\\s+[=]\\s+"))) {
                num = std::stof(x[0]) * (flagEqual ? 1 : -1);
                flagEqual = true;
            } else {
                std::cout << "Ups:: error: " << y << std::endl;
            }
            m_map_token[x[1]] = m_map_token[x[1]] + num;
        } catch (std::exception &e) {
            std::cout << "Error stof: " << e.what() << std::endl;
        }
    }
}

void validation::printReducedForm() const
{
    std::stringstream   ss;
    int                 polynomialDegree = 0;
    std::smatch         m;
    std::cout << "Reduced form: ";
    for (auto x : m_map_token) {
        std::regex_match(x.first, m, std::regex("X\\^(\\d+)"));
        if (polynomialDegree < std::stoi(m[1])) {
            polynomialDegree = std::stoi(m[1]);
        }
        if (x == m_map_token.begin().operator*()) {
            ss << x.second << " * " << x.first;
        } else {
            ss << " " << ((x.second < 0) ? "-" : "+");
            ss << " " << ((x.second < 0) ? (x.second * -1) : x.second);
            ss << " * " << x.first;
        }
    }
    std::cout << ss.str() << " = 0" << std::endl;
    ss.str("");
    ss << polynomialDegree;
    std::cout << "Polynomial degree: " << ss.str() << std::endl;
    if (polynomialDegree > 2) {
        std::cout << "The polynomial degree is stricly greater than 2, I can't solve" << std::endl;
        exit(1);
    }
}

const char *validation::ErrorLexical::what() const _NOEXCEPT
{
    return "Lexical error: ";
}
