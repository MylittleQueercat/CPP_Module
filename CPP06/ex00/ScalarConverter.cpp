#include "ScalarConverter.hpp"

// convert helpers

// les nombres specifiques
static bool isPseudo(const std::string &s) {
    return (s == "nan" || s == "nanf" || s == "-inf" ||
            s == "+inf" || s == "+inff" || s == "-inff");
}

// si input est un single nonnumeric charliteral
static bool isCharLiteral(const std::string &s) {
    return (s.size() == 1 && !std::isdigit(static_cast<unsigned char>(s[0])));
}

// "42.0f"
static bool endsWithF(const std::string &s) {
    return (s.size() > 1 && s[s.size() - 1] == 'f');
}

// convertir string s -> double
static bool parseDouble(const std::string &s, double &out) {
    std::string t = s;
    if (endsWithF(t) && !isPseudo(t))
        t = t.substr(0, t.size() - 1);

    char *end = NULL;
    errno = 0;
    out = std::strtod(t.c_str(), &end);

    if (!end || *end != '\0')
        return false;

    (void)errno;
    return true;
}

// verifier si double est intergral
static bool isIntegralDouble(double x) {
    if (std::isnan(x) || std::isinf(x))
        return false;
    return (x == std::floor(x));
}

static void printChar(double v) {
    std::cout << "char: ";
    if (std::isnan(v) || std::isinf(v) || v < 0 || v > 127) {
        std::cout << "impossible\n";
        return;
    }
    char c = static_cast<char>(v);
    if (!std::isprint(static_cast<unsigned char>(c))) {
        std::cout << "Not displayable\n";
        return;
    }
    std::cout << "'" << c << "'" << "\n";
}

static void printInt(double v) {
    std::cout << "int: ";
    if (std::isnan(v) || std::isinf(v) || v < INT_MIN || v > INT_MAX) {
        std::cout << "impossible\n";
        return;
    }
    int i = static_cast<int>(v);
    std::cout << i << "\n";
}

static void printFloat(double v) {
    std::cout << "float: ";
    if (std::isnan(v)) {
        std::cout << "nanf\n";
        return;
    }
    if (std::isinf(v)) {
        if (v < 0)
            std::cout << "-inff\n";
        else
            std::cout << "+inff\n";
    }

    float f = static_cast<float>(v);

    if (isIntegralDouble(v))
        std::cout << std::fixed << std::setprecision(1);
    else
        std::cout << std::fixed << std::setprecision(6);
    
    std::cout << f << "f\n";

    std::cout.unsetf(std::ios::floatfield);
    std::cout << std::setprecision(6);
}

static void printDouble(double v) {
    std::cout << "double: ";
    if (std::isnan(v)) {
        std::cout << "nan\n";
        return;
    }
    if (std::isinf(v)) {
        if (v < 0)
            std::cout << "-inf\n";
        else
            std::cout << "+inf\n";
        return;
    }

    if (isIntegralDouble(v))
        std::cout << std::fixed << std::setprecision(1);
    else
        std::cout << std::fixed << std::setprecision(6);

    std::cout << v << "\n";

    std::cout.unsetf(std::ios::floatfield);
    std::cout << std::setprecision(6);
}


// class

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &literal) {
    double value = 0.0;

    // char
    if (isCharLiteral(literal)) {
        value = static_cast<double>(literal[0]);
        printChar(value);
        printInt(value);
        printFloat(value);
        printDouble(value);
        return;
    }

    // pseudo-literals
    if (isPseudo(literal)) {
        if (!parseDouble(literal, value)) {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: impossible\n";
            std::cout << "double: impossible\n";
            return;
        }
        printChar(value);
        printInt(value);
        printFloat(value);
        printDouble(value);
        return;
    }

    // numeric
    if (!parseDouble(literal, value)) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}