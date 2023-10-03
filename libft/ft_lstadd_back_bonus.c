/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:46:21 by pvudthic          #+#    #+#             */
/*   Updated: 2023/09/05 12:16:46 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	else
	{
		current = *lst;
		if (current != NULL)
		{
			current = ft_lstlast(current);
			current->next = new;
		}
		else
			current->next = new;
	}
}
// int	main(void)
// {
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*node3;
// 	t_list	*node4;
// 	t_list	*node5;
// 	t_list	*node6;
// 	t_list	*n_lst;
// 	t_list	**lst;

// 	node1 = ft_lstnew((void *)("Phanuwat"));
// 	node2 = ft_lstnew((void *)("Vudthichairangsun"));
// 	node3 = ft_lstnew((void *)("maramick"));
// 	node4 = ft_lstnew((void *)("12/5/42"));
// 	node5 = ft_lstnew((void *)("Hello World!!"));
// 	node6 = ft_lstnew((void *)("Hello Earth!!"));
// 	n_lst = NULL;
// 	lst = &n_lst;

// 	//linkn node
// 	node1->next = node2;
// 	node2->next = node3;

// 	t_list	*reset_current = node1;
// 	t_list	*current = node1;

// 	printf("---- Before Add -----\n");
// 	while (current != NULL)
// 	{
// 		printf("%s ", (char *)current->content);
// 		current = current->next;
// 	}
// 	current = reset_current;
// 	ft_lstadd_back(&current, node4);
// 	ft_lstadd_back(&current, node5);
// 	printf("\n---- After Add -----\n");
// 	while (current != NULL)
// 	{
// 		printf("%s ", (char *)current->content);
// 		current = current->next;
// 	}
// 	printf("\n---- NULL LST -----\n");
// 	ft_lstadd_back(lst, node6);
// 	//ft_lstadd_back(&n_lst, node4);
// 	printf("%s ", (char *)n_lst->content);
// }
