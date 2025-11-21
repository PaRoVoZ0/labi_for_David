#include <iostream>

int main(){
    setlocale(LC_ALL, "rus");

    int arr_1[5], arr_2[5], s = 5, cnt = 0, res[5];

    std::cout << "Введите элементы превого массива:" << "\n";
    for (int i = 0; i < s; i++){
        std::cin >> arr_1[i];
    }

    std::cout << "Введите элементы второго массива:" << "\n";
    for (int i = 0; i < s; i++){
        std::cin >> arr_2[i];
    }

    int temp_cnt = 0;
    for (int i = 0; i < s; i++){
        for (int j = 0; j < s; j++){
            if (arr_1[i] != arr_2[j]){
                temp_cnt++;
            }
        }

        if (temp_cnt == 5){
            res[i] = arr_1[i];
            cnt++;
        }

        temp_cnt = 0;
    }

    std::cout << "Результат - ";
    for (int i = 0; i < cnt; i++) std::cout << res[i] << " ";
}
