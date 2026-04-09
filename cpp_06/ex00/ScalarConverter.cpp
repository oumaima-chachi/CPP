#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <cctype>
#include <iomanip>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}
ScalarConverter::~ScalarConverter() {}

static bool isPseudo(const std::string& s)
{
    return (s == "nan" || s == "nanf" ||
            s == "+inf" || s == "-inf" ||
            s == "+inff" || s == "-inff");
}

void ScalarConverter::convert(std::string literal)
{
    double value = 0.0;

    // pseudoliterals
    if (isPseudo(literal))
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";

        if (literal == "nan" || literal == "nanf")
        {
            std::cout << "float: nanf\n";
            std::cout << "double: nan\n";
        }
        else if (literal[0] == '-')
        {
            std::cout << "float: -inff\n";
            std::cout << "double: -inf\n";
        }
        else
        {
            std::cout << "float: +inff\n";
            std::cout << "double: +inf\n";
        }
        return;
    }

    // Detect char
    if (literal.length() == 1 && !std::isdigit(literal[0])) //1 char et not digit
    {
        value = static_cast<double>(literal[0]);//ascii
    }
    else
    {

        char* end;
        value = std::strtod(literal.c_str(), &end);

        if (*end != '\0')
        {
            if (!(*end == 'f' && *(end + 1) == '\0'))
            {
                std::cout << "char: impossible\n";
                std::cout << "int: impossible\n";
                std::cout << "float: impossible\n";
                std::cout << "double: impossible\n";
                return;
            }
        }
    }

    // CHAR
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value) ||
        value < 0 || value > 127)
        std::cout << "impossible\n";
    else if (!std::isprint(static_cast<char>(value)))
        std::cout << "Non displayable\n";//0-31
    else
        std::cout << "'" << static_cast<char>(value) << "'\n";

    // INT
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value) ||
        value > std::numeric_limits<int>::max() ||
        value < std::numeric_limits<int>::min())
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(value) << "\n";

    // FLOAT
    std::cout << "float: ";
    std::cout << std::fixed << std::setprecision(1)
              << static_cast<float>(value) << "f\n";

    // DOUBLE
    std::cout << "double: ";
    std::cout << std::fixed << std::setprecision(1)
              << value << "\n";
}


// /*

// hado smithum un pseudo-literal

// | Valeur  | Type   | Exemple      |
// | ------- | ------ | ------------ |
// | `nan`   | double | Not A Number |
// | `nanf`  | float  | Not A Number |
// | `+inf`  | double | +infinity    |
// | `-inf`  | double | -infinity    |
// | `+inff` | float  | +infinity    |
// | `-inff` | float  | -infinity    |

// En mémoire, c’est stocké selon la norme IEEE 754 pour les floats et doubles.
// */
