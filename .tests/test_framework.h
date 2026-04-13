#ifndef TEST_FRAMEWORK_H
# define TEST_FRAMEWORK_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>

/*
** Minimal unit test framework for libft.
** Each test file exposes a run function that returns (pass_count, fail_count)
** via output parameters.
*/

# define CLR_RED   "\033[31m"
# define CLR_GREEN "\033[32m"
# define CLR_RESET "\033[0m"

static int g_test_pass;
static int g_test_fail;

static inline void	test_init(void)
{
	g_test_pass = 0;
	g_test_fail = 0;
}

static inline void	test_assert(int cond, const char *test_name)
{
	if (cond)
	{
		g_test_pass++;
	}
	else
	{
		g_test_fail++;
		printf("  " CLR_RED "FAIL" CLR_RESET ": %s\n", test_name);
	}
}

# define ASSERT(cond)       test_assert((cond), #cond)
# define ASSERT_MSG(c, msg) test_assert((c), msg)

# define ASSERT_EQ_INT(a, b) do { \
	int _a = (a); int _b = (b); \
	if (_a == _b) { g_test_pass++; } \
	else { g_test_fail++; \
		printf("  " CLR_RED "FAIL" CLR_RESET ": %s == %s  " \
			"(got %d, expected %d)\n", #a, #b, _a, _b); } \
} while (0)

# define ASSERT_EQ_STR(a, b) do { \
	const char *_a = (a); const char *_b = (b); \
	if (_a && _b && strcmp(_a, _b) == 0) { g_test_pass++; } \
	else if (!_a && !_b) { g_test_pass++; } \
	else { g_test_fail++; \
		printf("  " CLR_RED "FAIL" CLR_RESET ": %s == %s  " \
			"(got \"%s\", expected \"%s\")\n", #a, #b, \
			_a ? _a : "(null)", _b ? _b : "(null)"); } \
} while (0)

# define ASSERT_EQ_SIZE(a, b) do { \
	size_t _a = (a); size_t _b = (b); \
	if (_a == _b) { g_test_pass++; } \
	else { g_test_fail++; \
		printf("  " CLR_RED "FAIL" CLR_RESET ": %s == %s  " \
			"(got %zu, expected %zu)\n", #a, #b, _a, _b); } \
} while (0)

# define ASSERT_FLOAT_EQ(a, b, eps) do { \
	float _a = (a); float _b = (b); \
	if (fabsf(_a - _b) <= (eps)) { g_test_pass++; } \
	else { g_test_fail++; \
		printf("  " CLR_RED "FAIL" CLR_RESET ": %s ~= %s  " \
			"(got %f, expected %f)\n", #a, #b, _a, _b); } \
} while (0)

# define ASSERT_NULL(a) do { \
	if ((a) == NULL) { g_test_pass++; } \
	else { g_test_fail++; \
		printf("  " CLR_RED "FAIL" CLR_RESET ": %s == NULL\n", #a); } \
} while (0)

# define ASSERT_NOT_NULL(a) do { \
	if ((a) != NULL) { g_test_pass++; } \
	else { g_test_fail++; \
		printf("  " CLR_RED "FAIL" CLR_RESET ": %s != NULL\n", #a); } \
} while (0)

# define TEST_SUMMARY(name, pass_out, fail_out) do { \
	*(pass_out) = g_test_pass; \
	*(fail_out) = g_test_fail; \
	if (g_test_fail == 0) \
		printf(CLR_GREEN "[PASS]" CLR_RESET " %s: %d/%d tests passed\n", \
			name, g_test_pass, g_test_pass + g_test_fail); \
	else \
		printf(CLR_RED "[FAIL]" CLR_RESET " %s: %d/%d tests passed\n", \
			name, g_test_pass, g_test_pass + g_test_fail); \
} while (0)

#endif
