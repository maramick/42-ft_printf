/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:46:43 by pvudthic          #+#    #+#             */
/*   Updated: 2023/09/04 17:46:43 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
// int	main(void)
// {
// 	t_list	**lst;
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
// 	node3->next = node4;

// 	t_list	*current = node1;
// 	printf("count : %d\n", ft_lstsize(current));
// 	while (current != NULL)
// 	{
// 		printf("%s ", (char *)current->content);
// 		current = current->next;
// 	}
// 	printf("%d", ft_lstsize(current));
// }
