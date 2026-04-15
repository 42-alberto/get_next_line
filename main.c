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

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

/*
* El bonus y el obligatorio son exactamente iguales puedes compilar uno solo.
* Compilar:
* gcc -Wall -Wextra -Werror -D BUFFER_SIZE=3 main.c get_next_line.c 
* get_next_line_utils.c
* Ejecutar:
* valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out
*/

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line1;
	char	*line2;
	int		i;

	i = 1;
	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	if (fd1 == -1 || fd2 == -1)
		return (1);
	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	while (line1 || line2)
	{
		if (line1)
		{
			printf("fd1 line %d-> %s", i, line1);
			free (line1);
			line1 = get_next_line(fd1);
		}
		if (line2)
		{
			printf("fd2 line %d-> %s", i, line2);
			free (line2);
			line2 = get_next_line(fd2);
			close(fd2);
		}
		i++;
	}
	printf("\n");
	close(fd1);
	close(fd2);
	return (0);
}
