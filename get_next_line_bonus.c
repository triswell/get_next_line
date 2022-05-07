/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpou-ale <tpou-ale@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:45:56 by tpou-ale          #+#    #+#             */
/*   Updated: 2022/01/25 17:46:01 by tpou-ale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;
	
	i = 0;
	while (*s++)
		++i;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	if (start < 0 || start > ft_strlen(s))
		return (ft_strdup(""));
	s_len = ft_strlen(s);
	if (s_len - start < len)
		len = s_len - start;
	substr = (char *)ft_calloc(len * (s_len && s_len > start) + 1, 1);
	if (substr == NULL)
		return (substr);
	ft_strlcpy(substr, s + start, len * (s_len && s_len > start) + 1);
	return (substr);
}

char	*ft_get_line(char **map)
{
	char	*line;
	char	*buff;

	if (!*map || !**map)
		return (NULL);
	if (!ft_strchr(*map, '\n'))
	{
		line = ft_strdup(*map);
		free(*map);
		*map = NULL;
		return (line);
	}
	line = ft_substr(*map, 0, ft_strchr(*map, '\n') - *map + 1);
	if (!line)
		return (line);
	buff = ft_substr(*map, ft_strchr(*map, '\n') - *map + 1, ft_strlen(*map));
	if (!ft_strlen(buff))
	{
		free(buff);
		buff = NULL;
	}
	free(*map);
	*map = buff;
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*map[MAX_FD + 1];
	char			*line;
	char			*buff;
	ssize_t			size;

	if (BUFFER_SIZE < 0 || fd < 0 || fd > MAX_FD)
		return (NULL);
	buff = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buff)
		return (NULL);
	size = read(fd, buff, BUFFER_SIZE);
	while (size > 0)
	{
		buff[size] = '\0';
		line = ft_strjoin(map[fd], buff);
		if (map[fd])
			free(map[fd]);
		map[fd] = line;
		if (ft_strchr(map[fd], '\n'))
			break;
		size = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (ft_get_line(&map[fd]));
}