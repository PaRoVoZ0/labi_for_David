#include <iostream> 
#include <cmath> 
#include <iomanip> 

double Y(double x) {
    return (2 * x * sin(x) - 2 + cos(x)) / 4.0;
}

// Функция S(x) для варианта 11 с подсчётом итераций
double S(double x, double eps, int &iter_count) {
    double sum = 0.0;
    double a_k;
    int k = 2;
    iter_count = 0;

    while (true) {
        a_k = pow(-1, k) * cos(k * x) / (k * k - 1);
        sum += a_k;
        iter_count++;
        if (fabs(a_k) < eps) {
            break;
        }
        k++;
    }
    return sum;
}

int main() {
    double a = -1.0;
    double b = 1.3;
    double h = 0.1;
    double eps = 1e-5;

    std::cout << std::fixed << std::setprecision(4);
    std::cout << std::setw(10) << "x" << std::setw(15) << "Y(x)" << std::setw(15) << "S(x)" << std::setw(10) << "iter" << std::endl;
    std::cout << std::string(50, '-') << std::endl;

    for (double x = a; x <= b + h/2; x += h) {
        int iter;
        double y_val = Y(x);
        double s_val = S(x, eps, iter);
        std::cout << std::setw(10) << x << std::setw(15) << y_val << std::setw(15) << s_val << std::setw(10) << iter << std::endl;
    }

    return 0;
}