#include <stdio.h>
#include <stdlib.h>

// Function to convert a string to an integer
int myAtoi(char* str) {
    int res = 0; // Initialize result

    // Iterate through all characters of input string and update result
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            res = res * 10 + str[i] - '0';
        }
    }

    return res;
}

int main() {
    FILE *fp;
    char line[100];
    int sum = 0;

    // Open the file
    fp = fopen("in.txt", "r");

    // Check if file opened successfully
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read each line from the file and calculate sum
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Convert the line to integer and add it to sum
        sum += myAtoi(line);
    }

    // Close the file
    fclose(fp);

    // Print the sum
    printf("Sum of numbers in the file: %d\n", sum);

    return 0;
}

