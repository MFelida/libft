#include "test_framework.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

static void	create_test_file(const char *path, const char *content)
{
	int	fd;

	fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return ;
	write(fd, content, strlen(content));
	close(fd);
}

void	test_gnl(int *pass, int *fail)
{
	test_init();

	printf("--- ft_gnl ---\n");

	/* Test 1: Simple multi-line file */
	{
		const char *path = "/tmp/libft_gnl_test1.txt";
		create_test_file(path, "line1\nline2\nline3\n");
		int fd = open(path, O_RDONLY);
		ASSERT(fd >= 0);

		char *line;
		line = ft_gnl(fd);
		ASSERT_EQ_STR(line, "line1\n");
		free(line);

		line = ft_gnl(fd);
		ASSERT_EQ_STR(line, "line2\n");
		free(line);

		line = ft_gnl(fd);
		ASSERT_EQ_STR(line, "line3\n");
		free(line);

		line = ft_gnl(fd);
		ASSERT_NULL(line);

		close(fd);
		unlink(path);
	}

	/* Test 2: File without trailing newline */
	{
		const char *path = "/tmp/libft_gnl_test2.txt";
		create_test_file(path, "no newline at end");
		int fd = open(path, O_RDONLY);
		ASSERT(fd >= 0);

		char *line;
		line = ft_gnl(fd);
		ASSERT_NOT_NULL(line);
		ASSERT_EQ_STR(line, "no newline at end");
		free(line);

		line = ft_gnl(fd);
		ASSERT_NULL(line);

		close(fd);
		unlink(path);
	}

	/* Test 3: Empty file */
	{
		const char *path = "/tmp/libft_gnl_test3.txt";
		create_test_file(path, "");
		int fd = open(path, O_RDONLY);
		ASSERT(fd >= 0);

		char *line;
		line = ft_gnl(fd);
		ASSERT_NULL(line);

		close(fd);
		unlink(path);
	}

	/* Test 4: Single newline */
	{
		const char *path = "/tmp/libft_gnl_test4.txt";
		create_test_file(path, "\n");
		int fd = open(path, O_RDONLY);
		ASSERT(fd >= 0);

		char *line;
		line = ft_gnl(fd);
		ASSERT_EQ_STR(line, "\n");
		free(line);

		line = ft_gnl(fd);
		ASSERT_NULL(line);

		close(fd);
		unlink(path);
	}

	/* Test 5: Invalid fd */
	{
		char *line = ft_gnl(-1);
		ASSERT_NULL(line);
	}

	TEST_SUMMARY("Get Next Line", pass, fail);
}
