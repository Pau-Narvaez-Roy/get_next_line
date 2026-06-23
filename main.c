/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnarvaez <pnarvaez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:42:47 by pnarvaez          #+#    #+#             */
/*   Updated: 2026/06/22 15:58:40 by pnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	fd;

	fd = argc;
	fd = open(argv[1], O_RDONLY);
	printf("Valor: %s\n", get_next_line(fd));
	printf("Valor: %s\n", get_next_line(fd));
	printf("Valor: %s\n", get_next_line(fd));
	return (0);
}
