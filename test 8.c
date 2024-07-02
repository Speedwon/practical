#include <stdio.h>
#include <string.h>

// Функція для обчислення факторіалу
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Функція для обчислення кількості анаграм
unsigned long long count_anagrams(char *word) {
    int length = strlen(word);
    unsigned long long total_anagrams = factorial(length);
    
    // Масив для підрахунку кількості кожної літери
    int letter_counts[256] = {0};
    
    for (int i = 0; i < length; i++) {
        letter_counts[(int)word[i]]++;
    }
    
    for (int i = 0; i < 256; i++) {
        if (letter_counts[i] > 1) {
            total_anagrams /= factorial(letter_counts[i]);
        }
    }
    
    return total_anagrams;
}

int main() {
    char word[15];
    printf("Введіть слово: ");
    scanf("%14s", word);
    
    unsigned long long result = count_anagrams(word);
    printf("Кількість можливих анаграм: %llu\n", result);
    
    return 0;
}
