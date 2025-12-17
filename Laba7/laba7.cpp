#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main(){
    setlocale(LC_ALL, "rus");

    struct statement{
        std::string last_name;
        std::string first_name;
        std::string patronymic;

        std::string city;

        float estimation;
    };

    statement student1 {"Зубенко", "Михаил", "Петрович", "Шумиловский городок", 2.28};
    statement student2 {"Айбибек", "Нуркек", "Мембетович", "Читобэлятаун", 4.67};
    statement student3 {"Попадинец", "Евгений", "Владимирович", "Николаевка", 4.82};
    statement student4 {"Путин", "Владимир", "Владимирович", "Ленинград", 5.55};
    statement student5 {"Никитин", "Давид", "Дмитриевич", "Четкий город", 5.0};
    statement student6 {"Пушкин", "Максчорт", "Хзкович", "Краснодар", 4.69};
    statement student7 {"Лукашенко", "Александр", "Григорьевич", "Минск", 4.66};
    statement student8 {"Отличный", "Отличник", "Из-Минскович", "Минск", 4.5};
    statement student9 {"Тот-Самый", "Ян", "Топлес", "Минск", 4.39};
    statement student10 {"СЦП-096", "Скромник", "Долговязович", "СЦП-Даболатория", 0.96};

    statement list[10] = {student1, student2, student3, student4, student5, student6, student7, student8, student9, student10};

    std::string city_check = "Минск";
    float estim_check = 4.5;

    std::vector<std::string> good_students;

    for (int i = 0; i < 10; i++) {
        if (list[i].city == city_check && list[i].estimation >= estim_check) {
            good_students.push_back(list[i].last_name);
        }
    }

    std::sort(good_students.begin(), good_students.end());

    for (size_t i = 0; i < good_students.size(); i++) {
        std::cout << good_students[i] << std::endl;
    }
}