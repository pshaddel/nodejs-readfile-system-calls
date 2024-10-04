#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char ch;

    // Open the file in read mode
    file = fopen("hello.txt", "r");

    // Check if the file exists and is opened successfully
    if (file == NULL) {
        printf("Error: Could not open file 'hello.txt'\n");
        return 1;
    }

    // Read and log each character from the file until EOF
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);  // Output each character to the console
    }

    // Close the file
    fclose(file);

    return 0;
}
