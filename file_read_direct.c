#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main()
{
    int fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    // Open the file
    fd = open("hello.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error: Could not open file 'hello.txt'");
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
    }

    // Close the file descriptor
    close(fd);

    return 0;
}