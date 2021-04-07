/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:46:05 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/07 21:17:34 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void check_strlen()
{
	char empty[] = "";
	char big[] = "012345678901234567890123456789012345678901234567890123456789";

	printf("\033[1m\033[34m---------------------------\n\t\033[36mFT_STRLEN\033[34m\n---------------------------\033[37m\n");
	printf("\n\033[1m\033[33m\"%s\"\033[0m :\n", empty);
	printf("	> MOI:     \033[32m|%lu|\033[0m\n", ft_strlen(empty));
	printf("	> BIBLI:   \033[32m|%lu|\033[0m\n", strlen(empty));
	printf("\n\033[1m\033[33m\"%s\"\033[0m :\n", big);
	printf("	> MOI:     \033[32m|%lu|\033[0m\n", ft_strlen(big));
	printf("	> BIBLI:   \033[32m|%lu|\033[0m\n", strlen(big));
	printf("\n\n");
}

void check_strcmp()
{
	char str1[] = "";
	char str2[] = "";
	char str3[] = "";
	char str4[] = "Premier parametre vide";
	char str5[] = "Deuxieme parametre vide";
	char str6[] = "";
	char str7[] = "Fais toi un kiff";
	char str8[] = "Fais toi un kiff";

	printf("\033[1m\033[34m---------------------------\n\t\033[36mFT_STRCMP\033[34m\n---------------------------\033[37m\n");
	printf("\n\033[1m\033[33m\"%s\"\033[0m comp to \033[1m\033[33m\"%s\"\033[0m :\n", str1, str2);
	printf("	> MOI:     \033[32m|%d|\033[0m\n", ft_strcmp(str1, str2));
	printf("	> BIBLI:   \033[32m|%d|\033[0m\n", strcmp(str1, str2));
	printf("\n\033[1m\033[33m\"%s\"\033[0m comp to \033[1m\033[33m\"%s\"\033[0m :\n", str3, str4);
	printf("	> MOI:     \033[32m|%d|\033[0m\n", ft_strcmp(str3, str4));
	printf("	> BIBLI:   \033[32m|%d|\033[0m\n", strcmp(str3, str4));
	printf("\n\033[1m\033[33m\"%s\"\033[0m comp to \033[1m\033[33m\"%s\"\033[0m :\n", str5, str6);
	printf("	> MOI:     \033[32m|%d|\033[0m\n", ft_strcmp(str5, str6));
	printf("	> BIBLI:   \033[32m|%d|\033[0m\n", strcmp(str5, str6));
	printf("\n\033[1m\033[33m\"%s\"\033[0m comp to \033[1m\033[33m\"%s\"\033[0m :\n", str7, str8);
	printf("	> MOI:     \033[32m|%d|\033[0m\n", ft_strcmp(str7, str8));
	printf("	> BIBLI:   \033[32m|%d|\033[0m\n", strcmp(str7, str8));
	printf("\n\n");
}

void check_strcpy()
{
	char buff[1000];
	char empty[] = "";
	char big[] = "Une looooooooooooooooongue phrase";

	printf("\033[1m\033[34m---------------------------\n\t\033[36mFT_STRCPY\033[34m\n---------------------------\033[37m\n");
	printf("\n\033[1m\033[33m\"%s\"\033[0m :\n", empty);
	printf("	> MOI:     \033[32m|%s|\033[0m\n", ft_strcpy(buff, empty));
	printf("	> BIBLI:   \033[32m|%s|\033[0m\n", strcpy(buff, empty));
	printf("\n\033[1m\033[33m\"%s\"\033[0m :\n", big);
	printf("	> MOI:     \033[32m|%s|\033[0m\n", ft_strcpy(buff, big));
	printf("	> BIBLI:   \033[32m|%s|\033[0m\n", strcpy(buff, big));
	printf("\n\n");
}

void check_write()
{
	long ret = 0;
	int fd = open("tests/write.txt", O_RDWR);
	char str1[] = "Belle ecriture dis donc";
	char str2[] = "Merci c'est gentil";
	char str3[] = "Y'a pas de quoi l'ami";

	printf("\033[1m\033[34m---------------------------\n\t\033[36mFT_WRITE\033[34m\n---------------------------\033[37m\n");
	errno = 0;
	printf("\n\033[1m\033[33m\"%s\"\033[0m on \033[1m\033[33m%s\033[0m:\n", str1, "STDOUT");
	printf("	> MOI:     |");
	printf("|     ret = \033[32m|%ld|\033[0m\n", ret = ft_write(1, str1, ft_strlen(str1)));
	if (ret == -1)
		perror("ERROR");
	printf("	> BIBLI:   |");
	printf("|     ret = \033[32m|%ld|\033[0m\n", ret = write(1, str1, ft_strlen(str1)));
	if (ret == -1)
		perror("ERROR");
	errno = 0;
	printf("\n\033[1m\033[33m\"%s\"\033[0m on \033[1m\033[33m%s\033[0m:\n", str2, "file tests/write.txt");
	printf("	> MOI:     |");
	printf("|     ret = \033[32m|%ld|\033[0m\n", ret = ft_write(fd, str2, ft_strlen(str2)));
	if (ret == -1)
		perror("ERROR");
	printf("	> BIBLI:   |");
	printf("|     ret = \033[32m|%ld|\033[0m\n", ret = write(fd, str2, ft_strlen(str2)));
	if (ret == -1)
		perror("ERROR");
	errno = 0;
	printf("\n\033[1m\033[33m\"%s\"\033[0m on \033[1m\033[33m%s\033[0m:\n", str3, "fd = 42");
	printf("	> MOI:     |");
	printf("|     ret = \033[32m|%ld|\033[0m\n", ret = ft_write(42, str3, ft_strlen(str3)));
	if (ret == -1)
		perror("ERROR");
	printf("	> BIBLI:   |");
	printf("|     ret = \033[32m|%ld|\033[0m\n", ret = write(42, str3, ft_strlen(str3)));
	if (ret == -1)
		perror("ERROR");
	if (fd > 2)
		close(fd);
	printf("\n\n");
}

