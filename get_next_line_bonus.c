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

char	*ft_create_line(char **line, char **residue)
{
	unsigned int	residue_len;
	unsigned int	line_len;
	char			*temp;

	residue_len = ft_strlen(*residue);
	line_len = ft_find_end_of_line(*residue);
	if (line_len == 0)
		line_len = residue_len;
	*line = ft_substr(*residue, 0, line_len);
	if (*line == NULL)
		return (ft_free_all(residue, NULL));
	if (line_len < residue_len)
	{
		temp = ft_substr(*residue, line_len, residue_len - line_len);
		free(*residue);
		*residue = temp;
	}
	else
	{
		free (*residue);
		*residue = NULL;
	}
	return (*line);
}

char	*ft_free_all(char **residue, char *buffer)
{
	free (buffer);
	free (*residue);
	*residue = NULL;
	return (NULL);
}

int	ft_fill_residue(char **residue, char *buffer)
{
	char	*temp;

	if (!*residue)
	{
		*residue = malloc(1);
		if (!*residue)
			return (0);
		(*residue)[0] = '\0';
	}
	temp = ft_strjoin_gnl(*residue, buffer);
	if (temp == NULL)
		return (0);
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
	char		*line;
	char		*buffer;
	int			characters_read;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (ft_free_all(&residue[fd], NULL));
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_free_all(&residue[fd], buffer));
	while (!ft_find_end_of_line(residue[fd]))
	{
		characters_read = read(fd, buffer, BUFFER_SIZE);
		if (characters_read == -1)
			return (ft_free_all(&residue[fd], buffer));
		buffer[characters_read] = '\0';
		if (!ft_fill_residue(&residue[fd], buffer))
			return (ft_free_all(&residue[fd], buffer));
		if (characters_read < BUFFER_SIZE || ft_find_end_of_line(residue[fd]))
			break ;
	}
	if (!residue[fd] || residue[fd][0] == '\0')
		return (ft_free_all(&residue[fd], buffer));
	free (buffer);
	return (ft_create_line(&line, &residue[fd]));
}
