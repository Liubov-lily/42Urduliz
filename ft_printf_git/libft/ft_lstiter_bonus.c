/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:02:02 by ltropina          #+#    #+#             */
/*   Updated: 2024/04/19 15:44:54 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*static void	ft_change(void *ch)
{
	*(char *)ch = 'A';
}

int main()
{
	t_list	*list;
	int i = 0;
	char ch[] = "0";

	list = NULL;
	t_list *tmp = NULL;
	while (i < 10)
	{
		t_list *node = ft_lstnew(ch);
		ft_lstadd_front(&list, node);
		i++;
	}
	i = 0;
	tmp = list;
	while (list)
	{
		printf("%d %s %p\n", i, (char *)list->content, list->next);
		list = list->next;
		i++;
	}
	list = tmp;
	ft_lstiter(list, ft_change);
	i = 0;
	while (tmp)
	{
		printf("%d %s %p\n", i, (char *)tmp->content, tmp->next);
		tmp = tmp->next;
		i++;
	}
	//ft_lstclear(list);
	return (0);
}*/