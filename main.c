/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:46:05 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/04 16:07:28 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void		ft_check_strcpy(void)
{
	char	str1[] = "Bonjour";
	char	str2[] = "Hello";
	char	str3[] = "libc most power full";
	char	str4[] = "libasm is for the ";
	char	str5[] = "petit";
	char	str6[] = "grand";
	char	str7[] = "";
	printf("============================================\n");
	printf("================ Ft_strcpy =================\n");
	printf("============================================\n\n");
	printf("\033[36mresultat : libasm\033[00m\n");
	printf("return : |%s|\n", ft_strcpy(str1, str2));
	printf("\033[36mresultat : libc\033[00m\n");
	printf("return : |%s|\n\n", strcpy(str1, str2));
	printf("\033[36mresultat : libasm\033[00m\n");
	printf("return : |%s|\n", ft_strcpy(str3, str4));
	printf("\033[36mresultat : libc\033[00m\n");
	printf("return : |%s|\n\n", strcpy(str3, str4));
	printf("\033[36mresultat : libasm\033[00m\n");
	printf("return : |%s|\n", ft_strcpy(str5, str6));
	printf("\033[36mresultat : libc\033[00m\n");
	printf("return : |%s|\n\n", strcpy(str5, str6));
	printf("\033[36mresultat : libasm\033[00m\n");
	printf("return : |%s|\n", ft_strcpy(str6, str7));
	printf("\033[36mresultat : libc\033[00m\n");
	printf("return : |%s|\n\n", strcpy(str6, str7));
	printf("\033[36mresultat : libasm\033[00m\n");
	printf("return : |%s|\n", ft_strcpy(str7, str6));
	printf("\033[36mresultat : libc\033[00m\n");
	printf("return : |%s|\n\n", strcpy(str7, str6));
}

int main(int argc, char **argv)
{
	int i;
	(void)i;
	(void)argc;
	setbuf(stdout, NULL);
	printf("---------------------------\n\tFT_STRLEN\n---------------------------\n");
	printf("MOI: %d\n", ft_strlen(argv[1]));
	printf("BIBLI: %lu\n", strlen(argv[1]));
	printf("\n");

	printf("---------------------------\n\tFT_STRCMP\n---------------------------\n");
	printf("MOI: %d\n", ft_strcmp(argv[1], argv[2]));
	printf("BIBLI: %d\n", strcmp(argv[1], argv[2]));
	printf("\n");

//	ft_check_strcpy();

	printf("---------------------------\n\tFT_STRCPY\n---------------------------\n");
	char dest[100] = "XXXXXXXXXXXXXXXXXXX";
//	const char test[15] = "Aller le stade";
	// char *dest;
	// dest = malloc (20);
	// for (i = 0; i < 20; i++)
	// 	dest[i] = 'X';
	// dest[i] = 0;
	printf("MOI:      dest AVANT = |%s|      ", dest);
	// dest = ft_strcpy(dest, test);
	printf("dest APRES = |%s|\n", ft_strcpy(dest, argv[2]));
	char dest2[100] = "XXXXXXXXXXXXXXXXXXX";
	printf("BIBLI:    dest AVANT = |%s|      ", dest2);
	printf("dest APRES = |%s|\n", strcpy(dest2, argv[2]));
	printf("\n");

	return (0);
}
