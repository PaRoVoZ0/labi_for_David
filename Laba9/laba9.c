#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#define KEY_COUNT 9
#define SHORT_BEEP 200
#define LONG_BEEP 1000
#define FREQUENCY 1000

const char keys[KEY_COUNT] = {'Q', 'W', 'E', 'A', 'S', 'D', 'Z', 'X', 'C'};
int pressed[KEY_COUNT] = {0};
int bomb_index; 

void beep_signal(int duration_ms) {
    Beep(FREQUENCY, duration_ms);
}

void process_key(char key) {
    int i;
    
    for (i = 0; i < KEY_COUNT; i++) {
        if (keys[i] == key) {
            if (i == bomb_index) {
                printf("\nБОМБА! Игра окончена.\n");
                beep_signal(LONG_BEEP);
                exit(0);
            } else if (!pressed[i]) {
                pressed[i] = 1;
                printf("%c ", key);
                return;
            }
            break;
        }
    }
}

int all_non_bomb_pressed() {
    for (int i = 0; i < KEY_COUNT; i++) {
        if (i != bomb_index && !pressed[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char ch;
    
    // Инициализация генератора случайных чисел
    srand(time(NULL));
    
    // Выбор случайной "бомбы"
    bomb_index = rand() % KEY_COUNT;
    
    printf("========================================\n");
    printf("      ИГРА: НАЙДИ БОМБУ\n");
    printf("========================================\n");
    printf("Нажмите все клавиши Q W E A S D Z X C,\n");
    printf("кроме одной, которая является БОМБОЙ\n");
    printf("========================================\n");
    printf("Нажимайте клавиши...\n\n");
    
    while (1){
        ch = _getch();
        ch = toupper(ch);
        
        process_key(ch);
        
        if (all_non_bomb_pressed()) {
            printf("\n\nПОБЕДА! Все безопасные клавиши нажаты!\n");

            for (int i = 0; i < 3; i++) {
                beep_signal(SHORT_BEEP);
                Sleep(100); 
            }
            break;
        }
    }
    
    printf("Нажмите любую клавишу для выхода...");
    _getch();
}