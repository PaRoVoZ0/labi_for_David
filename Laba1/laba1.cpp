#include <iostream>
#include <cmath>

int main() {
    setlocale(LC_ALL, "rus");
    double x = 6.251, y = 0.827, z = 25.001;

    double S = pow(y, cbrt(fabs(x))) + pow(cos(y), 3) * (fabs(x - y) * (1 + (pow(sin(z),2))/sqrt(x + y)))/(exp(fabs(x - y)) + x/2);

    std::cout <<  "Путем нехитрых вычислений понимаем, что ответ: " << S << std::endl;
}