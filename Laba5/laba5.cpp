#include <iostream>

int main(){
    setlocale(LC_ALL, "rus");

    int N, M;

    std::cout << "Введите кол-во строк: "; std::cin >> N;
    std::cout << "Введите кол-во столбцов: "; std::cin >> M;

    int **matr;
    matr = new int *[N];

    for (int i = 0; i < N; i++){
        matr[i] = new int[M];
    }

    for (int i = 0; i < N; i++){
        std::cout << "Введите элементы строки " << i + 1 << ":" << "\n";

        for (int j = 0; j < M; j++){
            std::cin >> matr[i][j];
        }
    }

    bool found_saddle = false;

    // Наименьшее в строке && наибольшее в столбце
    for (int i = 0; i < N; i++){
        int min_in_row = matr[i][0];
        for (int j = 0; j < M; j++){
            if (matr[i][j] < min_in_row){
                min_in_row = matr[i][j];
            }
        }

        for (int j = 0; j < M; ++j) {
            if (matr[i][j] == min_in_row) {
                bool is_max_in_col = true;

                for (int k = 0; k < N; ++k) {
                    if (matr[k][j] > matr[i][j]) {
                        is_max_in_col = false;
                        break;
                    }
                }

                if (is_max_in_col) {
                    std::cout << "Седловая точка: [" << i << "][" << j << "] = " << matr[i][j] << "\n";

                    found_saddle = true;
                }
            }
        }
    }

    // Наибольшее в строке && наименьшее в столбце
    for (int i = 0; i < N; i++){
        int max_in_row = matr[i][0];
        for (int j = 0; j < M; j++){
            if (matr[i][j] > max_in_row){
                max_in_row = matr[i][j];
            }
        }

        for (int j = 0; j < M; ++j) {
            if (matr[i][j] == max_in_row) {
                bool is_min_in_col = false;

                for (int k = 0; k < N; ++k) {
                    if (matr[k][j] > matr[i][j]) {
                        is_min_in_col = true;
                        break;
                    }
                }

                if (is_min_in_col == true) {
                    std::cout << "Седловая точка: [" << i << "][" << j << "] = " << matr[i][j] << "\n";

                    found_saddle = true;
                }
            }
        }
    }

    if (!found_saddle) {
        std::cout << "Седловых точек нет." << std::endl;
    }

    // Освобождение памяти
    for (int i = 0; i < N; ++i) {
        delete[] matr[i];
    }
    delete[] matr;
} 