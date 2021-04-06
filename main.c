/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <tdayde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:46:05 by tdayde            #+#    #+#             */
/*   Updated: 2021/04/06 19:09:31 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int main()
{
	setbuf(stdout, NULL);
	long int ret = 0;
	
	//	--> FT_STRLEN <--
	char str_strlen[] = "0123456789";

	//	--> FT_STRCMP <--
	char str1_strcmp[] = "0";
	char str2_strcmp[] = "9";
	
	//	--> FT_STRCPY <--
	char my_dest_strcpy[] = "XXXXXXXXXXXXXXXXXXX";
	char lib_dest_strcpy[] = "XXXXXXXXXXXXXXXXXXX";
	char src_strcpy[] = "Aller le stade";

	//	--> FT_WRITE <--
	int fd_write = 1;
	char *str_write = "Bien le bonjour";

	//	--> FT_READ <--
	int fd_read = open("test.txt", O_RDONLY);
	#define BUFF_LEN 42
	char buff[BUFF_LEN];
	
	//	--> FT_STRDUP <--
	char *str_src_strdup = "TEST";
	char *my_dest_strdup;
	char *lib_dest_strdup;

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

	printf("\033[34m---------------------------\n\t\033[36mFT_READ\033[34m\n---------------------------\033[37m\n");
	printf("MOI:");
	errno = 0;
	printf("     ret = %ld\n", ret = ft_read(fd_read, buff, BUFF_LEN));
	if (ret == -1)
		perror("ERROR");
	printf("BIBLI:");
	errno = 0;
	printf("   ret = %ld\n", ret = read(fd_read, buff, BUFF_LEN));
	if (ret == -1)
		perror("ERROR");
	printf("\n");

	printf("\033[34m---------------------------\n\t\033[36mFT_STRDUP\033[34m\n---------------------------\033[37m\n");
	printf("MOI:     ");
	errno = 0;
	printf("dest = |%s|\n", my_dest_strdup = ft_strdup(str_src_strdup));
	if (my_dest_strdup == NULL)
		perror("ERROR");
	free(my_dest_strdup);
	printf("BIBLI:   ");
	errno = 0;
	printf("dest = |%s|\n", lib_dest_strdup = strdup(str_src_strdup));
	if (lib_dest_strdup == NULL)
		perror("ERROR");
	printf("\n");
	free(lib_dest_strdup);

	return (0);
}
