/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:46:05 by tdayde            #+#    #+#             */
/*   Updated: 2021/03/31 19:23:44 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int main(int argc, char **argv)
{
	(void)argc;
	
	printf("------------------\n\tFT_STRLEN\n");
	printf("MOI: %d\n", ft_strlen(argv[2]));
	printf("BIBLI: %lu\n", strlen(argv[2]));
	return (0);
}