#include <stdio.h>
// Функція обчислення мінімальної кількості кроків
int minSteps(int x, int y) {
    if (x == y) {
        return 0;
    }
    
    int distance = y - x;
    int steps = 0;
    int step_length = 1;
    int current_distance = 0;

    while (current_distance < distance) {
        steps++;
        current_distance += step_length;
        if (current_distance >= distance) {
            break;
        }
        
        steps++;
        current_distance += step_length;
        
        if (current_distance >= distance) {
            break;
        }
        
        step_length++;
    }
    
    return steps;
}
int main() {
    int x1 = 44, y1 = 49;
    int x2 = 45, y2 = 49;
    int x3 = 45, y3 = 50;
    int x4 = 45, y4 = 51;

    printf("Мінімальна кількість кроків від %d до %d: %d\n", x1, y1, minSteps(x1, y1));
    printf("Мінімальна кількість кроків від %d до %d: %d\n", x2, y2, minSteps(x2, y2));
    printf("Мінімальна кількість кроків від %d до %d: %d\n", x3, y3, minSteps(x3, y3));
    printf("Мінімальна кількість кроків від %d до %d: %d\n", x4, y4, minSteps(x4, y4));

    return 0;
}