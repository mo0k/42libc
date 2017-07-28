/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_controler.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 16:16:47 by jmoucade          #+#    #+#             */
/*   Updated: 2017/07/11 20:35:13 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_CONTROLER_H
# define BUFFER_CONTROLER_H

#include <unistd.h>
#include <libft.h>

#define BUFF_SIZE_INIT 4096

typedef struct			s_control_malloc
{
	char				starter_buffer[BUFF_SIZE_INIT];
	char				*buffer;
	size_t				buff_size;
	size_t				remaining_size;
	unsigned int		increm;
	char				malloc;
}						t_buffer_controler;

void					init_buffer_controler(t_buffer_controler *controler);
void					print_buffer_controler(t_buffer_controler *controler);
int						fill_buffer_controler(t_buffer_controler *ctrl, char *input);

#endif