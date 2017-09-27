/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:50:56 by jmoucade          #+#    #+#             */
/*   Updated: 2017/09/27 01:48:04 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

typedef enum	e_bool
{
	FALSE = 0,
	TRUE = 1
}				t_bool;

typedef long int 				t_lint;
typedef long long int 			t_llint;
typedef unsigned int 			t_uint;
typedef unsigned long int 		t_ulint;
typedef unsigned long long int 	t_ullint;
typedef unsigned short int 		t_ushortint;
typedef unsigned char 			t_uchar;

# include <array.h>
# include <charac.h>
# include <convert.h>
# include <integer.h>
# include <list.h>
# include <memory.h>
# include <puts.h>
# include <colors.h>
# include <string.h>
# include <wchars.h>
# include <buffer_controler.h>
# include <get_next_line.h>

# define ABS(x) (x<0) ? (x*-1) : (x)

#endif
