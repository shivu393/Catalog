#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

long long convertToDecimal(const std::string& value, int base) {
    long long decimalValue = 0;
    for (char digit : value) {
        int numericValue;
        if (isdigit(digit)) {
            numericValue = digit - '0';
        } else {
            numericValue = toupper(digit) - 'A' + 10; 
        }
        if (numericValue >= base) {
            throw std::invalid_argument("Digit out of base range");
        }
        decimalValue = decimalValue * base + numericValue;
    }
    return decimalValue;
}

long long lagrangeInterpolation(const std::vector<long long>& xValues, const std::vector<long long>& yValues, long long x) {
    long long result = 0;
    size_t k = xValues.size();
    for (size_t i = 0; i < k; ++i) {
        long long term = yValues[i];
        for (size_t j = 0; j < k; ++j) {
            if (i != j) {
                term *= (x - xValues[j]) / (xValues[i] - xValues[j]);
            }
        }
        result += term;
    }
    return result;
}

int main() {
    // Hardcoded values from the second test case
    std::vector<long long> xValues = {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    std::vector<long long> yValues = {
        convertToDecimal("28735619723837", 10),
        convertToDecimal("1A228867F0CA", 16),
        convertToDecimal("32811A4AA0B7B", 12),
        convertToDecimal("917978721331A", 11),
        convertToDecimal("1A22886782E1", 16),
        convertToDecimal("28735619654702", 10),
        convertToDecimal("71AB5070CC4B", 14),
        convertToDecimal("122662581541670", 9),
        convertToDecimal("642121030037605", 8)
    };

    long long c = lagrangeInterpolation(xValues, yValues, 0);
    std::cout << "Constant term c: " << c << std::endl;

    return 0;
}
