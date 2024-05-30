/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_test_with_djb2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 07:48:57 by akuburas          #+#    #+#             */
/*   Updated: 2024/05/30 22:45:50 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

/**
 * @file hash_test_with_djb2.c
 * @brief Testing the djb2 hash function.
*/

typedef struct s_hash_table
{
	char			*key;
	unsigned long	value;
}	t_hash_table;

typedef struct s_hash_container
{
	void			*hash_table;
	int				table_size;
	int				current_amount;
	float			load_factor;
	int				increase_factor;
	unsigned long	(*hash_func)(unsigned char *);
}	t_container;

typedef struct s_cool_table
{
	char			*key;
	unsigned long	value;
	char			*hidden_info;
}	t_cool_table;

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

int	handle_collision(t_container *container, char *key, unsigned long hash)
{
	int	i;
	int	old_index;
	int	table_size;
	t_hash_table	*hash_table;

	hash_table = container->hash_table;
	table_size = container->table_size;
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
	printf("Inserted '%s' with hash value %lu\n", hash_table[i].key, hash_table[i].value);
	return (0);
}

void	container_increased(t_container *container)
{
	int	current_amount;
	int	table_size;

	current_amount = container->current_amount;
	table_size = container->table_size;
	container->current_amount++;
	current_amount++;
	container->load_factor = (float)current_amount / table_size;
}

int	insert_hash(t_container *container, char *key)
{
	unsigned long	hash;
	int				index;
	t_hash_table	*hash_table;

	hash_table = container->hash_table;
	hash = create_hash((unsigned char *)key);
	index = hash % container->table_size;
	if (hash_table[index].key)
	{
		if (handle_collision(container, key, hash) == 1)
			return (-1);
		container_increased(container);
		return (0);
	}
	hash_table[index].key = key;
	hash_table[index].value = hash;
	printf("Inserted '%s' with hash value %lu\n", hash_table[index].key, hash_table[index].value);
	container_increased(container);
	return (0);
}

t_hash_table	*search_collision(t_hash_table *hash_table, char *key
	, int table_size, unsigned long hash)
{
	int				i;
	int				old_index;

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
		{
			printf("not found\n");
			return (NULL);
		}
	}
	printf("not found\n");
	return (NULL);
}

void	*search_hash(t_container *hash_container, char *key)
{
	unsigned long	hash;
	int				index;
	t_hash_table	*hash_table;
	int				table_size;

	printf("inside search_hash\n");
	printf("searching for '%s'\n", key);
	hash_table = hash_container->hash_table;
	table_size = hash_container->table_size;
	hash = create_hash((unsigned char *)key);
	index = hash % table_size;
	printf("searching for '%s' with hash value %lu\n", key, hash);
	printf("index: %d\n", index);
	if (hash_table[index].key)
	{
		if (hash_table[index].value == hash)
		{
			if (strcmp(hash_table[index].key, key) == 0)
				return (&hash_table[index]);
		}
		else
			return (search_collision(hash_table, key, table_size, hash));
	}
	printf("not found\n");
	return (NULL);
}

void	cool_table_copy(t_container *container, t_container *temp, int i)
{
	t_cool_table	*old;
	t_cool_table	*new;
	t_cool_table	*search_old_in_new;

	old = container->hash_table;
	new = temp->hash_table;
	printf("copying2 %d\n", i);
	if (old[i].key != NULL)
		printf("key: %s\n", old[i].key);
	else
		printf("key empty %d\n", i);
	search_old_in_new = (t_cool_table *)search_hash(temp, old[i].key);
	printf("searched\n");
	search_old_in_new->hidden_info = old[i].hidden_info;
}

void	hash_resizer(t_container *container, void *new_table
	, void (copy)(t_container *, t_container *, int))
{
	int				i;
	t_container		*temp;
	t_hash_table	*hash_table;
	t_cool_table	*cool_table;

	hash_table = container->hash_table;
	temp->hash_table = new_table;
	cool_table = new_table;
	temp->table_size = container->table_size * container->increase_factor;
	temp->current_amount = 0;
	temp->load_factor = 0;
	temp->increase_factor = container->increase_factor;
	temp->hash_func = container->hash_func;
	i = 0;
	printf("copying table one by one\n");
	while (i < container->table_size)
	{
		if (hash_table[i].key)
		{
			printf("copying1 %d\n", i);
			printf("key: %s\n", hash_table[i].key);
			printf("hash: %lu\n", hash_table[i].value);
			insert_hash(temp, hash_table[i].key);
			cool_table = search_hash(temp, hash_table[i].key);
			printf("found\n");
			printf("key: %s\n", cool_table->key);
			printf("value: %lu\n", cool_table->value);
			printf("after inserting\n");
			//copy(container, temp, i);
		}
		else 
			printf("empty %d\n", i);
		i++;
	}
	printf("freeing old table\n");
	free(container->hash_table);
	container->hash_table = temp->hash_table;
	container->table_size = temp->table_size;
	container->current_amount = temp->current_amount;
	container->load_factor = temp->load_factor;
	container->increase_factor = temp->increase_factor;
	container->hash_func = temp->hash_func;
}

int	main(void)
{
	t_container		container;
	t_cool_table	*found;
	t_cool_table	*cool_table;
	t_cool_table	*temp;
	char			*search_key;
	int				i;

	cool_table = calloc(16, sizeof(t_cool_table));
	if (!cool_table)
		return (1);
	container.hash_table = cool_table;
	container.table_size = 16;
	container.current_amount = 0;
	container.load_factor = 0;
	container.increase_factor = 2;
	container.hash_func = create_hash;
	while (1)
	{
		search_key = readline("Enter a key to insert: ");
		if (!search_key)
			break ;
		if (insert_hash(&container, search_key) == 1)
		{
			printf("Error: table full\n");
			free(cool_table);
			return (1);
		}
		if (container.load_factor > 0.7)
		{
			temp = calloc(container.table_size * container.increase_factor,
					sizeof(t_cool_table));
			if (!temp)
			{
				free(cool_table);
				return (1);
			}
			printf("Resizing table\n");
			hash_resizer(&container, temp, cool_table_copy);
			printf("Table resized\n");
		}
		add_history(search_key);
	}
	while (1)
	{
		search_key = readline("Enter a key to search for: ");
		if (!search_key)
			break ;
		printf("Searching for '%s'\n", search_key);
		found = (t_cool_table *)search_hash(&container, search_key);
		if (found)
			printf("Found '%s' with hash value %lu\n", found->key, found->value);
		else
			printf("'%s' not found\n", search_key);
		free(search_key);
	}
	clear_history();
	i = 0;
	cool_table = container.hash_table;
	while (i < container.table_size)
	{
		if (cool_table[i].key)
		{
			printf("key: %s, value: %lu, hidden_info: %s\n", cool_table[i].key
				, cool_table[i].value, cool_table[i].hidden_info);
			free(cool_table[i].key);
		}
		i++;
	}
	free(cool_table);
	return (0);
}
