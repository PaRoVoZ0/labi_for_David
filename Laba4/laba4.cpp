#include <iostream>

int main() {
    setlocale(LC_ALL, "rus");

    int arr_1[5], arr_2[5], s = 5, cnt_fact = 0, cnt_user;

    std::cout << "Введите кол-во минимальных элементов, которые не входят во второй массив (не больше 5): "; std::cin >> cnt_user;

    for (int i = 0; i < s; i++) {
        arr_1[i] = rand() % 10;
        arr_2[i] = rand() % 10;
    }

    std::cout << "Элементы первого массива: ";
    for (int i = 0; i < s; i++) {
        std::cout << arr_1[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Элементы второго массива: ";
    for (int i = 0; i < s; i++) {
        std::cout << arr_2[i] << " ";
    }
    std::cout << "\n";

    int temp_cnt = 0;
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            if (arr_1[i] != arr_2[j]) {
                temp_cnt++;
            }
        }

        if (temp_cnt == 5) {
            cnt_fact++;
            std::cout << "Найден мин элемент первого массива, не входящий во второй: " << arr_1[i] << "\n";
        }

        temp_cnt = 0;
    }

    if (cnt_fact == cnt_user) {
        std::cout << "Все круто! Количество элементов совпадает с введенным!!";
    }
    else {
        std::cout << "Все плёха :( ! Количество элементов не совпадает с введенным (" << cnt_fact << ")";
    }
}
