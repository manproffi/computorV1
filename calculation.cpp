#include "calculation.h"
#include <cmath>
#include <limits>

calculation::calculation(std::map<std::string, float> input_map) : m_map(input_map)
{
//    std::cout << "constructor" << std::endl; //delete
}

void calculation::startCalculation() const
{
    checkPower();
}

/*
 *  powerPresent[0] = X^0
 *  powerPresent[1] = X^1
 *  powerPresent[2] = X^2
*/

void calculation::checkPower() const
{
    bool powerPresent[3] = {false, false, false};

    for (auto x:m_map) {
//        std::cout << x.first << " " << x.second << std::endl; //delete
        if (x.first.c_str()[2] == '0') {
            powerPresent[0] = true;
        } else if (x.first.c_str()[2] == '1') {
            powerPresent[1] = true;
        } else if (x.first.c_str()[2] == '2') {
            powerPresent[2] = true;
        } else {
            std::cout << "Error: incorrect behavior" << std::endl;
        }
    }

//    std::cout << powerPresent[0] << powerPresent[1] << powerPresent[2] << std::endl; //delete

    if (powerPresent[2] && powerPresent[1] && powerPresent[0]) {
        calcucalePolynomialEquations();
    } else if (!powerPresent[2] && powerPresent[1] && powerPresent[0]) {
        calcucaleLinearEquations();
    } else if (!powerPresent[2] && !powerPresent[1] && powerPresent[0]) {
//        std::cout << "X^0" << std::endl;
        calcucateZeroDegree();
    } else {
        std::cout << "Error: incorrect input. The powers must be well ordered and all present" << std::endl;
    }
}

void calculation::calcucalePolynomialEquations() const
{
    if (m_map.at("X^2") > 0 || m_map.at("X^2") < 0) {

        float a = m_map.at("X^2");
        float b = m_map.at("X^1");
        float c = m_map.at("X^0");
        float x = 0;
        float des = b * b - 4 * a * c;
        if (des > 0) {
            // des > 0
            std::cout << "Discriminant is strictly positive (" << des << "), the two solutions are:" << std::endl;
            x = (-1 * b - sqrt( b * b - 4 * a * c)) / (2 * a);
            std::cout << x << std::endl;
            x =  (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a);
            std::cout << x << std::endl;
        } else if (des < 0) {
            // des < 0
            std::cout << "Discriminant is strictly negative (" << des << "), the two solutions are:" << std::endl;
            std::cout << ((-b) / (2 * a))  << " + " << (sqrt(-1 * des) / (2 * a)) << " * i" << std::endl;
            std::cout << ((-b) / (2 * a))  << " - " << (sqrt(-1 * des) / (2 * a)) << " * i" << std::endl;
        } else {
            // des == 0
            std::cout << "Discriminant is equal to 0, the two equal solutions are:" << std::endl;
            x = -b / (2 * a);
            std::cout << x << std::endl;
            std::cout << x << std::endl;
        }
    } else {
        //std::cout << "Error: 0 * X^2 = 0" << std::endl;
        calcucaleLinearEquations();
    }
}

void calculation::calcucaleLinearEquations() const
{
    float b = m_map.at("X^1");
    float c = m_map.at("X^0");
    float res = (-c / b);
    if (isinf(res)) {
        std::cout << "Equation isn't solvable: c / b = " << -c << " / " << b << std::endl;
    } else {
        std::cout << "The solution is:" << std::endl;
        std::cout << (-c / b) << std::endl;
    }
}

void calculation::calcucateZeroDegree() const
{
    float c = m_map.at("X^0");
    float y = 0;
    float res = y / c;
     std::cout << "The solution is:" << std::endl;
    if (isnan(res)) {
        std::cout << "All the real numbers are solution" << std::endl;
    } else {
        std::cout << res << std::endl;
    }
}

