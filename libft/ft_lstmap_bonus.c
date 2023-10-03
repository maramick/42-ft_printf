/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maramick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:46:09 by pvudthic          #+#    #+#             */
/*   Updated: 2023/09/22 19:26:24 by maramick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*node;
	void	*a;

	if (!lst || !f)
		return (NULL);
	new_lst = NULL;
	node = NULL;
	while (lst != NULL)
	{
		a = f(lst->content);
		node = ft_lstnew(a);
		if (node == NULL)
		{
			del(a);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, node);
		lst = lst->next;
	}
	return (new_lst);
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
