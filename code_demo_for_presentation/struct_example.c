/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_example.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 02:01:56 by akuburas          #+#    #+#             */
/*   Updated: 2024/03/04 02:09:30 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct	s_example
{
	int			a;
	int			b;
}				t_example;

void	struct_modifier(t_example *example)
{
	example->a = 10;
	example->b = 5;
}

int	main(void)
{
	t_example			example;
	struct s_example	example2;

	example.a = 5;
	example.b = 10;
	printf("a = %d, b = %d\n", example.a, example.b);
	struct_modifier(&example);
	printf("a = %d, b = %d\n", example.a, example.b);
	return (0);
}