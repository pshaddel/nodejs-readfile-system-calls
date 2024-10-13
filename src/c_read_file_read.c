#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;
    int repetitions = 1;

    // Parse the number of repetitions
    repetitions = atoi(argv[1]);

    // Repeat the read and log operation
    for (int i = 0; i < repetitions; i++)
    {
        // Open the file
        fd = open("hello.txt", O_RDONLY);
        if (fd == -1)
        {
            perror("Error: Could not open file 'hello.txt'");
            return 1;
        }
        // Reset the file descriptor to the beginning of the file
        if (lseek(fd, 0, SEEK_SET) == -1)
        {
            perror("Error: Could not reset file descriptor");
            close(fd);
            return 1;
        }

        // Read and log chunks of data from the file until EOF
        while ((bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0)
        {
            if (write(STDOUT_FILENO, buffer, bytesRead) == -1)
            {
                perror("Error: Could not write to stdout");
                close(fd);
                return 1;
            }
        }

        if (bytesRead == -1)
        {
            perror("Error: Could not read file");
            close(fd);
            return 1;
        }
        close(fd);
    }

    // Close the file descriptor

    return 0;
}