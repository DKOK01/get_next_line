#include <fcntl.h>  // For open
#include <stdio.h>  // For printf, perror
#include <stdlib.h> // For malloc, free
#include <unistd.h>

char *get_next_line(int fd);

int main()
{
    int fd;
    char *line;

	fd = open("text.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file text.txt");
        return 1;
    }
    printf("Test Case 1: Reading from text.txt\n");
    // while ((line = get_next_line(fd)) != NULL)
    // {
    //     printf("LINE: %s", line);
    //     free(line);
    // }
	line = get_next_line(fd);
	printf("LINE: %s", line);
    free(line);

	line = get_next_line(42);
	printf("LINE: %s", line);
    free(line);

	line = get_next_line(fd);
	printf("LINE: %s", line);
    free(line);

	line = get_next_line(42);
	printf("LINE: %s", line);
    free(line);
	close(fd);

    return 0;
}
