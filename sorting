#include <stdio.h>
#include <string.h>
#define MAX 100

void sort(char names[][50], int count, int asc) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if ((asc && strcmp(names[i], names[j]) > 0) || (!asc && strcmp(names[i], names[j]) < 0)) {
                char temp[50];
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }
    for (int i = 0; i < count; i++) printf("%s\n", names[i]);
}

int countNames(int count) { return count; }

int main() {
    char names[MAX][50] = {"Alice", "Bob", "Charlie", "David", "Eve"};
    int count = 5, choice;
    printf("1. Sort Names\n2. Count Names\nChoose: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        char order[5];
        printf("Order (asc/desc): ");
        scanf("%s", order);
        sort(names, count, strcmp(order, "asc") == 0);
    } else if (choice == 2) {
        printf("Total: %d\n", countNames(count));
    } else printf("Invalid choice!\n");
    
    return 0;
}

