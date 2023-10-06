/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_btree.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 11:56:49 by yizhang       #+#    #+#                 */
/*   Updated: 2023/10/06 12:19:01 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int search(t_btree *root, int value)
{
	if (!root)
		return 1;
	else if (root->value == value)
		return 1;
	else if (root->right && search(root->right, value))
		return 1;
	else if (root->left && search(root->left, value))
		return 1;	
	return 0;
}

t_btree *insert(t_btree *root, int value)
{
	if (value > root->value)
	{
		if (!root->right)
		{
			t_btree *new = malloc(sizeof(t_btree));
			new->value = value;
			new->right = NULL;
			new->left = NULL;
			root->right = new;
			return new;
		}
		return(insert(root->right, value));
	}
	else if (value < root->value)
	{
		if (!root->left)
		{
			t_btree *new = malloc(sizeof(t_btree));
			new->value;
			new->right = NULL;
			new->left = NULL;
			root->left = new;
			return new;
		}
		return(insert(root->left, value));	
	}
	return NULL;
}

t_btree* insert_binary_tree(t_btree *root, int value)
{
	if (root == NULL)
		return NULL;
	t_btree *new = malloc(sizeof(t_btree));
	new = root;
	if (!search(root, value))
		insert(new,value);
	return new;
}



int main(void)
{
    t_btree *root;
	
	root = malloc(sizeof(t_btree));
	root->right = NULL;
	root->left = NULL;
	insert_binary_tree(root, 1);
	insert_binary_tree(root, 3);
	insert_binary_tree(root, 1);
	insert_binary_tree(root, 2);
	insert_binary_tree(root, 1);
	insert_binary_tree(root, 4);
	
	while (root)
	{
		printf("%i",root->value);
		if (!root->right)
			return 0;
		root = root->right;
	}
	while (root)
	{
		printf("%i",root->value);
		if (!root->left)
			return 0;
		root = root->left;
	}
	return 0;
}