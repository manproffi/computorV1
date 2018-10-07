#ifndef CALCULATION_H
#define CALCULATION_H

#include <iostream>
#include <map>

class calculation
{
public:
    calculation(std::map<std::string, float> input_map);
    void startCalculation() const;

private:

    void    checkPower() const;
    void    calcucalePolynomialEquations() const;
    void    calcucaleLinearEquations() const;
    void    calcucateZeroDegree() const;




    std::map<std::string, float> m_map;
};

#endif // CALCULATION_H
