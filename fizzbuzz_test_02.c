/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz_test_02.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:21:10 by akuburas          #+#    #+#             */
/*   Updated: 2023/12/20 10:29:21 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char *argv[])
{
	int			number;
	char		output[13];
	const char	*words[] = {"fizz", "buzz", "muzz"};
	const int	divisors[] = {3, 5, 7};
	int			i;

	i = 0;
	if (argc == 2)
	{
		number = atoi(argv[1]);
		while (i <= 2)
		{
			if (number % divisors[i] == 0)
				strcat(output, words[i]);
			i++;
		}
	}
	if (output[0] != '\0')
		write(1, output, strlen(output));
	write(1, "\n", 1);
}