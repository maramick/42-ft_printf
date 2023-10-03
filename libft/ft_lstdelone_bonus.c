/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:46:31 by pvudthic          #+#    #+#             */
/*   Updated: 2023/09/05 15:27:05 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	if (del)
		del(lst->content);
	free(lst);
}
// void	del(void *node)
// {
// 	char *reset = (char *)node;
// 	int i = 0;
// 	printf("--%s--\n", reset);
// 	// Clear the content by setting each character to '\0'
// 	while (reset[i] != '\0') {
// 		reset[i] = '\0';
// 		i++;
// 	}
// }
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
// 	while (current != NULL) {
// 		printf("%s ", (char *)current->content);
// 		current = current->next;
// 	}
// 	current = reset_current;
// 	ft_lstadd_back(&current, node4);
// 	ft_lstadd_back(&current, node5);
// 	printf("\n---- After Add -----\n");
// 	while (current != NULL) {
// 		printf("%s ", (char *)current->content);
// 		current = current->next;
// 	}
// 	// Call ft_lstdelone with node5
// 	ft_lstdelone(node5, del);
// 	//current = reset_current;
// 	// printf("\n---- After Delete -----\n");
// 	// while (current != NULL) {
// 	// 	printf("%s ", (char *)current->content);
// 	// 	current = current->next;
// 	// }
// 	// printf("\n---- NULL LST -----\n");
// 	// ft_lstadd_back(lst, node6);
// 	// printf("%s ", (char *)n_lst->content);
// 	// // Call ft_lstdelone with node6
// 	// ft_lstdelone(node6, del);
// 	// ... (rest of your code)
// 	return 0;
// }
