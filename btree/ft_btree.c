/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_btree.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 11:56:49 by yizhang       #+#    #+#                 */
/*   Updated: 2023/09/28 12:36:22 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdio.h>

int search(t_btree* head, int value)
{
	if (!head)
		return (1);
	if (head->value == value)
		return (1);
	if (head->right && search(head->right, value))
		return (1);
	if (head->left && search(head->left, value))
		return (1);
	return (0);
}

t_btree* insert(t_btree *node, int value)
{
	if (value > node->value)
	{
		if (!node->right)
		{
			t_btree *new = malloc(sizeof(t_btree));
			new->value = value;
			node->right = new;
			return (node);
		}
		return (insert(node->right, value)); 
	}
	if (value < node->value)
	{
		if (!node->left)
		{
			t_btree *new = malloc(sizeof(t_btree));
			new->value = value;
			node->left = new;
			return (node);
		}
		return (insert(node->left, value));
	}
	return (NULL);
}

t_btree* insert_binary_tree(t_btree *root, int value)
{
	t_btree *new = malloc(sizeof(t_btree));
	new = NULL;
	if(root == NULL)
		return new;
	new = root;
	if (!(search(root, value)))
		new = insert(new, value);
	return new;
}

int main()
{
    t_btree *root;
    
    root = malloc(sizeof(t_btree));
    root->value = 3;
    insert_binary_tree(root, 2);
    insert_binary_tree(root, 20);
    insert_binary_tree(root, 6);
    insert_binary_tree(root, 3);
    insert_binary_tree(root, -2);
    insert_binary_tree(root, -1);
    insert_binary_tree(root, 19);
    while (root != NULL)
    {
        printf("lol:%i",root->value);
        if (!root->right)
            return(0);
        root = root->right;
    }
    return 0;
}