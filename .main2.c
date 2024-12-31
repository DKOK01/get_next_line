#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line_bonus.h"

int main(void)
{
    int fd1 = open("text.txt", O_RDONLY);
    int fd2 = open("text1.txt", O_RDONLY);
    char *line;

    if (fd1 < 0 || fd2 < 0)
    {
        perror("Error opening files");
        return (1);
    }

    printf("Reading from text.txt:\n");
    line = get_next_line(fd1);
    printf("%s", line);
    free(line);

    printf("Reading from text1.txt:\n");
    line = get_next_line(fd2);
    printf("%s", line);
    free(line);

    printf("Reading another line from text.txt:\n");
    line = get_next_line(fd1);
    printf("%s", line);
    free(line);

    close(fd1);
    close(fd2);
    return (0);
}
