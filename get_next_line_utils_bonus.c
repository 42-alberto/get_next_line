/* ************************************************************************** */
/*                                                                            */
/*    /\_/\                                               :::      ::::::::   */
/*   ( o.o )   "Dejando de ser anal-fabeto,             :+:      :+:    :+:   */
/*    > ^ <         ¿Qué me recomiendas leer?"        +:+ +:+         +:+     */
/*   By: Me                                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0003/01/01 00:00:01 by Me                #+#    #+#             */
/*   Updated: 0003/01/01 00:00:02 by Me               ###   ########.fr       */
/*                                                                     librito*/
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	dsts1s2_len;
	char	*dst_s1s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (((size_t) - 1) - s1_len - 1 < s2_len)
		return (NULL);
	dsts1s2_len = s1_len + s2_len;
	dst_s1s2 = malloc(sizeof(char) * (dsts1s2_len + 1));
	if (dst_s1s2 == NULL)
		return (NULL);
	ft_strlcpy (dst_s1s2, s1, dsts1s2_len + 1);
	ft_strlcat (dst_s1s2, s2, dsts1s2_len + 1);
	return (dst_s1s2);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	i_src;

	dst_len = 0;
	src_len = ft_strlen (src);
	i = 0;
	i_src = 0;
	while (dst[i] && i < dsize)
	{
		i++;
		dst_len = i;
	}
	if (dsize > dst_len)
	{
		while (src[i_src] && i < dsize - 1)
			dst [i++] = src[i_src++];
		dst [i] = '\0';
		return (dst_len + src_len);
	}
	return (dsize + src_len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	i;

	i = 0;
	if (dsize > 0)
	{
		while (src[i] && i < dsize - 1)
		{
			dst [i] = src [i];
			i++;
		}
		dst [i] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlen(const char *c)
{
	size_t	count;

	count = 0;
	while (c[count])
		count++;
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	substr_len;
	char	*substr;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen (s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len < s_len - start)
		substr_len = len;
	else
		substr_len = s_len - start;
	substr = malloc (sizeof(char) * (substr_len + 1));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, substr_len + 1);
	return (substr);
}

char	*ft_strdup(const char *s)
{
	size_t	s_len;
	char	*s_dup;

	s_len = ft_strlen(s);
	s_dup = malloc(s_len + 1);
	if (s_dup == NULL)
		return (NULL);
	ft_memcpy(s_dup, s, s_len + 1);
	return (s_dup);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned const char *)src;
	while (n-- > 0)
		*d++ = *s++;
	return (dest);
}
