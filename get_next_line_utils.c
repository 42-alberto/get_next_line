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

#include "get_next_line.h"

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*dst;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (((size_t) - 1) - s1_len - 1 < s2_len)
		return (NULL);
	dst = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (dst == NULL)
		return (NULL);
	j = 0;
	i = 0;
	while (i < s1_len)
		dst[j++] = s1[i++];
	i = 0;
	while (i < s2_len)
		dst[j++] = s2[i++];
	dst[j] = '\0';
	return (dst);
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
	size_t	i;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen (s);
	if (len < s_len - start)
		substr_len = len;
	else
		substr_len = s_len - start;
	substr = malloc (sizeof(char) * (substr_len + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] && i < substr_len)
	{
		substr [i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
