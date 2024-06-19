/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:10:12 by akuburas          #+#    #+#             */
/*   Updated: 2024/06/19 10:38:10 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int	main(void)
{
	t_hash	*hash_table;
	char	*input;
	float	load_factor;
	int		table_size;
	int		i;

	table_size = 16;
	hash_table = (t_hash *)malloc(sizeof(t_hash) * table_size);
	if (!hash_table)
		return (1);
	i = 0;
	load_factor = 0;
	while (i < table_size)
	{
		hash_table[i].key = NULL;
		hash_table[i].value = 0;
		i++;
	}
	i = 0;
	while (1)
	{
		input = readline("Enter a key: ");
		if (!input)
			break ;
		if (insert_hash(hash_table, input, table_size) == 1)
		{
			printf("Failed to insert key\n");
			exit(1);
		}
		i++;
		load_factor = (float)i / (float)table_size;
		if (load_factor > 0.7)
		{
			printf("Resizing hash table\n");
			if (resize_hash(table_size * 2, &hash_table, table_size) == 1)
			{
				printf("Failed to resize hash table\n");
				free_hash(hash_table, table_size);
				exit(1);
			}
			table_size *= 2;
		}
	}
	i = 0;
	while (i < table_size)
	{
		if (hash_table[i].key)
			printf("Key: %s, Value: %lu Position: %d\n", hash_table[i].key,
				hash_table[i].value, i);
		i++;
	}
	free_hash(hash_table, table_size);
	return (0);
}
