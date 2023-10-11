/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   serch.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 11:24:29 by yizhang       #+#    #+#                 */
/*   Updated: 2023/10/11 11:24:43 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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