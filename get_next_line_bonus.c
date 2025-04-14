/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhallaf <ekhallaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 01:39:14 by ekhallaf          #+#    #+#             */
/*   Updated: 2024/12/13 00:08:34 by ekhallaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s, len + 1);
	return (ptr);
}

char	*read_buffer(int fd, char *store)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(store, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(buffer);
			free(store);
			return (NULL);
		}
		if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		store = ft_strjoin(store, buffer);
	}
	free(buffer);
	return (store);
}

char	*extract_line(char *store)
{
	size_t	len;
	char	*line;

	if (!store || !store[0])
		return (NULL);
	if (!ft_strchr(store, '\n'))
		len = ft_strlen(store);
	else
		len = ft_strchr(store, '\n') - store + 1;
	line = ft_substr(store, 0, len);
	return (line);
}

char	*update_store(char *store)
{
	size_t	len;
	char	*updated_store;

	if (!ft_strchr(store, '\n'))
	{
		free(store);
		return (NULL);
	}
	len = ft_strchr(store, '\n') - store + 1;
	updated_store = ft_substr(store, len, ft_strlen(store) - len);
	free(store);
	return (updated_store);
}

char	*get_next_line(int fd)
{
	static char	*store[FD_MAX];
	char		*line;

	if (fd < 0 || FD_MAX > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	store[fd] = read_buffer(fd, store[fd]);
	if (!store[fd])
		return (NULL);
	line = extract_line(store[fd]);
	store[fd] = update_store(store[fd]);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("text.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	close(fd);
// 	return (0);
// }
