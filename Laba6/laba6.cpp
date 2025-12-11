#include <iostream>
#include <string>

int main(){
    setlocale(LC_ALL,"rus");

    std::string text;
    std::cout << "Введите текст: ";
    std::getline(std::cin, text);

    text += ' ';

    int word_count = 0;
    for (size_t i = 0; i < text.length(); i++) {
        if (text[i] == ' ' && text[i - 1] != ' ' && i > 0) {
            word_count++;
        }
    }

    if (word_count == 0) {
        std::cout << "Слов нет!" << std::endl;
        return 0;
    }

    std::string* words = new std::string[word_count];
    int current_word = 0;
    std::string temp = "";

    for (unsigned int i = 0; i < text.length(); i++) {
        if (text[i] != ' ') {
            temp += text[i];
        } else if (!temp.empty()) {
            words[current_word++] = temp;
            temp = "";
        }
    }

    for (int i = 0; i < word_count - 1; i++) {
        for (int j = 0; j < word_count - i - 1; j++) {
            if (words[j] > words[j + 1]) {
                std::string swap_temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = swap_temp;
            }
        }
    }

    std::cout << "Слова в алфавитом порядке:" << std::endl;
    for (int i = 0; i < word_count; i++) {
        std::cout << words[i] << std::endl;
    }

    delete[] words;
}