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

int main()
{
	setbuf(stdout, NULL);
	long int ret = 0; 
	char str1[20] = "0123456789";
	char str2[20] = "XXXXXXXXXXXXXX";
	char str3[20] = "XXXXXXXXXXXXX0";
	char str4[20] = "Aller le stade";
	#define BUFF_LEN 42
	char buff[BUFF_LEN];
	int fd = -1;

	printf("---------------------------\n\tFT_STRLEN\n---------------------------\n");
	printf("MOI:   %d\n", ft_strlen(str1));
	errno = 0;
	printf("BIBLI: %lu\n", strlen(str1));
	printf("\n");

	printf("---------------------------\n\tFT_STRCMP\n---------------------------\n");
	printf("MOI:   %d\n", ft_strcmp(str2, str3));
	printf("BIBLI: %d\n", strcmp(str2, str3));
	printf("\n");

	printf("---------------------------\n\tFT_STRCPY\n---------------------------\n");
	char dest[100] = "XXXXXXXXXXXXXXXXXXX";
	printf("MOI:      dest AVANT = |%s|      ", dest);
	printf("dest APRES = |%s|\n", ft_strcpy(dest, str4));
	char dest2[100] = "XXXXXXXXXXXXXXXXXXX";
	printf("BIBLI:    dest AVANT = |%s|      ", dest2);
	printf("dest APRES = |%s|\n", strcpy(dest2, str4));
	printf("\n");

	
	printf("---------------------------\n\tFT_WRITE\n---------------------------\n");
	printf("MOI:     ");
	errno = 0;
	printf("     ret = %ld\n", ret = ft_write(fd, str4, ft_strlen(str4)));
	if (ret == -1)
		perror("ERROR");
	printf("BIBLI:   ");
	errno = 0;
	printf("     ret = %ld\n", ret = write(fd, str4, ft_strlen(str4)));
	if (ret == -1)
		perror("ERROR");
	printf("\n");

	printf("---------------------------\n\tFT_READ\n---------------------------\n");
	printf("MOI:     ");
	fd = open("test.txt", O_RDONLY);
	printf("fd = %d\n", fd);
	errno = 0;
	printf("     ret = %ld\n", ret = ft_read(fd, buff, BUFF_LEN));
	if (ret == -1)
		perror("ERROR");
	printf("BIBLI:   ");
	errno = 0;
	printf("     ret = %ld\n", ret = read(fd, buff, BUFF_LEN));
	if (ret == -1)
		perror("ERROR");
	printf("\n");

	return (0);
}
