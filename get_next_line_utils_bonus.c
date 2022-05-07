/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpou-ale <tpou-ale@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:46:18 by tpou-ale          #+#    #+#             */
/*   Updated: 2022/01/25 17:46:29 by tpou-ale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (const char)c)
		++s;
	if (*s == (const char)c)
		return ((char *)s);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (ptr);
	i = 0;
	while (i < count * size)
		((char *)ptr)[i++] = 0;
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s1);
	ptr = (char *)malloc(len + 1);
	if (ptr == NULL)
		return (ptr);
	ft_strlcpy(ptr, s1, len + 1);
	return (ptr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	
	i = 0;
	while (dstsize && src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		++i;
	}
	if (i < dstsize)
		dst[i] = 0;
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(len1 + len2 + 1);
	if (str == NULL)
		return (str);
	ft_strlcpy(str, s1, len1 + 1);
	ft_strlcpy(str + len1, s2, len2 + 1);
	return (str);
}