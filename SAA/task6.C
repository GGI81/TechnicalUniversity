// Даден е едномерен масив с n елемента. 
// Да се напише програма, която намира броя на намаляващите редици от елементи в масива, 
// тяхната дължина и най-дългата от тях.

#include <stdio.h>

int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);

    int a[100];

    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    int lengths[100];
    int count = 0;
    int currentLen = 1;
    int maxLen = 1;

    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            currentLen++;
        } else {
            if (currentLen > 1) {
                lengths[count] = currentLen;
                count++;
                if (currentLen > maxLen)
                    maxLen = currentLen;
            }
            currentLen = 1;
        }
    }

    if (currentLen > 1) {
        lengths[count] = currentLen;
        count++;
        if (currentLen > maxLen)
            maxLen = currentLen;
    }
    else {
        maxLen = 0;
    }

    printf("\nБрой намаляващи редици: %d\n", count);

    printf("Дължини на редиците: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", lengths[i]);
    }

    printf("\nНай-дълга редица: %d\n", maxLen);

    return 0;
}