void check_read()
{
	long ret = 0;
	int fd_me = open("tests/my_read.txt", O_RDWR);
	int fd_lib = open("tests/lib_read.txt", O_RDWR);
	#define BUFF_LEN 42
	char buff[BUFF_LEN];

	printf("\033[1m\033[34m---------------------------\n\t\033[36mFT_READ\033[34m\n---------------------------\033[37m\n");
	errno = 0;
	printf("\n\033[1m\033[33m%s\033[0m on \033[1m\033[33m%s\033[0m:\n", "Read", "STDIN");
	printf("	> MOI:     ");
	printf("	ret = \033[32m|%ld|\033[0m\n", ret = ft_read(0, buff, BUFF_LEN));
	if (ret == -1)
		perror("ERROR");
	printf("	> BIBLI:   ");
	printf("	ret = \033[32m|%ld|\033[0m\n", ret = read(0, buff, BUFF_LEN));
	if (ret == -1)
		perror("ERROR");
	errno = 0;
	printf("\n\033[1m\033[33m%s\033[0m on \033[1m\033[33m%s\033[0m:\n", "Read", "file tests/write.txt");
	printf("	> MOI:     |");
	printf("|     ret = \033[32m|%ld|\033[0m\n", ret = ft_read(fd_me, buff, BUFF_LEN));
	if (ret == -1)
		perror("ERROR");
	printf("	> BIBLI:   |");
	printf("|     ret = \033[32m|%ld|\033[0m\n", ret = read(fd_lib, buff, BUFF_LEN));
	if (ret == -1)
		perror("ERROR");
	errno = 0;
	printf("\n\033[1m\033[33m%s\033[0m on \033[1m\033[33m%s\033[0m:\n", "Read", "fd = 42");
	printf("	> MOI:     |");
	printf("|     ret = \033[32m|%ld|\033[0m\n", ret = ft_read(42, buff, BUFF_LEN));
	if (ret == -1)
		perror("ERROR");
	printf("	> BIBLI:   |");
	printf("|     ret = \033[32m|%ld|\033[0m\n", ret = read(42, buff, BUFF_LEN));
	if (ret == -1)
		perror("ERROR");
	if (fd_me > 2)
		close(fd_me);
	if (fd_lib > 2)
		close(fd_lib);
	printf("\n\n");
}

void check_strdup()
{
	char *empty = "";
	char *big = "C'est preeeeeeeeeeeeeeeeeeeesque fini ;)";
	char *my_dest = NULL;
	char *lib_dest = NULL;

	printf("\033[1m\033[34m---------------------------\n\t\033[36mFT_STRDUP\033[34m\n---------------------------\033[37m\n");
	printf("\nStrdup the string \033[1m\033[33m\"%s\"\033[0m :\n", empty);
	printf("	> MOI:     \033[32m|%s|\033[0m\n", my_dest = ft_strdup(empty));
	printf("	> BIBLI:   \033[32m|%s|\033[0m\n", lib_dest = strdup(empty));
	printf("\nStrdup the string \033[1m\033[33m\"%s\"\033[0m :\n", big);
	printf("	> MOI:     \033[32m|%s|\033[0m\n", lib_dest = my_dest = ft_strdup(big));
	printf("	> BIBLI:   \033[32m|%s|\033[0m\n", strdup(big));
	printf("\n\n");
}

int main(int argc, char **argv)
{
	setbuf(stdout, NULL);
	if (argc == 1 || !ft_strcmp(argv[1], "ft_strlen"))
		check_strlen();
	if (argc == 1 || !ft_strcmp(argv[1], "ft_strcmp"))
		check_strcmp();
	if (argc == 1 || !ft_strcmp(argv[1], "ft_strcpy"))
		check_strcpy();
	if (argc == 1 || !ft_strcmp(argv[1], "ft_write"))
		check_write();
	if (argc == 1 || !ft_strcmp(argv[1], "ft_read"))
		check_read();
	if (argc == 1 || !ft_strcmp(argv[1], "ft_strdup"))
		check_strdup();
	return (0);
}
