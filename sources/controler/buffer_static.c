/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_static.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 23:59:17 by mo0ky             #+#    #+#             */
/*   Updated: 2017/09/14 14:47:01 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <buffer_controler.h>
#include <stdio.h>

void			init_buffer_static(t_buffer_static *controler)
{
	//ft_bzero(controler->buffer, BUFF_SIZE_INIT);
	controler->current = controler->buffer;
	controler->buff_size = BUFF_SIZE_INIT;
	controler->remaining_size = BUFF_SIZE_INIT;
	controler->used_size = 0;
}

void			print_buffer_static(t_buffer_static *controler)
{
	ft_putstrcolor("+--------------------------+static\n", C_YELLOW);
	ft_putstrcolor("| ", C_YELLOW);
	ft_putstrcolor("controler->buffer:", C_GREEN);
	ft_putendl(controler->buffer);
	ft_putstrcolor("| ", C_YELLOW);
	ft_putstrcolor("controler->buff_size:", C_GREEN);
	ft_putnbr((int)controler->buff_size);
	write(1, "\n", 1);
	ft_putstrcolor("| ", C_YELLOW);
	ft_putstrcolor("controler->used_size:", C_GREEN);
	ft_putnbr(controler->used_size);
	write(1, "\n", 1);
	ft_putstrcolor("| ", C_YELLOW);
	ft_putstrcolor("controler->remaining_size:", C_GREEN);
	ft_putnbr((int)controler->remaining_size);
	write(1, "\n", 1);
	ft_putstrcolor("+--------------------------+\n", C_YELLOW);
}

static int		fill_buffer(t_buffer_static *ctrl, void *input, size_t size)
{
	if (!ctrl || !input)
		return (0);
	//ft_putstrcolor("fill controler->starter_buffer\n", C_CYAN);
	//ft_strcat(ctrl->current, input);
	//if (!*input)
	//	ctrl->buffer[ctrl->buff_size - ctrl->remaining_size] = 0;
//	else
	//printf("input:'%c',%zu\n", *input, size);
	
	//if (size == 1)
	//	ctrl->buffer[ctrl->used_size] = (char)(input);
	//else
		ft_memmove(ctrl->buffer + ctrl->used_size, input, size);
	ctrl->remaining_size -= size;
	ctrl->used_size += size;
	ctrl->buffer[ctrl->used_size] = 0;
	//print_buffer_static(ctrl);
	return (1);
}

static int		filln_buffer(t_buffer_static *ctrl, void *c, size_t n)
{
	int		i;
	if (!ctrl || !c)
		return (0);
	//ft_putstrcolor("fill controler->starter_buffer\n", C_CYAN);
	//ft_strcat(ctrl->current, input);
	//if (!*input)
	//	ctrl->buffer[ctrl->buff_size - ctrl->remaining_size] = 0;
//	else
	//printf("input:'%c',%zu\n", *input, size);
	i = -1;
	while (++i < (int)n)
	{
		ft_memmove(ctrl->buffer + ctrl->used_size, c, 1);
		++ctrl->used_size;
		--ctrl->remaining_size;
	}
	//ctrl->remaining_size -= n;
	//ctrl->used_size += n;
	ctrl->buffer[ctrl->used_size] = 0;
	//print_buffer_static(ctrl);
	return (1);
}

int				filln_buffer_static(t_buffer_static *ctrl, void *c, size_t n)
{
	if (!ctrl)
		return (0);
	return (available_space(n, ctrl->remaining_size)) ?
			filln_buffer(ctrl, c, n) : 0;

}
int				fill_buffer_static(t_buffer_static *ctrl, void *input, size_t size)
{
	//ft_putstr("START fill_buffer_static\n");
	//size_t		new_size;

	if (!ctrl || !input)
		return (0);
	//new_size = ft_strlen(input);
	//new_size = (!*input) ? 1 : ft_strlen(input);
	return (available_space(size, ctrl->remaining_size)) ?
			fill_buffer(ctrl, input, size) : 0;
}