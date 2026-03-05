#include "test_framework.h"
#include <stdio.h>

/* Test suite declarations */
void	test_char(int *pass, int *fail);
void	test_str(int *pass, int *fail);
void	test_str_alloc(int *pass, int *fail);
void	test_mem(int *pass, int *fail);
void	test_conv(int *pass, int *fail);
void	test_output(int *pass, int *fail);
void	test_lst(int *pass, int *fail);
void	test_gnl(int *pass, int *fail);

int	main(void)
{
	int	pass;
	int	fail;
	int	total_pass;
	int	total_fail;

	total_pass = 0;
	total_fail = 0;
	printf("========================================\n");
	printf("         LIBFT UNIT TEST SUITE\n");
	printf("========================================\n\n");

	test_char(&pass, &fail);
	total_pass += pass;
	total_fail += fail;
	printf("\n");

	test_str(&pass, &fail);
	total_pass += pass;
	total_fail += fail;
	printf("\n");

	test_str_alloc(&pass, &fail);
	total_pass += pass;
	total_fail += fail;
	printf("\n");

	test_mem(&pass, &fail);
	total_pass += pass;
	total_fail += fail;
	printf("\n");

	test_conv(&pass, &fail);
	total_pass += pass;
	total_fail += fail;
	printf("\n");

	test_output(&pass, &fail);
	total_pass += pass;
	total_fail += fail;
	printf("\n");

	test_lst(&pass, &fail);
	total_pass += pass;
	total_fail += fail;
	printf("\n");

	test_gnl(&pass, &fail);
	total_pass += pass;
	total_fail += fail;
	printf("\n");

	printf("========================================\n");
	if (total_fail == 0)
		printf(CLR_GREEN "ALL TESTS PASSED" CLR_RESET
			": %d/%d\n", total_pass, total_pass + total_fail);
	else
		printf(CLR_RED "SOME TESTS FAILED" CLR_RESET
			": %d/%d passed, %d failed\n",
			total_pass, total_pass + total_fail, total_fail);
	printf("========================================\n");
	return (total_fail > 0 ? 1 : 0);
}
