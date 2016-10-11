/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 20:05:02 by jmoucade          #+#    #+#             */
/*   Updated: 2016/08/15 20:05:12 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	ct;

	ct = 0;
	while ((s1[ct] || s2[ct] || ct < n) && (s1[ct] == s2[ct]))
	{
		if (s1[ct] < s2[ct])
			return (s1[ct] - s2[ct]);
		if (s1[ct] > s2[ct])
			return (s1[ct] - s2[ct]);
		ct++;
	}
	return (s1[ct] - s2[ct]);
}
