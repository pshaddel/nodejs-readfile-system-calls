#include <stdio.h>
#include <stdlib.h>
#include <uv.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

// Forward declaration of the on_open function
void on_open(uv_fs_t *req);

// Buffer to store the file content
char buffer[BUFFER_SIZE];
int repetitions = 1;
int current_read = 0;

// Callback when the file read is completed
void on_read(uv_fs_t *req)
{
    if (req->result < 0)
    {
        fprintf(stderr, "Read error: %s\n", uv_strerror((int)req->result));
    }
    else if (req->result == 0)
    {
        // End of file reached
        printf("Read complete.\n");
    }
    else
    {
        // Print the content read
        printf("%s", buffer);
    }

    // Clean up read request
    uv_fs_req_cleanup(req);
    free(req);

    // Check if we need to read the file again
    if (++current_read < repetitions)
    {
        uv_fs_t *open_req = (uv_fs_t *)malloc(sizeof(uv_fs_t));
        uv_fs_open(uv_default_loop(), open_req, "hello.txt", O_RDONLY, 0, on_open);
    }
}

// Callback when the file is opened
void on_open(uv_fs_t *req)
{
    if (req->result < 0)
    {
        fprintf(stderr, "Error opening file: %s\n", uv_strerror((int)req->result));
        free(req);
        return;
    }

    int file = (int)req->result;
    uv_fs_t *read_req = (uv_fs_t *)malloc(sizeof(uv_fs_t));
    uv_buf_t iov = uv_buf_init(buffer, sizeof(buffer));

    // Read the file
    uv_fs_read(uv_default_loop(), read_req, file, &iov, 1, -1, on_read);

    // Clean up open request
    uv_fs_req_cleanup(req);
    free(req);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <repetitions>\n", argv[0]);
        return 1;
    }

    // Parse the number of repetitions
    repetitions = atoi(argv[1]);
    if (repetitions <= 0)
    {
        fprintf(stderr, "Error: Repetitions must be a positive integer\n");
        return 1;
    }

    uv_loop_t *loop = uv_default_loop();
    uv_fs_t *open_req = (uv_fs_t *)malloc(sizeof(uv_fs_t));

    // Open the file hello.txt
    uv_fs_open(loop, open_req, "hello.txt", O_RDONLY, 0, on_open);

    // Run the event loop
    uv_run(loop, UV_RUN_DEFAULT);

    return 0;
}