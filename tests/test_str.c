#include "test_framework.h"
#include "libft.h"

void	test_str(int *pass, int *fail)
{
	test_init();

	/* --- ft_strlen --- */
	printf("--- ft_strlen ---\n");
	ASSERT_EQ_SIZE(ft_strlen(""), 0);
	ASSERT_EQ_SIZE(ft_strlen("hello"), 5);
	ASSERT_EQ_SIZE(ft_strlen("a"), 1);
	ASSERT_EQ_SIZE(ft_strlen("hello world"), 11);
	ASSERT_EQ_SIZE(ft_strlen("abc\0def"), 3);

	/* --- ft_strchr --- */
	printf("--- ft_strchr ---\n");
	{
		const char *s = "hello world";
		ASSERT(ft_strchr(s, 'h') == s);
		ASSERT(ft_strchr(s, 'o') == s + 4);
		ASSERT(ft_strchr(s, 'd') == s + 10);
		ASSERT(ft_strchr(s, '\0') == s + 11);
		ASSERT_NULL(ft_strchr(s, 'z'));
		ASSERT(ft_strchr(s, 'l') == s + 2);
	}

	/* --- ft_strrchr --- */
	printf("--- ft_strrchr ---\n");
	{
		const char *s = "hello world";
		ASSERT(ft_strrchr(s, 'l') == s + 9);
		ASSERT(ft_strrchr(s, 'o') == s + 7);
		ASSERT(ft_strrchr(s, 'h') == s);
		ASSERT(ft_strrchr(s, '\0') == s + 11);
		ASSERT_NULL(ft_strrchr(s, 'z'));
	}

	/* --- ft_strncmp --- */
	printf("--- ft_strncmp ---\n");
	ASSERT_EQ_INT(ft_strncmp("abc", "abc", 3), 0);
	ASSERT_EQ_INT(ft_strncmp("abc", "abd", 3) < 0, 1);
	ASSERT_EQ_INT(ft_strncmp("abd", "abc", 3) > 0, 1);
	ASSERT_EQ_INT(ft_strncmp("abc", "abcdef", 3), 0);
	ASSERT_EQ_INT(ft_strncmp("abc", "abc", 0), 0);
	ASSERT_EQ_INT(ft_strncmp("", "", 0), 0);
	ASSERT_EQ_INT(ft_strncmp("a", "", 1) > 0, 1);
	ASSERT_EQ_INT(ft_strncmp("", "a", 1) < 0, 1);

	/* --- ft_strlcpy --- */
	printf("--- ft_strlcpy ---\n");
	{
		char dst[20];
		ASSERT_EQ_SIZE(ft_strlcpy(dst, "hello", 20), 5);
		ASSERT_EQ_STR(dst, "hello");
		ASSERT_EQ_SIZE(ft_strlcpy(dst, "hello", 3), 5);
		ASSERT_EQ_STR(dst, "he");
		ASSERT_EQ_SIZE(ft_strlcpy(dst, "hello", 1), 5);
		ASSERT_EQ_STR(dst, "");
		ASSERT_EQ_SIZE(ft_strlcpy(dst, "", 20), 0);
		ASSERT_EQ_STR(dst, "");
	}

	/* --- ft_strlcat --- */
	printf("--- ft_strlcat ---\n");
	{
		char dst[20];

		ft_strlcpy(dst, "hello", 20);
		ASSERT_EQ_SIZE(ft_strlcat(dst, " world", 20), 11);
		ASSERT_EQ_STR(dst, "hello world");

		ft_strlcpy(dst, "hello", 20);
		ASSERT_EQ_SIZE(ft_strlcat(dst, " world", 8), 11);
		ASSERT_EQ_STR(dst, "hello w");

		ft_strlcpy(dst, "hello", 20);
		ASSERT_EQ_SIZE(ft_strlcat(dst, " world", 5), 11);
		ASSERT_EQ_STR(dst, "hello");

		ft_strlcpy(dst, "hello", 20);
		ASSERT_EQ_SIZE(ft_strlcat(dst, " world", 3), 9);
	}

	/* --- ft_strdup --- */
	printf("--- ft_strdup ---\n");
	{
		char *dup;

		dup = ft_strdup("hello");
		ASSERT_EQ_STR(dup, "hello");
		free(dup);

		dup = ft_strdup("");
		ASSERT_EQ_STR(dup, "");
		free(dup);

		dup = ft_strdup("a longer test string");
		ASSERT_EQ_STR(dup, "a longer test string");
		free(dup);
	}

	/* --- ft_strnstr --- */
	printf("--- ft_strnstr ---\n");
	{
		const char *big = "hello world";

		ASSERT(ft_strnstr(big, "hello", 11) == big);
		ASSERT(ft_strnstr(big, "world", 11) == big + 6);
		ASSERT_NULL(ft_strnstr(big, "world", 5));
		ASSERT(ft_strnstr(big, "", 11) == big);
		ASSERT_NULL(ft_strnstr(big, "xyz", 11));
		ASSERT(ft_strnstr(big, "lo w", 11) == big + 3);
		ASSERT_NULL(ft_strnstr(big, "world", 10));
	}

	TEST_SUMMARY("String functions", pass, fail);
}
