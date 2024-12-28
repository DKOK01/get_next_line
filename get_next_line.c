/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:30:04 by aysadeq           #+#    #+#             */
/*   Updated: 2024/12/28 09:38:04 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *buffer;
	int size_read;
	int	i;
	char *line;

	i = 0;
	buffer = malloc(BUFFER_SIZE + 1);
	while (1)
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read == -1)
			return (NULL);
		buffer[size_read + 1] = '\0';
		while(buffer[i] != '\n' && buffer[i] != '\0')
			i++;
		




	}

}
void	call_get(int	fd)
{
	char *line;
	printf("%s", line = get_next_line(fd));
	free(line);
}

int main()
{
	int	fd;
	fd = open("text.txt", O_RDONLY);

	if (fd == -1)
	{
		perror("Error opening file");
		return 1;
	}

	call_get(fd);
	//call_get(fd);






	// char *line;
	// printf("%s", line = get_next_line(fd));
	// free(line);

	// printf("%s", line = get_next_line(fd));
	// free(line);

	close(fd);
	return 0;
}
