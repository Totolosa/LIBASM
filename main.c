/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:46:05 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/07 12:24:33 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int main()
{
	setbuf(stdout, NULL);
	long int ret = 0;
	
	//	--> FT_STRLEN <--
	char str_strlen[] = "0123456789";
	// char *str_strlen = NULL;

	//	--> FT_STRCMP <--
	char str1_strcmp[] = "0";
	char str2_strcmp[] = "9";
	// char *str1_strcmp = NULL;
	// char *str2_strcmp = NULL;
	
	//	--> FT_STRCPY <--
	char my_dest_strcpy[] = "XXXXXXXXXXXXXXXXXXX";
	char lib_dest_strcpy[] = "XXXXXXXXXXXXXXXXXXX";
	char src_strcpy[] = "Aller le stade";
	// char *my_dest_strcpy = NULL;
	// char *lib_dest_strcpy = NULL;
	// char *src_strcpy = NULL;

	//	--> FT_WRITE <--
	int fd_write = 1;
	// fd_write = open("files/test_write.txt", O_RDWR);
	char *str_write = "Bien le bonjour";

	//	--> FT_READ <--
	int fd_my_read;
	int fd_lib_read;
	fd_my_read = open("files/test_my_read.txt", O_RDONLY);
	fd_lib_read = open("files/test_lib_read.txt", O_RDONLY);
	#define BUFF_LEN 42
	char buff[BUFF_LEN];
	
	//	--> FT_STRDUP <--
	char *str_src_strdup = "TEST";
	char *my_dest_strdup = NULL;
	char *lib_dest_strdup = NULL;

	printf("\033[34m---------------------------\n\t\033[36mFT_STRLEN\033[34m\n---------------------------\033[37m\n");
	printf("MOI:     %d\n", ft_strlen(str_strlen));
	errno = 0;
	printf("BIBLI:   %lu\n", strlen(str_strlen));
	printf("\n");

	printf("\033[34m---------------------------\n\t\033[36mFT_STRCMP\033[34m\n---------------------------\033[37m\n");
	printf("MOI:     %d\n", ft_strcmp(str1_strcmp, str2_strcmp));
	printf("BIBLI:   %d\n", strcmp(str1_strcmp, str2_strcmp));
	printf("\n");

	printf("\033[34m---------------------------\n\t\033[36mFT_STRCPY\033[34m\n---------------------------\033[37m\n");
	printf("MOI:     dest AVANT = |%s|      ", my_dest_strcpy);
	printf("dest APRES = |%s|\n", ft_strcpy(my_dest_strcpy, src_strcpy));
	printf("BIBLI:   dest AVANT = |%s|      ", lib_dest_strcpy);
	printf("dest APRES = |%s|\n", strcpy(lib_dest_strcpy, src_strcpy));
	printf("\n");

	
	printf("\033[34m---------------------------\n\t\033[36mFT_WRITE\033[34m\n---------------------------\033[37m\n");
	// printf("fd_write = %d\n", fd_write);
	printf("MOI:     |");
	errno = 0;
	printf("|     ret = %ld\n", ret = ft_write(fd_write, str_write, ft_strlen(str_write)));
	if (ret == -1)
		perror("ERROR");
	printf("BIBLI:   |");
	errno = 0;
	printf("|     ret = %ld\n", ret = write(fd_write, str_write, ft_strlen(str_write)));
	if (ret == -1)
		perror("ERROR");
	printf("\n");
	if (fd_write > 1)
		close(fd_write);

	printf("\033[34m---------------------------\n\t\033[36mFT_READ\033[34m\n---------------------------\033[37m\n");
	printf("MOI:");
	errno = 0;
	printf("     ret = %ld\n", ret = ft_read(fd_my_read, buff, BUFF_LEN));
	if (ret == -1)
		perror("ERROR");
	printf("BIBLI:");
	errno = 0;
	printf("   ret = %ld\n", ret = read(fd_lib_read, buff, BUFF_LEN));
	if (ret == -1)
		perror("ERROR");
	printf("\n");

	printf("\033[34m---------------------------\n\t\033[36mFT_STRDUP\033[34m\n---------------------------\033[37m\n");
	printf("MOI:     ");
	errno = 0;
	printf("dest = |%s|\n", my_dest_strdup = ft_strdup(str_src_strdup));
	if (my_dest_strdup == NULL)
		perror("ERROR");
	if (my_dest_strdup != NULL)
		free(my_dest_strdup);
	printf("BIBLI:   ");
	errno = 0;
	printf("dest = |%s|\n", lib_dest_strdup = strdup(str_src_strdup));
	if (lib_dest_strdup == NULL)
		perror("ERROR");
	printf("\n");
	if (lib_dest_strdup != NULL)
		free(lib_dest_strdup);

	return (0);
}
