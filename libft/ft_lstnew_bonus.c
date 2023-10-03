/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:52:57 by pvudthic          #+#    #+#             */
/*   Updated: 2023/09/05 12:27:39 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
// int	main(void)
// {
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*node3;
// 	t_list	*node4;

// 	node1 = ft_lstnew((void *)("Phanuwat"));
// 	node2 = ft_lstnew((void *)("Vudthichairangsun"));
// 	node3 = ft_lstnew((void *)("3"));
// 	node4 = ft_lstnew(NULL);

// 	node1->next = node2;
// 	node2->next = node3;

// 	t_list	*current = node1;
// 	while (current != NULL)
// 	{
// 		printf("%s ", (char *)current->content);
// 		current = current->next;
// 	}
// }
