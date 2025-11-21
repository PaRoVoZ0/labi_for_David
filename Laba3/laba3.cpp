#include <iostream>
#include <cmath>
#include <iomanip>

double fact(double n);

int main(){
    double a = 0.1, b = 1, n = 100, x = a, h = (b - a) / 10, S = 0, Y;

    std::cout << "   S(x)   |   Y(x)   " << std::endl;
    std::cout << "---------------------" << std::endl;

    // for (float x = a; x < b; x += h) {
    //     S += pow(-1, n) * (2 * sqrt(n) + 1)/(fact(2 * n)) * pow(x, 2 * n);
    //     Y = (1 - sqrt(x) / 2) * cos(x) - x / 2 * sin(x);

    //     std::cout << std::left << std::setprecision(3) << std::setw(3) << " " << std::setw(7) << S << std::setw(4) << '|' << Y << std::endl; 
    // }

    do {
        double temp;

        for (double i = 0; i <= n; i++) {
            temp = pow(-1, i) * (2 * pow(i, 2) + 1)/(fact(2 * i)) * pow(x, 2 * i);
            S += temp;
            //std::cout << S << ' ';
        }

        Y = (1 - pow(x, 2) / 2) * cos(x) - x / 2 * sin(x);
        
        std::cout << std::left << std::setprecision(3) << std::setw(3) << " " << std::setw(7) << S << std::setw(4) << '|' << Y << std::endl;
        
        x += h;
        S = 0;
    } while (x < b - h);


}

double fact(double n){
    double res = 1;

    for(int k = 1; k <= n; k++){
        res *= k;
    }

    return res;
}
