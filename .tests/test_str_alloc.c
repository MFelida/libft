#include "test_framework.h"
#include "libft.h"

static char	to_upper_map(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

static void	to_upper_iter(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

void	test_str_alloc(int *pass, int *fail)
{
	test_init();

	/* --- ft_substr --- */
	printf("--- ft_substr ---\n");
	{
		char *s;

		s = ft_substr("hello world", 0, 5);
		ASSERT_EQ_STR(s, "hello");
		free(s);

		s = ft_substr("hello world", 6, 5);
		ASSERT_EQ_STR(s, "world");
		free(s);

		s = ft_substr("hello", 0, 100);
		ASSERT_EQ_STR(s, "hello");
		free(s);

		s = ft_substr("hello", 10, 5);
		ASSERT_EQ_STR(s, "");
		free(s);

		s = ft_substr("hello", 1, 3);
		ASSERT_EQ_STR(s, "ell");
		free(s);

		s = ft_substr("hello", 0, 0);
		ASSERT_EQ_STR(s, "");
		free(s);
	}

	/* --- ft_strjoin --- */
	printf("--- ft_strjoin ---\n");
	{
		char *s;

		s = ft_strjoin("hello", " world");
		ASSERT_EQ_STR(s, "hello world");
		free(s);

		s = ft_strjoin("", "world");
		ASSERT_EQ_STR(s, "world");
		free(s);

		s = ft_strjoin("hello", "");
		ASSERT_EQ_STR(s, "hello");
		free(s);

		s = ft_strjoin("", "");
		ASSERT_EQ_STR(s, "");
		free(s);
	}

	/* --- ft_strtrim --- */
	printf("--- ft_strtrim ---\n");
	{
		char *s;

		s = ft_strtrim("  hello  ", " ");
		ASSERT_EQ_STR(s, "hello");
		free(s);

		s = ft_strtrim("xxhelloxx", "x");
		ASSERT_EQ_STR(s, "hello");
		free(s);

		s = ft_strtrim("hello", "");
		ASSERT_EQ_STR(s, "hello");
		free(s);

		s = ft_strtrim("", "abc");
		ASSERT_EQ_STR(s, "");
		free(s);

		s = ft_strtrim("aaa", "a");
		ASSERT_EQ_STR(s, "");
		free(s);

		s = ft_strtrim("abcHELLOcba", "abc");
		ASSERT_EQ_STR(s, "HELLO");
		free(s);
	}

	/* --- ft_split --- */
	printf("--- ft_split ---\n");
	{
		char **res;

		res = ft_split("hello world foo", ' ');
		ASSERT_NOT_NULL(res);
		ASSERT_EQ_STR(res[0], "hello");
		ASSERT_EQ_STR(res[1], "world");
		ASSERT_EQ_STR(res[2], "foo");
		ASSERT_NULL(res[3]);
		ft_split_free(res);

		res = ft_split("  hello  world  ", ' ');
		ASSERT_NOT_NULL(res);
		ASSERT_EQ_STR(res[0], "hello");
		ASSERT_EQ_STR(res[1], "world");
		ASSERT_NULL(res[2]);
		ft_split_free(res);

		res = ft_split("", ' ');
		ASSERT_NOT_NULL(res);
		ASSERT_NULL(res[0]);
		ft_split_free(res);

		res = ft_split("   ", ' ');
		ASSERT_NOT_NULL(res);
		ASSERT_NULL(res[0]);
		ft_split_free(res);

		res = ft_split("hello", ' ');
		ASSERT_NOT_NULL(res);
		ASSERT_EQ_STR(res[0], "hello");
		ASSERT_NULL(res[1]);
		ft_split_free(res);

		res = ft_split("a,b,,c,", ',');
		ASSERT_NOT_NULL(res);
		ASSERT_EQ_STR(res[0], "a");
		ASSERT_EQ_STR(res[1], "b");
		ASSERT_EQ_STR(res[2], "c");
		ASSERT_NULL(res[3]);
		ft_split_free(res);
	}

	/* --- ft_split_free --- */
	printf("--- ft_split_free ---\n");
	ASSERT_NULL(ft_split_free(NULL));

	/* --- ft_strmapi --- */
	printf("--- ft_strmapi ---\n");
	{
		char *s;

		s = ft_strmapi("hello", to_upper_map);
		ASSERT_EQ_STR(s, "HELLO");
		free(s);

		s = ft_strmapi("", to_upper_map);
		ASSERT_EQ_STR(s, "");
		free(s);

		s = ft_strmapi("abc123", to_upper_map);
		ASSERT_EQ_STR(s, "ABC123");
		free(s);
	}

	/* --- ft_striteri --- */
	printf("--- ft_striteri ---\n");
	{
		char s1[] = "hello";
		ft_striteri(s1, to_upper_iter);
		ASSERT_EQ_STR(s1, "HELLO");

		char s2[] = "abc123";
		ft_striteri(s2, to_upper_iter);
		ASSERT_EQ_STR(s2, "ABC123");
	}

	TEST_SUMMARY("String alloc functions", pass, fail);
}
