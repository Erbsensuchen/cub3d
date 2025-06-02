/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlendle <mlendle@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:54:58 by mlendle           #+#    #+#             */
/*   Updated: 2024/10/18 10:59:12 by mlendle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*temp;

	if (lst == 0)
		return (0);
	start = ft_lstnew(f(lst->content));
	if (start == 0)
		return (0);
	lst = lst->next;
	while (lst != 0)
	{
		temp = ft_lstnew(f(lst->content));
		if (temp == 0)
			return (0);
		ft_lstadd_back(&start, temp);
		lst = lst->next;
	}
	return (start);
	del(temp);
}
