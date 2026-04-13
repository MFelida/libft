#include "test_framework.h"
#include "libft.h"

void	test_char(int *pass, int *fail)
{
	test_init();
	printf("--- ft_isalpha ---\n");
	ASSERT(ft_isalpha('a'));
	ASSERT(ft_isalpha('z'));
	ASSERT(ft_isalpha('A'));
	ASSERT(ft_isalpha('Z'));
	ASSERT(ft_isalpha('m'));
	ASSERT(!ft_isalpha('0'));
	ASSERT(!ft_isalpha('9'));
	ASSERT(!ft_isalpha(' '));
	ASSERT(!ft_isalpha('\0'));
	ASSERT(!ft_isalpha('@'));
	ASSERT(!ft_isalpha('['));

	printf("--- ft_isdigit ---\n");
	ASSERT(ft_isdigit('0'));
	ASSERT(ft_isdigit('5'));
	ASSERT(ft_isdigit('9'));
	ASSERT(!ft_isdigit('a'));
	ASSERT(!ft_isdigit('/'));
	ASSERT(!ft_isdigit(':'));
	ASSERT(!ft_isdigit(' '));

	printf("--- ft_isalnum ---\n");
	ASSERT(ft_isalnum('a'));
	ASSERT(ft_isalnum('Z'));
	ASSERT(ft_isalnum('0'));
	ASSERT(ft_isalnum('9'));
	ASSERT(!ft_isalnum(' '));
	ASSERT(!ft_isalnum('!'));
	ASSERT(!ft_isalnum('\n'));

	printf("--- ft_isascii ---\n");
	ASSERT(ft_isascii(0));
	ASSERT(ft_isascii(127));
	ASSERT(ft_isascii('a'));
	ASSERT(ft_isascii(65));
	ASSERT(!ft_isascii(128));
	ASSERT(!ft_isascii(-1));
	ASSERT(!ft_isascii(200));

	printf("--- ft_isprint ---\n");
	ASSERT(ft_isprint(' '));
	ASSERT(ft_isprint('~'));
	ASSERT(ft_isprint('a'));
	ASSERT(ft_isprint('0'));
	ASSERT(!ft_isprint('\0'));
	ASSERT(!ft_isprint(127));
	ASSERT(!ft_isprint('\t'));
	ASSERT(!ft_isprint(31));

	printf("--- ft_isspace ---\n");
	ASSERT(ft_isspace(' '));
	ASSERT(ft_isspace('\t'));
	ASSERT(ft_isspace('\n'));
	ASSERT(ft_isspace('\v'));
	ASSERT(ft_isspace('\f'));
	ASSERT(ft_isspace('\r'));
	ASSERT(!ft_isspace('a'));
	ASSERT(!ft_isspace('0'));
	ASSERT(!ft_isspace('\0'));

	printf("--- ft_toupper ---\n");
	ASSERT_EQ_INT(ft_toupper('a'), 'A');
	ASSERT_EQ_INT(ft_toupper('z'), 'Z');
	ASSERT_EQ_INT(ft_toupper('m'), 'M');
	ASSERT_EQ_INT(ft_toupper('A'), 'A');
	ASSERT_EQ_INT(ft_toupper('0'), '0');
	ASSERT_EQ_INT(ft_toupper(' '), ' ');

	printf("--- ft_tolower ---\n");
	ASSERT_EQ_INT(ft_tolower('A'), 'a');
	ASSERT_EQ_INT(ft_tolower('Z'), 'z');
	ASSERT_EQ_INT(ft_tolower('M'), 'm');
	ASSERT_EQ_INT(ft_tolower('a'), 'a');
	ASSERT_EQ_INT(ft_tolower('0'), '0');
	ASSERT_EQ_INT(ft_tolower(' '), ' ');

	TEST_SUMMARY("Character functions", pass, fail);
}
