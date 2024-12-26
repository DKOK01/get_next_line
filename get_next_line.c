/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:30:04 by aysadeq           #+#    #+#             */
/*   Updated: 2024/12/26 14:20:15 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *buffer;
	int size_read;
	int	i;

	buffer = malloc(BUFFER_SIZE + 1);
	size_read = read(fd, buffer, BUFFER_SIZE);
	if (size_read == -1)
		return (NULL);
	i = 0;
	buffer[size_read] = '\0';
	while(buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	return (ft_substr(buffer, 0, i));
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
	char *line = get_next_line(fd);
	printf("%s\n", line);
	free(line);

	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	
	close(fd);
	return 0;
}
