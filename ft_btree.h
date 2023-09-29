/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_btree.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 11:59:21 by yizhang       #+#    #+#                 */
/*   Updated: 2023/09/28 12:30:11 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
#define FT_BTREE_H

#include <stdlib.h>

typedef struct s_btree
{
    struct  s_btree *left;
    struct  s_btree *right;
    int     value;
}t_btree;

#endif