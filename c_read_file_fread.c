#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    FILE *file;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    int repetitions = 1;

    // Parse the number of repetitions
    repetitions = atoi(argv[1]);

    // Repeat the read and log operation
    for (int i = 0; i < repetitions; i++)
    {
        // Open the file in read mode
        file = fopen("hello.txt", "r");

        // Check if the file exists and is opened successfully
        if (file == NULL)
        {
            fprintf(stderr, "Error: Could not open file 'hello.txt'\n");
            return 1;
        }

        // Read and log chunks of data from the file until EOF
        while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, file)) > 0)
        {
            fwrite(buffer, 1, bytesRead, stdout); // Output each chunk to the console
        }

        // Close the file
        fclose(file);
    }

    return 0;
}