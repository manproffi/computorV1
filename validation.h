#ifndef VALIDATION_H
#define VALIDATION_H

#include <iostream>
#include <list>
#include <vector>
#include <map>

class validation
{
public:
    validation(char *);
    bool    checking();


private:
    void    checkOperators();
    void    takeToken();
    void    preparationReducedForm();
    void    moveAllTokenToLeftSide();
    void    printReducedForm() const;

    std::string                 m_input;
    std::list<std::string>      m_operator;
    std::vector<std::string>    m_token;
    std::vector<std::vector<std::string>> m_vect_token;
    std::map<std::string, float> m_map_token;
};

#endif // VALIDATION_H
