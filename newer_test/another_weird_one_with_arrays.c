/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_weird_one_with_arrays.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:22:52 by akuburas          #+#    #+#             */
/*   Updated: 2024/05/30 15:39:07 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

void	the_original(void)
{
	int	original[5] = {1, 2, 3, 4, 5};
	int	i;

	i = 0;
	while (i < 5)
	{
		printf("Original: original[%d]: %d\n", i, original[i]);
		i++;
	}
	printf("alternatively\n");
	i = 0;
	while (i < 5)
	{
		printf("Original: *(original + %d): %d\n", i, *(original + i));
		i++;
	}
	printf("alternatively\n");
	i = 0;
	while (i < 5)
	{
		printf("Original: %d[original]: %d\n", i, i[original]);
		i++;
	}
	printf("crazy one: %d[original][original]: %d\n", 1, 1[original][original]);
	printf("crazy two: %d[original][original][original]: %d\n", 1, 1[original][original][original]);
	printf("crazy three: %d[original][original][original][original]: %d\n", 1, 1[original][original][original][original]);
}

void	the_2d_array(void)
{
	int	original[5][5] = {{1, 2, 3, 4, 5},
							{6, 7, 8, 9, 10},
							{11, 12, 13, 14, 15},
							{16, 17, 18, 19, 20},
							{21, 22, 23, 24, 25}};
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			printf("Original: original[%d][%d]: %d\n", i, j, original[i][j]);
			j++;
		}
		i++;
	}
	printf("alternatively\n");
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			printf("Original: *(*(original + %d) + %d): %d\n", i, j, *(*(original + i) + j));
			j++;
		}
		i++;
	}
	printf("alternatively\n");
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			printf("Original: %d[original][%d]: %d\n", i, j, i[original][j]);
			j++;
		}
		i++;
	}
	printf("alternatively\n");
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			printf("Original: j%d[i%d[original]]: %d\n", j, i, j[i[original]]);
			j++;
		}
		i++;
	}
}

void	no_type_specified(void)
{
	auto original[5] = {1, 2, 3, 4, 5};
	printf("Original: original[0]: %d\n", original[0]);
	printf("Original: original[1]: %d\n", original[1]);
	printf("Original: original[2]: %d\n", original[2]);
	printf("Original: original[3]: %d\n", original[3]);
	printf("Original: original[4]: %d\n", original[4]);
}

int typedef	t_blah;
typedef int	t_plah;
unsigned typedef int t_woah;

volatile int keep_running = true;

void	signal_handler(int signal)
{
	keep_running = false;
}

void	volatile_example(void)
{
	signal(SIGINT, signal_handler);
	while (keep_running)
	{
		printf("Keep running\n");
	}
	printf("Stopped running\n");
	signal(SIGINT, SIG_DFL);
}

void	syntax_nonsense(void)
{
	const int	x;
	int const	y;
	t_blah		z;
	t_plah		a;
}

int	main(void)
{
	the_original();
	//the_2d_array();
	//no_type_specified();
	//syntax_nonsense();
	//volatile_example();
	return (0);
}