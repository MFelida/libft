#include "test_framework.h"
#include "libft.h"

void	test_mem(int *pass, int *fail)
{
	test_init();

	/* --- ft_memset --- */
	printf("--- ft_memset ---\n");
	{
		char buf[10];
		ft_memset(buf, 'A', 5);
		buf[5] = '\0';
		ASSERT_EQ_STR(buf, "AAAAA");

		ft_memset(buf, 0, 5);
		ASSERT_EQ_INT(buf[0], 0);
		ASSERT_EQ_INT(buf[4], 0);

		char buf2[1];
		void *ret = ft_memset(buf2, 'x', 1);
		ASSERT(ret == buf2);
		ASSERT_EQ_INT(buf2[0], 'x');
	}

	/* --- ft_bzero --- */
	printf("--- ft_bzero ---\n");
	{
		char buf[10] = "abcdefghi";
		ft_bzero(buf, 5);
		ASSERT_EQ_INT(buf[0], 0);
		ASSERT_EQ_INT(buf[4], 0);
		ASSERT_EQ_INT(buf[5], 'f');

		ft_bzero(buf, 0);
		ASSERT_EQ_INT(buf[5], 'f');
	}

	/* --- ft_memcpy --- */
	printf("--- ft_memcpy ---\n");
	{
		char dst[20];
		const char *src = "hello world";

		ft_memcpy(dst, src, 12);
		ASSERT_EQ_STR(dst, "hello world");

		char dst2[10] = "xxxxxxxxx";
		ft_memcpy(dst2, "abc", 3);
		ASSERT_EQ_INT(dst2[0], 'a');
		ASSERT_EQ_INT(dst2[1], 'b');
		ASSERT_EQ_INT(dst2[2], 'c');
		ASSERT_EQ_INT(dst2[3], 'x');

		void *ret = ft_memcpy(dst2, "Z", 1);
		ASSERT(ret == dst2);
	}

	/* --- ft_memmove --- */
	printf("--- ft_memmove ---\n");
	{
		char buf[20] = "hello world";
		ft_memmove(buf + 1, buf, 5);
		ASSERT_EQ_INT(buf[1], 'h');
		ASSERT_EQ_INT(buf[2], 'e');

		char buf2[20] = "hello world";
		ft_memmove(buf2, buf2 + 6, 5);
		ASSERT_EQ_STR(buf2, "world world");

		void *ret = ft_memmove(buf2, "abc", 3);
		ASSERT(ret == buf2);
	}

	/* --- ft_memchr --- */
	printf("--- ft_memchr ---\n");
	{
		char buf[] = "hello world";
		ASSERT(ft_memchr(buf, 'h', 11) == buf);
		ASSERT(ft_memchr(buf, 'o', 11) == buf + 4);
		ASSERT_NULL(ft_memchr(buf, 'z', 11));
		ASSERT_NULL(ft_memchr(buf, 'o', 3));
		ASSERT(ft_memchr(buf, '\0', 12) == buf + 11);

		unsigned char data[] = {0, 1, 2, 128, 255};
		ASSERT(ft_memchr(data, 128, 5) == data + 3);
		ASSERT(ft_memchr(data, 255, 5) == data + 4);
	}

	/* --- ft_memcmp --- */
	printf("--- ft_memcmp ---\n");
	{
		ASSERT_EQ_INT(ft_memcmp("abc", "abc", 3), 0);
		ASSERT(ft_memcmp("abc", "abd", 3) < 0);
		ASSERT(ft_memcmp("abd", "abc", 3) > 0);
		ASSERT_EQ_INT(ft_memcmp("abc", "abd", 2), 0);
		ASSERT_EQ_INT(ft_memcmp("abc", "xyz", 0), 0);

		unsigned char a[] = {0, 1, 2};
		unsigned char b[] = {0, 1, 3};
		ASSERT(ft_memcmp(a, b, 3) < 0);
	}

	/* --- ft_calloc --- */
	printf("--- ft_calloc ---\n");
	{
		int *arr = ft_calloc(5, sizeof(int));
		ASSERT_NOT_NULL(arr);
		ASSERT_EQ_INT(arr[0], 0);
		ASSERT_EQ_INT(arr[4], 0);
		free(arr);

		char *s = ft_calloc(1, 1);
		ASSERT_NOT_NULL(s);
		ASSERT_EQ_INT(s[0], 0);
		free(s);

		void *p = ft_calloc(0, 0);
		/* malloc(0) may return NULL or a valid pointer; just don't crash */
		free(p);
	}

	/* --- ft_realloc --- */
	printf("--- ft_realloc ---\n");
	{
		char *ptr = malloc(5);
		memcpy(ptr, "abcd", 5);
		char *new_ptr = ft_realloc(ptr, 10, 5);
		ASSERT_NOT_NULL(new_ptr);
		ASSERT_EQ_STR(new_ptr, "abcd");
		free(new_ptr);
	}

	TEST_SUMMARY("Memory functions", pass, fail);
}
