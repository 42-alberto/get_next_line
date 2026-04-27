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

char	*ft_create_line(char **residue)
{
	unsigned int	residue_len;
	unsigned int	line_len;
	char			*line;
	int				i;

	residue_len = ft_strlen(*residue);
	line_len = ft_find_end_of_line(*residue);
	if (line_len == 0)
		line_len = residue_len;
	line = ft_substr(*residue, 0, line_len);
	if (line == NULL)
		return (ft_free_all(residue, NULL));
	if (line_len < residue_len)
	{
		i = 0;
		while ((*residue)[line_len + i])
		{
			(*residue)[i] = (*residue)[line_len + i];
			i++;
		}
		(*residue)[i] = '\0';
	}
	else
		ft_free_all(residue, NULL);
	return (line);
}

char	*ft_free_all(char **residue, char *buffer)
{
	free (buffer);
	free (*residue);
	*residue = NULL;
	return (NULL);
}

int	ft_fill_residue(char **residue, char *buffer, size_t *resid_buffer_len)
{
	char	*temp;

	if (!*residue)
	{
		*residue = malloc(*resid_buffer_len + 1);
		if (!*residue)
			return (0);
		(*residue)[0] = '\0';
	}
	if (*resid_buffer_len > ft_strlen(*residue) + ft_strlen(buffer))
		return (ft_strlcat_gnl(*residue, buffer), 1);
	while (*resid_buffer_len <= ft_strlen(*residue) + ft_strlen(buffer))
		*resid_buffer_len *= 2;
	temp = malloc(*resid_buffer_len + 1);
	if (!temp)
		return (0);
	temp[0] = '\0';
	ft_strlcat_gnl(temp, *residue);
	ft_strlcat_gnl(temp, buffer);
	free (*residue);
	*residue = temp;
	return (1);
}

int	ft_find_end_of_line(char *residue)
{
	int	i;

	i = 0;
	if (!residue)
		return (0);
	while (residue[i])
	{
		if (residue[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*residue[1024];
	char		*buffer;
	int			characters_read;
	size_t		resid_buffer_len;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_free_all(&residue[fd], buffer));
	resid_buffer_len = 256;
	while (!ft_find_end_of_line(residue[fd]))
	{
		characters_read = read(fd, buffer, BUFFER_SIZE);
		if (characters_read == -1)
			return (ft_free_all(&residue[fd], buffer));
		buffer[characters_read] = '\0';
		if (!ft_fill_residue(&residue[fd], buffer, &resid_buffer_len))
			return (ft_free_all(&residue[fd], buffer));
		if (characters_read < BUFFER_SIZE || ft_find_end_of_line(residue[fd]))
			break ;
	}
	if (!residue[fd] || residue[fd][0] == '\0')
		return (ft_free_all(&residue[fd], buffer));
	return (free (buffer), ft_create_line(&residue[fd]));
}
