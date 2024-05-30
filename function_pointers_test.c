/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_pointers_test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:45:18 by akuburas          #+#    #+#             */
/*   Updated: 2024/05/30 13:58:52 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef int	(*t_func)(int, int);

int	add(int a, int b)
{
	return (a + b);
}

int	subtract(int a, int b)
{
	return (a - b);
}

int	multiply(int a, int b)
{
	return (a * b);
}

int	divide(int a, int b)
{
	return (a / b);
}

int	main(void)
{
	t_func	func[4];
	int		i;
	int		a;
	int		b;

	func[0] = add;
	func[1] = subtract;
	func[2] = multiply;
	func[3] = divide;
	i = 0;
	a = 10;
	b = 5;
	while (i < 4)
	{
		printf("Result: %d\n", func[i](a, b));
		i++;
	}
	return (0);
}
