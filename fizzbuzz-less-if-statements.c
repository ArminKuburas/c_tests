/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz-less-if-statements.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:44:56 by akuburas          #+#    #+#             */
/*   Updated: 2023/12/20 09:55:59 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int	number;

	if (argc == 2)
	{
		number = atoi(argv[1]);
		if (number % 3 == 0 && number % 5 == 0 && number % 7 == 0)
			write(1, "fizzbuzzmuzz", 12);
		else if (number % 3 == 0 && number % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (number % 3 == 0 && number % 7 == 0)
			write(1, "fizzmuzz", 8);
		else if (number % 5 == 0 && number % 7 == 0)
			write(1, "buzzmuzz", 8);
		else if (number % 3 == 0)
			write(1, "fizz", 4);
		else if (number % 5 == 0)
			write(1, "buzz", 4);
		else if (number % 7 == 0)
			write(1, "muzz", 4);
	}
	write(1, "\n", 1);
	return (0);
}
