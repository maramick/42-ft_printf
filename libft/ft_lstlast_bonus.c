/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:46:37 by pvudthic          #+#    #+#             */
/*   Updated: 2023/09/04 17:46:38 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
// int	main(void)
// {
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*node3;
// 	t_list	*node4;

// 	node1 = ft_lstnew((void *)("Phanuwat"));
// 	node2 = ft_lstnew((void *)("Vudthichairangsun"));
// 	node3 = ft_lstnew((void *)("maramick"));
// 	node4 = ft_lstnew((void *)("12/5/42"));
// 	//node4 = ft_lstnew(NULL);

// 	//linkn node
// 	node1->next = node2;
// 	node2->next = node3;
// 	node3->next = node4;

// 	t_list	*current = node1;
// 	// while (current != NULL)
// 	// {
// 	// 	printf("%s ", (char *)current->content);
// 	// 	current = current->next;
// 	// }
// 	printf("%d\n", ft_lstsize(current));
// 	printf("%s\n", (char *)current->content);
// 	current = ft_lstlast(current);
// 	printf("%s\n", (char *)current->content);
// 	//printf("%s", (char *)current->content);
// }
