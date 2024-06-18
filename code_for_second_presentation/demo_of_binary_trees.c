/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo_of_binary_trees.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:19:01 by akuburas          #+#    #+#             */
/*   Updated: 2024/06/18 19:25:10 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int				data;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

t_node	*new_node(int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

t_node	*insert(t_node *node, int data)
{
	if (!node)
		return (new_node(data));
	if (data < node->data)
		node->left = insert(node->left, data);
	else if (data > node->data)
		node->right = insert(node->right, data);
	return (node);
}

void	inorder(t_node *node)
{
	if (node)
	{
		inorder(node->left);
		printf("%d\n", node->data);
		inorder(node->right);
	}
}

void	preorder(t_node *node)
{
	if (node)
	{
		printf("%d\n", node->data);
		preorder(node->left);
		preorder(node->right);
	}
}

void	postorder(t_node *node)
{
	if (node)
	{
		postorder(node->left);
		postorder(node->right);
		printf("%d\n", node->data);
	}
}

int	main(void)
{
	t_node	*root;

	root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
	printf("Inorder traversal\n");
	inorder(root);
	printf("Preorder traversal\n");
	preorder(root);
	printf("Postorder traversal\n");
	postorder(root);
	return (0);
}
