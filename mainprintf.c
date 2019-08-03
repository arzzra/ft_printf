/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 18:23:33 by cdemetra          #+#    #+#             */
/*   Updated: 2019/08/02 07:51:01 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(int ac, char **av)
{
	int	a = -15;
	int	*f;
	char	b[] = "qwertyR";
	char	*c;
	char	*h;
	char	t = 'V';
	unsigned long long	ewr;
	f = &a;
	int		i = 0;
	// a = c - b;
	//printf("%p", f);
	c = (char*)&f;
	h = (char*)&ewr;
	ewr = (unsigned long long)f;
	printf("11%llu\n", ewr);
	printf("adress f:%-30pk\nadress c:%30p \n", f, c);
	//printf("adress ewr:%f\n", ewr);
	while (i < 8)
	{
		t = c[i];
		h[i] = t;
		printf("%c\n", t);
		i++;
	}
	printf("%llu\n", ewr);
	return (0);
}
