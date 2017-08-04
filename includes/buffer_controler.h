/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_controler.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 16:16:47 by jmoucade          #+#    #+#             */
/*   Updated: 2017/08/03 00:33:28 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_CONTROLER_H
# define BUFFER_CONTROLER_H

#include <unistd.h>
#include <libft.h>

#define BUFF_SIZE_INIT 4096

typedef struct		s_control_malloc
{
	char			starter_buffer[BUFF_SIZE_INIT];
	char			*buffer;
	size_t			buff_size;
	size_t			remaining_size;
	unsigned int	increm;
	char			malloc;
}					t_buffer_static_controler;

typedef struct		s_controler_buffer_static
{
	char			buffer[BUFF_SIZE_INIT];
	char			*current;
	size_t			buff_size;
	size_t			remaining_size;
}					t_buffer_static;

typedef struct		s_controler_buffer_malloc
{
	char			*buffer;
	size_t			buff_size;
	size_t			remaining_size;
	unsigned int	increm;
}					t_buffer_malloc;


void				init_buffer_static(t_buffer_static *controler);
void				init_buffer_malloc(t_buffer_malloc *controler);
int					fill_buffer_static(t_buffer_static *controler, char *input);
int					fill_buffer_malloc(t_buffer_malloc *controler, char *input);
void				print_buffer_static(t_buffer_static *controler);
void				print_buffer_malloc(t_buffer_malloc *controler);
int					available_space(size_t new_size, size_t remaining_size);

#endif
