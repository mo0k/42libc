/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 08:21:54 by jmoucade          #+#    #+#             */
/*   Updated: 2017/09/19 10:36:55 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <buffer_controler.h>
#include <stdio.h>
void			init_buffer_malloc(t_buffer_malloc *controler)
{
	controler->buffer = ft_strnew(BUFF_SIZE_INIT);
	controler->buff_size = BUFF_SIZE_INIT;
	controler->remaining_size = BUFF_SIZE_INIT;
	controler->increm = 1;
}

void				print_buffer_malloc(t_buffer_malloc *controler)
{
	ft_putstrcolor("+--------------------------+malloc\n", C_YELLOW);
	ft_putstrcolor("| ", C_YELLOW);
	ft_putstrcolor("controler->buffer:", C_GREEN);
	ft_putendl(controler->buffer);
	ft_putstrcolor("| ", C_YELLOW);
	ft_putstrcolor("controler->len:", C_GREEN);
	//ft_putnbr((int)ft_strlen(controler->buffer));
	ft_putnbr(controler->buff_size - controler->remaining_size);
	write(1, "\n", 1);
	ft_putstrcolor("| ", C_YELLOW);
	ft_putstrcolor("controler->buff_size:", C_GREEN);
	ft_putnbr((int)controler->buff_size);
	write(1, "\n", 1);
	ft_putstrcolor("| ", C_YELLOW);
	ft_putstrcolor("controler->remaining_size:", C_GREEN);
	ft_putnbr((int)controler->remaining_size);
	write(1, "\n", 1);
	ft_putstrcolor("| ", C_YELLOW);
	ft_putstrcolor("controler->increm:", C_GREEN);
	ft_putnbr((int)controler->increm);
	write(1, "\n", 1);
	ft_putstrcolor("+--------------------------+\n", C_YELLOW);
}

static int		fill_starter_buffer(t_buffer_malloc *ctrl, char *input, size_t size)
{
	//ft_putstrcolor("fill controler->starter_buffer\n", C_CYAN);
	if (!ctrl || !input)
	{
		//printf("return (0)\n");
		return (0);
	}
	//if (!*input)
	//	ctrl->buffer[ctrl->buff_size - ctrl->remaining_size] = 0;
	//else
	//	ft_strcat(ctrl->buffer, input);
	ft_memmove(ctrl->buffer + (ctrl->buff_size - ctrl->remaining_size), input, size);
	ctrl->remaining_size -= size;
//	print_buffer_malloc(ctrl);
	return (1);
}


static int		fill_buffer(t_buffer_malloc *ctrl, char *input, size_t size)
{
	//ft_putstrcolor("fill controler->buffer\n", C_LBLUE);
	char		*new_buffer;
	int 		old_buff_size;

	if (!ctrl || !input)
		return (0);
	old_buff_size = ctrl->buff_size;
	while ((ctrl->buff_size = ctrl->increm * BUFF_SIZE_INIT) <
										size + old_buff_size - ctrl->remaining_size)
		++ctrl->increm;
	if (!(new_buffer = ft_strnew(ctrl->buff_size)))
		return (0);
	ft_memmove(new_buffer, ctrl->buffer, old_buff_size - ctrl->remaining_size);
	ctrl->remaining_size += ctrl->buff_size - old_buff_size;
	ft_memmove(new_buffer + (ctrl->buff_size - ctrl->remaining_size), input, size);
	ctrl->remaining_size -= size;
	ft_memdel((void**)&ctrl->buffer);
	ctrl->buffer = new_buffer;
//	print_buffer_malloc(ctrl);
	return (1);
}

int				fill_buffer_malloc(t_buffer_malloc *ctrl, char *input, size_t size)
{
	if (!ctrl || !input)
		return (0);
	return (input && available_space(size, ctrl->remaining_size)) ?
			fill_starter_buffer(ctrl, input, size) :
			fill_buffer(ctrl, input, size);
			
}
