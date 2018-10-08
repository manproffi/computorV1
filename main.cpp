#include <iostream>
//#include "lexer.h"
#include "validation.h"
#include "calculation.h"

int main(int argc, char *argv[])
{
    if (argc == 2) {
        validation  val(argv[1]);
        if (val.checking()) {
//            std::cout << "Calculate" << std::endl;
            calculation calc(val.getMap());
            calc.startCalculation();
        }
    } else {
        std::cout << "usage: ./computer \"polynomial equation\"" << std::endl;
    }
    // std::cout << std::endl;
    return 0;
}
