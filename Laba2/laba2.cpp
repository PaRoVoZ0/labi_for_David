#include <cmath>;
#include <iomanip>;
#include <iostream>;

int main(){
    setlocale(LC_ALL, "rus");

    double x, y, f, res;
    int func_type;

    std::cout << "Введите x: "; std::cin >> x;
    std::cout << "Введите y: "; std::cin >> y;
    std::cout << "Введите f: 1 - sh(x); 2 - x^2; 3 - e^x" << std::endl; 
    std::cin >> func_type; 

    switch (func_type) {
        case 1:
            f = sinh(x);
            break;
        case 2:
            f = pow(x, 2);
            break;
        case 3:
            f = exp(x);
            break;
        
        default:
            std::cout << "Не выбрана функция. Попробуйте еще раз.";
            return 1;
    }

    if (x * y > 0) {
        res = tan(f) + x / cbrt(y);
    }
    else if(x * y < 0){
        res = fabs(log(pow(f,2) * y));
    }
    else {
        res = pow(f, 2) + pow(sin(y), 2);
    }

    std::cout << "Результат - " << std::setprecision(4) << res << std::endl;
}