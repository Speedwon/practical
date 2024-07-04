#include <stdio.h>

// Функція для обчислення кількості чисел із р розрядів
int countNumbers(int p) {
    if (p == 1) return 2; 
    int dp[p+1][4];
    
    // Початкові значення для одного розряду
    dp[1][0] = 1;  // тільки 5
    dp[1][1] = 1;  // тільки 9
    dp[1][2] = 0;  // неможливо
    dp[1][3] = 0;  // неможливо

    for (int i = 2; i <= p; i++) {
        dp[i][0] = dp[i-1][1] + dp[i-1][3];
        dp[i][1] = dp[i-1][0] + dp[i-1][2];
        dp[i][2] = dp[i-1][0];
        dp[i][3] = dp[i-1][1];
    }

    return dp[p][0] + dp[p][1] + dp[p][2] + dp[p][3];
}

int main() {
    int p;
    printf("Введіть кількість розрядів p: ");
    scanf("%d", &p);
    
    if (p <= 0 || p > 30) {
        printf("Невірне значення p. Введіть число від 1 до 30.\n");
        return 1;
    }
    int result = countNumbers(p);
    printf("Кількість чисел із %d розрядів: %d\n", p, result);

    return 0;
}
