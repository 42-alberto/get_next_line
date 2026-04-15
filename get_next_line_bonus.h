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

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

/* Librerías necesarias para usar malloc, free, read, size_t, etc. */
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

/* BUFFER_SIZE debe definirse en la compilación */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_create_line(char **line, char **residue);
char	*ft_free_all(char **residue, char *buffer);
int		ft_fill_residue(char **residue, char *buffer);
int		ft_find_end_of_line(char *residue);

/* Prototipos de funciones auxiliares de libft*/
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dsize);
size_t	ft_strlen(const char *c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif