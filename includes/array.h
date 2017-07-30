/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 00:18:14 by mo0ky             #+#    #+#             */
/*   Updated: 2017/07/30 00:52:10 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <stdlib.h>

int 		*ft_range(int min, int max);
void		ft_foreach(int *tab, int length, void (*f)(int));
int			ft_count_if(char **tab, int (*f)(char*));
void		ft_delstrtab(char **tab);
char		***ft_get_triple_tab(int line, int columm, int len);
void		ft_print_triple_tab(char ***tab);
void		ft_delete_triple_tab(char ***tab);

#endif