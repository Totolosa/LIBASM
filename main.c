/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:46:05 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/02 15:06:30 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int main(int argc, char **argv)
{
	(void)argc;
	printf("---------------------------\n\tFT_STRLEN\n---------------------------\n");
	printf("MOI: %d\n", ft_strlen(argv[1]));
	printf("BIBLI: %lu\n", strlen(argv[1]));
	printf("\n");

	printf("---------------------------\n\tFT_STRCMP\n---------------------------\n");
	printf("MOI: %d\n", ft_strcmp(argv[1], argv[2]));
	printf("BIBLI: %d\n", strcmp(argv[1], argv[2]));
	printf("\n");

	printf("---------------------------\n\tFT_STRCPY\n---------------------------\n");
	char dest[100];
	printf("MOI:      dest AVANT cpy = |%s|      dest APRES cpy = |%s|\n", dest, ft_strcpy(dest, argv[2]));
	char dest2[100];
	printf("BIBLI:    dest AVANT cpy = |%s|      dest APRES cpy = |%s|\n", dest2, strcpy(dest2, argv[2]));
	printf("\n");

	return (0);
}