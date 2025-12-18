#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main() {
    char key;
    printf("Консольное фортепиано. '1' для выхода.\n");

    while (1) {
        if (_kbhit()) {
            key = getch();

            if (key == '1') {
                printf("\nВыход из программы.\n");
                break;
            }

            int freq = 0;
            switch (key) {
                // Малая октава
                case 'q': freq = 130; break; // До (C3)
                case 'w': freq = 139; break; // До-диез (C3#)
                case 'e': freq = 147; break; // Ре (D3)
                case 'r': freq = 156; break; // Ре-диез (D3#)
                case 't': freq = 165; break; // Ми (E3)
                case 'y': freq = 175; break; // Фа (F3)
                case 'u': freq = 185; break; // Фа-диез (F3#)
                case 'i': freq = 196; break; // Соль (G4)
                case 'o': freq = 207; break; // Соль-диез (G4#)
                case 'p': freq = 220; break; // Ля (A4)
                case '[': freq = 233; break; // Ля-диез (A4#)
                case ']': freq = 247; break; // Си (B4)

                // Первая октава
                case 'a': freq = 262; break; // До (C4)
                case 's': freq = 277; break; // До-диез (C4#)
                case 'd': freq = 294; break; // Ре (D4)
                case 'f': freq = 311; break; // Ре-диез (D4#)
                case 'g': freq = 330; break; // Ми (E4)
                case 'h': freq = 349; break; // Фа (F4)
                case 'j': freq = 370; break; // Фа-диез (F4#)
                case 'k': freq = 392; break; // Соль (G4)
                case 'l': freq = 415; break; // Соль-диез (G4#)
                case ';': freq = 440; break; // Ля (A4)
                case '9': freq = 466; break; // Ля-диез (A4#)
                case '0': freq = 494; break; // Си (B4)

                // Вторая октава
                case 'z': freq = 523; break; // До (C5)
                case 'x': freq = 554; break; // До-диез (C5#)
                case 'c': freq = 587; break; // Ре (D5)
                case 'v': freq = 622; break; // Ре-диез (D5#)
                case 'b': freq = 659; break; // Ми (E5)
                case 'n': freq = 698; break; // Фа (F5)
                case 'm': freq = 740; break; // Фа-диез (F5#)
                case ',': freq = 784; break; // Соль (G5)
                case '.': freq = 831; break; // Соль-диез (G5#)
                case '/': freq = 880; break; // Ля (A5)
                case '-': freq = 932; break; // Ля-диез (A5#)
                case '=': freq = 988; break; // Си (B5)

                default: continue;
            }
            
            Beep(freq, 120);
        }
    }

    return 0;
}
