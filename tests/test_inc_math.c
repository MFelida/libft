#include "test_framework.h"
#include "libft.h"

void	test_inc_math(int *pass, int *fail)
{
	test_init();

	/* --- ft_ftoa --- */
	printf("--- ft_ftoa ---\n");
	{
		char *s;

		s = ft_ftoa(3.14f, 2);
		ASSERT_NOT_NULL(s);
		ASSERT_EQ_STR(s, "3.14");
		free(s);

		s = ft_ftoa(0.0f, 1);
		ASSERT_NOT_NULL(s);
		ASSERT_EQ_STR(s, "0.0");
		free(s);

		s = ft_ftoa(42.0f, 0);
		ASSERT_NOT_NULL(s);
		ASSERT_EQ_STR(s, "42");
		free(s);

		s = ft_ftoa(1.5f, 1);
		ASSERT_NOT_NULL(s);
		ASSERT_EQ_STR(s, "1.5");
		free(s);

		s = ft_ftoa(-1.5f, 1);
		ASSERT_NOT_NULL(s);
		ASSERT_EQ_STR(s, "-1.5");
		free(s);
	}

	TEST_SUMMARY("inc_math functions", pass, fail);
}
