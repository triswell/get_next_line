/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpou-ale <tpou-ale@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:46:42 by tpou-ale          #+#    #+#             */
/*   Updated: 2022/01/25 17:46:45 by tpou-ale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# define MAX_FD 1024

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

size_t	ft_strlen(const char *s);

char	*ft_strchr(const char *s, int c);

void	*ft_calloc(size_t count, size_t size);

char	*ft_strdup(const char *s1);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*get_next_line(int fd);

char	*ft_get_line(char **map);

#endif //GET_NEXT_LINE_BONUS_H