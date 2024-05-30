/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_test_with_djb2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 07:48:57 by akuburas          #+#    #+#             */
/*   Updated: 2024/05/30 10:36:42 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @file hash_test_with_djb2.c
 * @brief Testing the djb2 hash function.
*/

typedef struct s_cool_table
{
	char			*key;
	unsigned long	value;
	char			*hidden_info;
}	t_cool_table;

typedef struct s_hash_table
{
	char			*key;
	unsigned long	value;
}	t_hash_table;


// ((hash << 5) + hash) + str[i] == hash * 33 + str[i]
/**
 * @brief Creates a hash value from a string.
 * @param str The string to be hashed.
 * @return The hash value.
*/
unsigned long	create_hash(unsigned char *str)
{
	unsigned long	hash;
	int				i;

	hash = 5381;
	i = 0;
	while (str[i])
	{
		hash = ((hash << 5) + hash) + str[i];
		i++;
	}
	return (hash);
}

int	handle_collision(t_hash_table *hash_table, char *key,
	unsigned long hash, int table_size)
{
	int	i;
	int	old_index;

	hash = create_hash((unsigned char *)key);
	old_index = hash % table_size;
	if (old_index == table_size - 1)
		i = 0;
	else
		i = old_index + 1;
	while (hash_table[i].key)
	{
		i++;
		if (i == table_size && (old_index == 0 || old_index == table_size - 1))
			return (1);
		else if (i == table_size && old_index != table_size - 1)
			i = 0;
		if (i == old_index)
			return (1);
	}
	hash_table[i].key = key;
	hash_table[i].value = hash;
	return (0);
}

int	insert_hash(t_hash_table *hash_table, char *key, int table_size)
{
	unsigned long	hash;
	int				index;

	hash = create_hash((unsigned char *)key);
	index = hash % table_size;
	if (hash_table[index].key)
	{
		if (handle_collision(hash_table, key, hash, table_size) == 1)
			return (1);
	}
	hash_table[index].key = key;
	hash_table[index].value = hash;
	return (0);
}

t_hash_table	*search_collision(t_hash_table *hash_table, char *key,
	unsigned long hash, int table_size)
{
	int	i;
	int	old_index;

	old_index = hash % table_size;
	if (old_index == table_size - 1)
		i = 0;
	else
		i = old_index + 1;
	while (hash_table[i].key)
	{
		if (hash_table[i].value == hash)
			if (strcmp(hash_table[i].key, key) == 0)
				return (&hash_table[i]);
		i++;
		if (i == table_size && (old_index == 0 || old_index == table_size - 1))
			return (NULL);
		else if (i == table_size && old_index != table_size - 1)
			i = 0;
		if (i == old_index)
			return (NULL);
	}
	return (NULL);
}

t_hash_table	*search_hash(t_hash_table *hash_table, char *key,
	int table_size)
{
	unsigned long	hash;
	int				index;

	hash = create_hash((unsigned char *)key);
	index = hash % table_size;
	if (hash_table[index].key)
	{
		if (hash_table[index].value == hash)
		{
			if (strcmp(hash_table[index].key, key) == 0)
				return (&hash_table[index]);
		}
		else
			return (search_collision(hash_table, key, hash, table_size));
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_hash_table	*hash_table;
	t_hash_table	*found;

	if (argc < 2)
	{
		printf("Usage: %s <string> [string]...\n", argv[0]);
		return (1);
	}
	hash_table = calloc(16, sizeof(t_hash_table));
	if (!hash_table)
		return (1);
	while (argc > 1)
	{
		if (insert_hash(hash_table, argv[argc - 1], 16) == 1)
		{
			printf("Error: table full\n");
			free(hash_table);
			return (1);
		}
		argc--;
	}
	printf("Searching for '%s'\n", "macarony");
	found = search_hash(hash_table, "macarony", 16);
	if (found)
		printf("Found '%s' with hash value %lu\n", found->key, found->value);
	else
		printf("'%s' not found\n", "macarony");
	return (0);
}
