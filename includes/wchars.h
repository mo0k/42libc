/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchars.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 00:20:24 by mo0ky             #+#    #+#             */
/*   Updated: 2017/09/24 20:57:46 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WCHARS_H
# define WCHARS_H

# include <wchar.h>
# include <stdlib.h>

char	ft_wcharlen(wchar_t c);
int		ft_wstrlen(wchar_t *str);
int		ft_wstrnlen(wchar_t *str, int n);

#endif