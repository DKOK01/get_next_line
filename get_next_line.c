/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:30:04 by aysadeq           #+#    #+#             */
/*   Updated: 2024/12/28 13:09:55 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *extract_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (buffer[i] == '\0')
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	line = malloc(i + 2);
	if (!line)
		return(NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}
char	*cut_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return(NULL);
	}
	new_buffer = malloc(ft_strlen(buffer) - i + 1);
	if (!new_buffer)
		return(NULL);
	i++;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	free(buffer);
	return(new_buffer);
}


char *get_next_line(int fd)
{
	static char	*buffer;
	int			size_read;
	char		temp[BUFFER_SIZE + 1];
	char		*line;

	if (!buffer)
		buffer = ft_strdup("");
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while ((size_read = read(fd, temp, BUFFER_SIZE)) > 0)
    {
        temp[size_read] = '\0';
        buffer = ft_strjoin(buffer, temp);
        if (ft_strchr(buffer, '\n'))
            break;
    }
	line = extract_line(buffer);
	buffer = cut_buffer(buffer);
	return (line);
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

	char *line;
	printf("%s", line = get_next_line(fd));
	free(line);

	close(fd);
	return 0;
}
