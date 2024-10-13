#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int repeatations = atoi(argv[1]);

    int fd;
    struct stat sb;
    char *fileContent;

    for (int i = 0; i < repeatations; i++)
    {
        // Open the file
        fd = open("hello.txt", O_RDONLY);
        if (fd == -1)
        {
            perror("Error: Could not open file");
            return 1;
        }

        // Get the file size
        if (fstat(fd, &sb) == -1)
        {
            perror("Error: Could not get file size");
            close(fd);
            return 1;
        }

        // Map the file into memory
        fileContent = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
        if (fileContent == MAP_FAILED)
        {
            perror("Error: Could not map file");
            close(fd);
            return 1;
        }

        // Output the file content to the console
        fwrite(fileContent, 1, sb.st_size, stdout);

        // Unmap the file and close the file descriptor
        munmap(fileContent, sb.st_size);
        close(fd);
    }

    return 0;
}