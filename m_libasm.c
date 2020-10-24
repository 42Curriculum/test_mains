#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <error.h>
#include <errno.h>
#include <unistd.h>

int main()
{

	extern size_t ft_strlen(char *s);
	extern char *ft_strcpy(char *dest,const char *src);
	extern int ft_strcmp(char *s1, char *s2);
	extern size_t ft_read(int fd, char *buffer, size_t size);
	extern size_t ft_write(int fd, char *buffer, size_t size);
	extern char *ft_strdup(char *str);
//__________________________________Strlen_Tests_______________________________________________\\
//Regular string
	printf("----------------Strlen_Test----------\n");
	printf("___Regular_str_test : This is a 31 bytes long string\n\n");
	printf("Strlen output: %ld \n", strlen("This is a 31 bytes long string"));
	printf("My output: %ld \n", ft_strlen("This is a 31 bytes long string"));
//NULL string yeah can't do that cause strlen not supposed to hand that
//	printf("\n___NULL_str_test : NULL");
//	printf("Strlen output: %d \n", strlen(NULL));
//	printf("My output: %ld \n", ft_strlen(NULL));
//Empty string
	printf("\n___Empty_str_test : \"\"\n");
	printf("Strlen output: %ld \n", strlen(""));
	printf("My output: %ld \n", ft_strlen(""));
//__________________________________Strcpy_Tests_______________________________________________\\/
	char *dest_small;
	char *dest_exact;
	char *dest_big;

	dest_small = malloc(3);
	dest_exact = malloc(17);
	dest_big = malloc (42);
	printf("\n----------------Strcpy_Test----------\n");
//Regular string
	printf("\n__Regular_str_test : This is a string\n");
	printf("Strcpy output: %s\n", strcpy(dest_exact, "This is a string"));
	printf("My output: %s\n", ft_strcpy(dest_exact, "This is a string"));
//Empty string
	printf("\n__Empty_str_test : \"\"\n");
	printf("Strcpy output: %s\n", strcpy(dest_exact, ""));
	printf("My output: %s\n", ft_strcpy(dest_exact, ""));
//SmallDest
	printf("\n_Small_dest_test : This dest is way too small\n");
	printf("Strcpy output: %s\n", strcpy(dest_small, "This dest is way too small"));
	printf("My output: %s\n", ft_strcpy(dest_small, "This dest is way too small"));
//Big Dest
	printf("\n__Big_Dest_test : This dest is too big\n");
	printf("Strcpy output: %s\n", strcpy(dest_big, "This dest is too big"));
	printf("My output: %s\n", ft_strcpy(dest_big, "This dest is too big"));
//\n_________________________Strcmp_Tests_______________________________________________\\/
	printf("\n----------------Strcmp_Test----------\n");
//Equal string
	printf("___Equal_str_test : This is a string\n");
	printf("Strcpy output: %d\n", strcmp("This is a string", "This is a string"));
	printf("My output: %d\n", ft_strcmp("This is a string", "This is a string"));
//Bigger
	printf("___Bigger_str_test : abc, bcd\n");
	printf("Strcpy output: %d\n", strcmp("abc", "edf"));
	printf("My output: %d\n", ft_strcmp("abc","edf"));
//Smaller
	printf("___Smaller_str_test : bcd, abc\n");
	printf("Strcpy output: %d\n", strcmp("bcd", "abc"));
	printf("My output: %d\n", ft_strcmp("bcd","abc"));
//Empty string 1
	printf("___Empty string 1_test : "", This is a string\n");
	printf("Strcpy output: %d\n", strcmp("", "This is a string"));
	printf("My output: %d\n", ft_strcmp("","This is a string"));
//Empty string 2
	printf("___Empty string 2_test : This is a string, ""\n");
	printf("Strcpy output: %d\n", strcmp("This is a string", ""));
	printf("My output: %d\n", ft_strcmp("This is a string",""));
//Empty string 3
	printf("___Empty string 3_test : "", ""\n");
	printf("Strcpy output: %d\n", strcmp("", ""));
	printf("My output: %d\n", ft_strcmp("",""));

//__________________________________ft_read_Tests_______________________________________________\\/
	printf("\n----------------Ft_read_Test----------\n");
	int  fd;
	int myerr;
	int syserr;
	char *output_buff;
	char *my_output_buff;

	output_buff = malloc(20);
	my_output_buff = malloc(20);
	fd = open("readme", O_RDONLY);

//Existing file-----------------------------
	printf("___Exisitng_file_test : readme\n");
	syserr = 0;
	myerr = 0;

	printf("Read output: Bytes : %ld\t", read(fd, output_buff, 6));
	syserr = errno;
	printf("Syserrno : %d\n",syserr);
	errno = 0;
	printf("My output: Bytes : %ld\t", ft_read(fd, output_buff, 6));
	myerr = errno;
	printf("My errno : %d\n",myerr);
	errno = 0;

//Invalid fd-----------------------------------
	syserr = 0;
	myerr = 0;
	printf("\n___Invalid_fd_test : readme\n");

	printf("Read output: Bytes : %ld\t", read(-1, output_buff, 6));
	syserr = errno;
	printf("Syserrno : %d\n",syserr);
	errno = 0;
	printf("My output: Bytes : %ld\t", ft_read(-1, output_buff, 6));
	myerr = errno;
	printf("My errno : %d\n",myerr);
	errno = 0;
//Bigger than count --------------------------------
	syserr = 0;
	myerr = 0;
	printf("\n__Bigger_than _count_test : readme\n");

	printf("Read output (1): Bytes : %ld\t", read(fd, output_buff, 2));
	syserr = errno;
	printf("Syserrno : %d\n",syserr);
	errno = 0;

	printf("My output (1): Bytes : %ld\t", ft_read(fd, output_buff, 2));
	myerr = errno;
	printf("My errno : %d\n",myerr);
	errno = 0;

	printf("Read output (2): Bytes : %ld\t", read(fd, output_buff, 2));
	syserr = errno;
	printf("Syserrno : %d\n",syserr);
	errno = 0;

	printf("My output (2): Bytes : %ld\t", ft_read(fd, output_buff, 2));
	myerr = errno;
	printf("My errno : %d\n",myerr);
	errno = 0;
//Smaller than count-------------------------------------
	syserr = 0;
	myerr = 0;
	printf("\n__Bigger_than _count_test : readme\n");

	printf("Read output: Bytes : %ld\t", read(fd, output_buff, 12));
	syserr = errno;
	printf("Syserrno : %d\n",syserr);
	errno = 0;

	printf("My output: Bytes : %ld\t", ft_read(fd, output_buff, 12));
	myerr = errno;
	printf("My errno : %d\n",myerr);
	errno = 0;

//0 fd --------------------------------------------------------
	syserr = 0;
	myerr = 0;
	printf("\n__Stdin_test : readme\n");

	printf("Read output: Bytes : %ld\t", read(0, output_buff, 6));
	syserr = errno;
	printf("Syserrno : %d\n",syserr);
	errno = 0;

	printf("My output: Bytes : %ld\t", ft_read(0, output_buff, 6));
	myerr = errno;
	printf("My errno : %d\n",myerr);
	errno = 0;

//2 fd-------------------------------------------------------------
	syserr = 0;
	myerr = 0;
	printf("\n__Stderr_test : readme\n");

	printf("Read output: Bytes : %ld\t", read(2, output_buff, 6));
	syserr = errno;
	printf("Syserrno : %d\n",syserr);
	errno = 0;

	printf("My output: Bytes : %ld\t", ft_read(2, output_buff, 6));
	myerr = errno;
	printf("My errno : %d\n",myerr);
	errno = 0;

//Empty buffer------------------------------------------------------
	syserr = 0;
	myerr = 0;
	printf("\n__Empty_Buff : readme\n");

	printf("Read output: Bytes : %ld\t", read(0, "", 6));
	syserr = errno;
	printf("Syserrno : %d\n",syserr);
	errno = 0;

	printf("My output: Bytes : %ld\t", ft_read(0, "", 6));
	myerr = errno;
	printf("My errno : %d\n",myerr);
	errno = 0;

//__________________________________ft_write_Tests_______________________________________________\\/errno = 0;
	printf("\n----------------Ft_write_Test----------\n");
//Existing file
	syserr = 0;
	myerr = 0;
	printf("\n___Exisitng_file_test : readme\n");

	printf("%s Bytes : %ld, \n", "\nWrite output", write(fd, "readme", 6));
	syserr = errno;
	printf("Syserrno : %d\n",syserr);
	errno = 0;

	printf("%s Bytes : %ld, \n", "\nMy output:", ft_write(fd, "readme", 6));
	myerr = errno;
	printf("My errno : %d\n",myerr);
	errno = 0;

//Invalid fderrno = 0;------------------------------------------------------
	printf("\n___Invalid_fd_test : readme\n");

	printf("%s Bytes : %ld, \n", "\nWrite output :", write(-1, "readme", 6));
	syserr = errno;
	printf("Syserrno : %d\n",syserr);
	errno = 0;

	printf(" %s Bytes : %ld, \n", "\nMy output:", ft_write(-1,"readme", 6));
	myerr = errno;
	printf("My errno : %d\n",myerr);
	errno = 0;
//Bigger than counterrno = 0;----------------------------------------------
	printf("\n__Bigger_than _count_test : readme\n");

	printf(" %s Bytes : %ld, ", "\nWrite output (1) : \n", write(1, "readme", 2));
	syserr = errno;
	printf("Syserrno : %d\n",syserr);
	errno = 0;

	printf(" %s Bytes : %ld, \n", "\nMy output (1):" , ft_write(1, "readme", 2));
	myerr = errno;
	printf("My errno : %d\n",myerr);
	errno = 0;

	printf(" %s Bytes : %ld, ", "\nWrite output (2):\n", write(1, "readme", 2));
	syserr = errno;
	printf("Syserrno : %d\n",syserr);
	errno = 0;

	printf(" %s Bytes : %ld, \n", "\nMy output (2):", ft_write(1, "readme", 2));
	myerr = errno;
	printf("My errno : %d\n",myerr);
	errno = 0;

//Smaller than counterrno = 0;------------------------------------------------
	printf("\n___Bigger_than _count_test : readme\n");

	printf("%s Bytes : %ld, \n","\nWrite output :", write(1, "readme", 12));
	syserr = errno;
	printf("Syserrno : %d\n",syserr);
	errno = 0;

	printf(" %s Bytes : %ld, \n", "\nMy output:", ft_write(1, "readme", 12));
	myerr = errno;
	printf("My errno : %d\n",myerr);
	errno = 0;

//0 fd-------------------------------------------------------------------------
	printf("\n___Stdin_test : readme\n");

	printf("%s Bytes : %ld, \n","\nWrite output :", write(0, "readme", 6));
	syserr = errno;
	printf("Syserrno : %d\n",syserr);
	errno = 0;

	printf(" %s Bytes : %ld, \n",  "\nMy output:",ft_write(0, "readme", 6));
	myerr = errno;
	printf("My errno : %d\n",myerr);
	errno = 0;

//2errno = 0; ---------------------------------------------------------------------------
	printf("\n___Stderr_test : readme\n");

	printf("%s Bytes : %ld, \n","\nWrite output :", write(2, "readme", 6));
	syserr = errno;
	printf("Syserrno : %d\n",syserr);
	errno = 0;

	printf(" %s Bytes : %ld, \n", "\nMy output:", ft_write(2, "readme", 6));
	myerr = errno;
	printf("My errno : %d\n",myerr);
	errno = 0;

//NULL buffererrno = 0--------------------------------------------------------------------
	printf("\n___NULL_Buff_test : readme\n");

	printf("%s Bytes : %ld, \n","\nWrite output :", write(1, NULL, 6));
	syserr = errno;
	printf("Syserrno : %d\n",syserr);
	errno = 0;

	printf(" %s Bytes : %ld, \n", "\nMy output:", ft_write(1, NULL, 6));
	myerr = errno;
	printf("My errno : %d\n",myerr);
	errno = 0;

//Empty buffererrno = 0------------------------------------------------------------------
	printf("\n___Empty_Buff : readme\n");
	printf("%s Bytes : %ld, \n","\nWrite output :", write(1, "", 6));
	syserr = errno;
	printf("Syserrno : %d\n",syserr);
	errno = 0;

	printf(" %s Bytes : %ld, \n", "\nMy output:", ft_write(1, "", 6));
	myerr = errno;
	printf("My errno : %d\n",myerr);
	errno = 0;
//__________________________________Strdup_Tests_______________________________________________\\/
	printf("\n----------------Strdup_Test----------\n");
//Regular string
	printf("\n___Regular_str_test : This is a 31 bytes long string\n");
	printf("Strdup output: %s \n", strdup("This is a 31 bytes long string"));
	printf("My output: %s \n", ft_strdup("This is a 31 bytes long string"));
//Empty string
	printf("\n___Empty_str_test : ""\n");
	printf("Strdup output: %s \n", strdup(""));
	printf("My output: %s \n", ft_strdup(""));
	return 0;
}
