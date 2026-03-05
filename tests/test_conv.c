#include "test_framework.h"
#include "libft.h"

void	test_conv(int *pass, int *fail)
{
	test_init();

	/* --- ft_atoi --- */
	printf("--- ft_atoi ---\n");
	ASSERT_EQ_INT(ft_atoi("0"), 0);
	ASSERT_EQ_INT(ft_atoi("42"), 42);
	ASSERT_EQ_INT(ft_atoi("-42"), -42);
	ASSERT_EQ_INT(ft_atoi("+42"), 42);
	ASSERT_EQ_INT(ft_atoi("   42"), 42);
	ASSERT_EQ_INT(ft_atoi("\t\n 42"), 42);
	ASSERT_EQ_INT(ft_atoi("42abc"), 42);
	ASSERT_EQ_INT(ft_atoi("2147483647"), 2147483647);
	ASSERT_EQ_INT(ft_atoi("-2147483648"), -2147483648);
	ASSERT_EQ_INT(ft_atoi("0000042"), 42);
	ASSERT_EQ_INT(ft_atoi(""), 0);
	ASSERT_EQ_INT(ft_atoi("abc"), 0);

	/* --- ft_atoi_base --- */
	printf("--- ft_atoi_base ---\n");
	ASSERT_EQ_INT(ft_atoi_base("ff", "0123456789abcdef"), 255);
	ASSERT_EQ_INT(ft_atoi_base("FF", "0123456789ABCDEF"), 255);
	ASSERT_EQ_INT(ft_atoi_base("101", "01"), 5);
	ASSERT_EQ_INT(ft_atoi_base("10", "0123456789"), 10);
	ASSERT_EQ_INT(ft_atoi_base("0", "01"), 0);
	ASSERT_EQ_INT(ft_atoi_base("-101", "01"), -5);
	ASSERT_EQ_INT(ft_atoi_base("   42", "0123456789"), 42);
	/* invalid bases */
	ASSERT_EQ_INT(ft_atoi_base("42", "0"), 0);
	ASSERT_EQ_INT(ft_atoi_base("42", ""), 0);
	ASSERT_EQ_INT(ft_atoi_base("42", "00"), 0);
	ASSERT_EQ_INT(ft_atoi_base("42", "0+"), 0);
	ASSERT_EQ_INT(ft_atoi_base("42", "0-"), 0);

	/* --- ft_atof --- */
	printf("--- ft_atof ---\n");
	ASSERT_FLOAT_EQ(ft_atof("3.14"), 3.14f, 0.01f);
	ASSERT_FLOAT_EQ(ft_atof("0.0"), 0.0f, 0.001f);
	ASSERT_FLOAT_EQ(ft_atof("-1.5"), -1.5f, 0.01f);
	ASSERT_FLOAT_EQ(ft_atof("42"), 42.0f, 0.001f);
	ASSERT_FLOAT_EQ(ft_atof("0.5"), 0.5f, 0.01f);
	ASSERT_FLOAT_EQ(ft_atof("100.25"), 100.25f, 0.01f);

	/* --- ft_itoa --- */
	printf("--- ft_itoa ---\n");
	{
		char *s;

		s = ft_itoa(0);
		ASSERT_EQ_STR(s, "0");
		free(s);

		s = ft_itoa(42);
		ASSERT_EQ_STR(s, "42");
		free(s);

		s = ft_itoa(-42);
		ASSERT_EQ_STR(s, "-42");
		free(s);

		s = ft_itoa(2147483647);
		ASSERT_EQ_STR(s, "2147483647");
		free(s);

		s = ft_itoa(-2147483648);
		ASSERT_EQ_STR(s, "-2147483648");
		free(s);

		s = ft_itoa(-1);
		ASSERT_EQ_STR(s, "-1");
		free(s);

		s = ft_itoa(1);
		ASSERT_EQ_STR(s, "1");
		free(s);

		s = ft_itoa(100);
		ASSERT_EQ_STR(s, "100");
		free(s);
	}

	TEST_SUMMARY("Conversion functions", pass, fail);
}
