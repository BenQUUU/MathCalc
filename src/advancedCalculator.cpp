#include "../include/advancedCalculator.hpp"

using CalculatorFunction = std::function<ErrorCode(double, double, double*)>;

ErrorCode process(std::string input, double* out) {
    std::unordered_map<char, CalculatorFunction> calculatorFunctions = {
        {'+', [](double a, double b, double* out) { *out = a + b; return OK; }},
        {'-', [](double a, double b, double* out) { *out = a - b; return OK; }},
        {'*', [](double a, double b, double* out) { *out = a * b; return OK; }},
        {'/', [](double a, double b, double* out) {
             if (b == 0)
                 return DivideBy0;
             *out = a / b;
             return OK;
         }},
        {'%', [](double a, double b, double* out) {
             if (std::floor(a) != a || std::floor(b) != b)
                 return ModuleOfNonIntegerValue;
             if (b == 0)
                 return DivideBy0;
             *out = std::fmod(a, b);
             return OK;
         }},
        {'^', [](double a, double b, double* out) {
             *out = std::pow(a, b);
             return OK;
         }},
        {'$', [](double a, double b, double* out) {
             if (a < 0)
                 return SqrtOfNegativeNumber;
             *out = std::pow(a, 1.0 / b);
             return OK;
         }},
        {'!', [](double a, double b, double* out) {
             if (a < 0 || std::floor(a) != a)
                 return BadFormat;
             double result = 1;
             for (int i = 2; i <= a; ++i)
                 result *= i;
             *out = result;
             return OK;
         }}};

    double operand1, operand2;
    char operation;

    if (std::sscanf(input.c_str(), "%lf %c %lf", &operand1, &operation, &operand2) != 3) {
        return BadFormat;
    }

    auto it = calculatorFunctions.find(operation);
    if (it == calculatorFunctions.end()) {
        return BadCharacter;
    }

    return it->second(operand1, operand2, out);
}