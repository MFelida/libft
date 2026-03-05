#include "test_framework.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

/* Helper: capture fd output to a temp file, read it back */
static char	*capture_fd_output(void (*fn)(int fd), int *out_len)
{
	char	tmpfile[] = "/tmp/libft_test_XXXXXX";
	int		fd;
	char	*buf;
	ssize_t	n;

	fd = mkstemp(tmpfile);
	if (fd < 0)
		return (NULL);
	fn(fd);
	lseek(fd, 0, SEEK_SET);
	buf = malloc(4096);
	n = read(fd, buf, 4095);
	if (n < 0)
		n = 0;
	buf[n] = '\0';
	if (out_len)
		*out_len = (int)n;
	close(fd);
	unlink(tmpfile);
	return (buf);
}

/* Individual capture functions */
static void	write_char_A(int fd)		{ ft_putchar_fd('A', fd); }
static void	write_char_nl(int fd)		{ ft_putchar_fd('\n', fd); }
static void	write_str_hello(int fd)		{ ft_putstr_fd("hello", fd); }
static void	write_str_null(int fd)		{ ft_putstr_fd(NULL, fd); }
static void	write_endlhello(int fd)		{ ft_putendl_fd("hello", fd); }
static void	write_endlnull(int fd)		{ ft_putendl_fd(NULL, fd); }
static void	write_nbr_42(int fd)		{ ft_putnbr_fd(42, fd); }
static void	write_nbr_neg42(int fd)		{ ft_putnbr_fd(-42, fd); }
static void	write_nbr_0(int fd)			{ ft_putnbr_fd(0, fd); }
static void	write_nbr_max(int fd)		{ ft_putnbr_fd(2147483647, fd); }
static void	write_nbr_min(int fd)		{ ft_putnbr_fd(-2147483648, fd); }
static void	write_uint_0(int fd)		{ ft_putuint_fd(0, fd); }
static void	write_uint_42(int fd)		{ ft_putuint_fd(42, fd); }
static void	write_hexl_0(int fd)		{ ft_puthexl_fd(0, fd); }
static void	write_hexl_255(int fd)		{ ft_puthexl_fd(255, fd); }
static void	write_hexl_42(int fd)		{ ft_puthexl_fd(42, fd); }
static void	write_hexu_255(int fd)		{ ft_puthexu_fd(255, fd); }
static void	write_hexu_42(int fd)		{ ft_puthexu_fd(42, fd); }

static void	write_fprintf_hello(int fd)
{
	ft_fprintf(fd, "hello %s %d", "world", 42);
}

void	test_output(int *pass, int *fail)
{
	char	*buf;

	test_init();

	/* --- ft_putchar_fd --- */
	printf("--- ft_putchar_fd ---\n");
	buf = capture_fd_output(write_char_A, NULL);
	ASSERT_EQ_STR(buf, "A");
	free(buf);
	buf = capture_fd_output(write_char_nl, NULL);
	ASSERT_EQ_STR(buf, "\n");
	free(buf);

	/* --- ft_putstr_fd --- */
	printf("--- ft_putstr_fd ---\n");
	buf = capture_fd_output(write_str_hello, NULL);
	ASSERT_EQ_STR(buf, "hello");
	free(buf);
	buf = capture_fd_output(write_str_null, NULL);
	ASSERT_EQ_STR(buf, "(null)");
	free(buf);

	/* --- ft_putendl_fd --- */
	printf("--- ft_putendl_fd ---\n");
	buf = capture_fd_output(write_endlhello, NULL);
	ASSERT_EQ_STR(buf, "hello\n");
	free(buf);
	buf = capture_fd_output(write_endlnull, NULL);
	ASSERT_EQ_STR(buf, "");
	free(buf);

	/* --- ft_putnbr_fd --- */
	printf("--- ft_putnbr_fd ---\n");
	buf = capture_fd_output(write_nbr_42, NULL);
	ASSERT_EQ_STR(buf, "42");
	free(buf);
	buf = capture_fd_output(write_nbr_neg42, NULL);
	ASSERT_EQ_STR(buf, "-42");
	free(buf);
	buf = capture_fd_output(write_nbr_0, NULL);
	ASSERT_EQ_STR(buf, "0");
	free(buf);
	buf = capture_fd_output(write_nbr_max, NULL);
	ASSERT_EQ_STR(buf, "2147483647");
	free(buf);
	buf = capture_fd_output(write_nbr_min, NULL);
	ASSERT_EQ_STR(buf, "-2147483648");
	free(buf);

	/* --- ft_putuint_fd --- */
	printf("--- ft_putuint_fd ---\n");
	buf = capture_fd_output(write_uint_0, NULL);
	ASSERT_EQ_STR(buf, "0");
	free(buf);
	buf = capture_fd_output(write_uint_42, NULL);
	ASSERT_EQ_STR(buf, "42");
	free(buf);

	/* --- ft_puthexl_fd --- */
	printf("--- ft_puthexl_fd ---\n");
	buf = capture_fd_output(write_hexl_0, NULL);
	ASSERT_EQ_STR(buf, "0");
	free(buf);
	buf = capture_fd_output(write_hexl_255, NULL);
	ASSERT_EQ_STR(buf, "ff");
	free(buf);
	buf = capture_fd_output(write_hexl_42, NULL);
	ASSERT_EQ_STR(buf, "2a");
	free(buf);

	/* --- ft_puthexu_fd --- */
	printf("--- ft_puthexu_fd ---\n");
	buf = capture_fd_output(write_hexu_255, NULL);
	ASSERT_EQ_STR(buf, "FF");
	free(buf);
	buf = capture_fd_output(write_hexu_42, NULL);
	ASSERT_EQ_STR(buf, "2A");
	free(buf);

	/* --- ft_fprintf --- */
	printf("--- ft_fprintf ---\n");
	buf = capture_fd_output(write_fprintf_hello, NULL);
	ASSERT_EQ_STR(buf, "hello world 42");
	free(buf);

	TEST_SUMMARY("Output functions", pass, fail);
}
