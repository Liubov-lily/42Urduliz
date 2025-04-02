/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:30:39 by ltropina          #+#    #+#             */
/*   Updated: 2024/04/17 14:57:56 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	if (!lst && !del)
		return ;
	while (*lst)
	{
		node = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = node;
	}
}

/*int main()
{
	t_list	*list;
	int i = 0;
	char *ch = "0";

	list = NULL;
	while (i < 10)
	{
		t_list *node = ft_lstnew(ch);
		ft_lstadd_front(&list, node);
		i++;
	}
	i = 0;
	while (list)
	{
		printf("%d %s %p\n", i, (char *)list->content, list->next);
		list = list->next;
		i++;
	}
	ft_lstclear(&list, free);
	if (!list)
		printf("clean");
	return (0);
}*/