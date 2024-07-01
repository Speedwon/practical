#include <stdio.h>
#include <string.h>

int main() {
    double t1, t2, t3;
    char input[50];
    while (1) {
        printf("Введіть три значення (або 'exit' для завершення):\n");
        fgets(input, 50, stdin);
        if (strncmp(input, "exit", 4) == 0) {
            break;
        }
        sscanf(input, "%lf %lf %lf", &t1, &t2, &t3);
        // Загальна продуктивність трьох гостей
        double total_efficiency = (1.0 / t1) + (1.0 / t2) + (1.0 / t3);
        
        double time_to_eat = 1.0 / total_efficiency;
        
        printf("Час, необхідний для з'їдання пирогаs: %.2lf годин\n", time_to_eat);
    }

    return 0;
}