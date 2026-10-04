#include <stdio.h>
#include "validation.h"

void clearInputBuffer(void) {
    while (getchar() != '\n');
}

int getValidIntOption(int min, int max) {
    int choice;
    while (1) {
        printf("Enter choice (%d-%d): ", min, max);
        if (scanf("%d", &choice) == 1 && choice >= min && choice <= max) {
            clearInputBuffer();
            return choice;
        } else {
            printf("Invalid input! Please enter a valid number.\n");
            clearInputBuffer();
        }
    }
}