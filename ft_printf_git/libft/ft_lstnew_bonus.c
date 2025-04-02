/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:37:40 by ltropina          #+#    #+#             */
/*   Updated: 2024/04/17 12:19:48 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/*int main() 
{
	int *tmp = malloc(sizeof(int));
	*tmp = 42;
    t_list *node = ft_lstnew(tmp);
    printf("%d\n", *((int *)node->content));
	char str[] = "Hello";
	t_list *node1 = ft_lstnew(str);
    printf("%s\n", (char *)node1->content);
    return (0);
}*/