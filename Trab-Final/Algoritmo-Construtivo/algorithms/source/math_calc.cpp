// Math formulas file

#include "../math_calc.hpp"

double euclidian_distance(double x1, double y1, double x2, double y2) {
    double x = x1 - x2;
    double y = y1 - y2;
    return pow(pow(x, 2) + pow(y, 2), 1/2);
}