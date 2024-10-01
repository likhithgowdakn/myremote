#include <stdio.h>
#include <string.h>

#define MAX_NAMES 100
#define MAX_LENGTH 50

int binarySearch(char names[][MAX_LENGTH], int n, const char *target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int cmp = strcmp(names[mid], target);

        if (cmp == 0) {
            return mid; // Name found
        } else if (cmp < 0) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }

    return -1; // Name not found
}

int main() {
    char names[MAX_NAMES][MAX_LENGTH];
    int n;

    printf("Enter the number of names: ");
    scanf("%d", &n);
    getchar(); // To consume the newline character left by scanf

    printf("Enter %d names (in sorted order):\n", n);
    for (int i = 0; i < n; i++) {
        fgets(names[i], MAX_LENGTH, stdin);
        names[i][strcspn(names[i], "\n")] = '\0'; // Remove the newline character
    }

    char target[MAX_LENGTH];
    printf("Enter the name to search: ");
    fgets(target, MAX_LENGTH, stdin);
    target[strcspn(target, "\n")] = '\0'; // Remove the newline character

    int result = binarySearch(names, n, target);
    if (result != -1) {
        printf("Name '%s' found at index %d.\n", target, result);
    } else {
        printf("Name '%s' not found in the list.\n", target);
    }

    return 0;
}
