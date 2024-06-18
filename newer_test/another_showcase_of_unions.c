/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_showcase_of_unions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:55:56 by akuburas          #+#    #+#             */
/*   Updated: 2024/05/30 16:20:28 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0m"

const char *g_preset_strings[] = {
	"Hello world",
	"Goodbye world",
	"Hello again",
	"General Kenobi",
};

const char *g_colors[] = {
	"red",
	"green",
	"blue",
	"yellow",
};

typedef union u_data
{
	struct
	{
		unsigned char	string_index : 2;
		unsigned char	color_index : 2;
	} s_bits;
	unsigned char	byte;
}	t_data;

char	*find_color(unsigned char color_index)
{
	if (color_index == 0)
		return (RED);
	else if (color_index == 1)
		return (GREEN);
	else if (color_index == 2)
		return (BLUE);
	else if (color_index == 3)
		return (YELLOW);
}

void	data_interpreter(t_data data)
{
	char	*color;

	color = find_color(data.s_bits.color_index);
	printf("%s%s%s\n", color, g_preset_strings[data.s_bits.string_index], RESET);
}

int	main(void)
{
	t_data	data;
	int		i;
	int		j;

	data.byte = 0;
	printf("this is size of data: %lu\n", sizeof(data));
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			data.s_bits.string_index = i;
			data.s_bits.color_index = j;
			printf("String: %s, Color: %s\n", g_preset_strings[data.s_bits.string_index], g_colors[data.s_bits.color_index]);
			data_interpreter(data);
			j++;
		}
		i++;
	}
	return (0);
}
