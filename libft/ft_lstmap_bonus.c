/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:30:51 by ltropina          #+#    #+#             */
/*   Updated: 2024/04/19 15:18:23 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*node;
	void	*cnt;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		cnt = f(lst->content);
		node = ft_lstnew(cnt);
		if (!node)
		{
			del(cnt);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, node);
		lst = lst->next;
	}
	return (new_list);
}

/*static void *f(void * ch)
{
	return (ch);
}

int main ()
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
	t_list *new = ft_lstmap(list,f, free);
	i = 0;
	while (new)
	{
		printf("%d %s %p\n", i, (char *)new->content, new->next);
		new = new->next;
		i++;
	}
	//ft_lstclear(&list, free);
	//ft_lstclear(&new, free);
return (0);
}*/