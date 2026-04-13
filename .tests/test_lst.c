#include "test_framework.h"
#include "libft.h"

/* Helper: delete function for lstdelone/lstclear
** Note: this implementation passes the whole node to del(), not content.
** So our del function receives a t_list*, frees content, then frees node. */
static void	del_node(void *node)
{
	t_list	*n;

	n = (t_list *)node;
	free(n->content);
	free(n);
}

/* Helper: free content only (for lstclear which iterates and frees) */
static void	del_node_for_clear(void *node)
{
	t_list	*n;

	n = (t_list *)node;
	free(n->content);
	free(n);
}

/* Helper for lstiter: increment int content */
static int g_iter_sum;
static void	sum_content(void *node)
{
	t_list *n = (t_list *)node;
	g_iter_sum += *(int *)(n->content);
}

/* Helper for lstmap: duplicate int content, returning new t_list node */
static void	*map_double(void *node)
{
	t_list	*src;
	int		*new_val;
	t_list	*new_node;

	src = (t_list *)node;
	new_val = malloc(sizeof(int));
	if (!new_val)
		return (NULL);
	*new_val = (*(int *)(src->content)) * 2;
	new_node = ft_lstnew(new_val);
	if (!new_node)
	{
		free(new_val);
		return (NULL);
	}
	return (new_node);
}

static void	del_content_free_node(void *ptr)
{
	t_list *n = (t_list *)ptr;
	free(n->content);
	free(n);
}

void	test_lst(int *pass, int *fail)
{
	test_init();

	/* --- ft_lstnew --- */
	printf("--- ft_lstnew ---\n");
	{
		int *val = malloc(sizeof(int));
		*val = 42;
		t_list *node = ft_lstnew(val);
		ASSERT_NOT_NULL(node);
		ASSERT_EQ_INT(*(int *)node->content, 42);
		ASSERT_NULL(node->next);
		free(val);
		free(node);
	}
	{
		t_list *node = ft_lstnew(NULL);
		ASSERT_NOT_NULL(node);
		ASSERT_NULL(node->content);
		ASSERT_NULL(node->next);
		free(node);
	}

	/* --- ft_lstadd_front --- */
	printf("--- ft_lstadd_front ---\n");
	{
		t_list *lst = NULL;
		t_list *n1 = ft_lstnew("first");
		t_list *n2 = ft_lstnew("second");
		ft_lstadd_front(&lst, n1);
		ASSERT(lst == n1);
		ft_lstadd_front(&lst, n2);
		ASSERT(lst == n2);
		ASSERT(lst->next == n1);
		free(n1);
		free(n2);
	}

	/* --- ft_lstadd_back --- */
	printf("--- ft_lstadd_back ---\n");
	{
		t_list *lst = NULL;
		t_list *n1 = ft_lstnew("first");
		t_list *n2 = ft_lstnew("second");
		t_list *n3 = ft_lstnew("third");
		ft_lstadd_back(&lst, n1);
		ASSERT(lst == n1);
		ft_lstadd_back(&lst, n2);
		ASSERT(lst == n1);
		ASSERT(lst->next == n2);
		ft_lstadd_back(&lst, n3);
		ASSERT(lst->next->next == n3);
		free(n1);
		free(n2);
		free(n3);
	}

	/* --- ft_lstsize --- */
	printf("--- ft_lstsize ---\n");
	{
		ASSERT_EQ_INT(ft_lstsize(NULL), 0);

		t_list *n1 = ft_lstnew("a");
		ASSERT_EQ_INT(ft_lstsize(n1), 1);

		t_list *n2 = ft_lstnew("b");
		t_list *n3 = ft_lstnew("c");
		n1->next = n2;
		n2->next = n3;
		ASSERT_EQ_INT(ft_lstsize(n1), 3);
		free(n1);
		free(n2);
		free(n3);
	}

	/* --- ft_lstlast --- */
	printf("--- ft_lstlast ---\n");
	{
		ASSERT_NULL(ft_lstlast(NULL));

		t_list *n1 = ft_lstnew("a");
		ASSERT(ft_lstlast(n1) == n1);

		t_list *n2 = ft_lstnew("b");
		t_list *n3 = ft_lstnew("c");
		n1->next = n2;
		n2->next = n3;
		ASSERT(ft_lstlast(n1) == n3);
		free(n1);
		free(n2);
		free(n3);
	}

	/* --- ft_lstdelone --- */
	printf("--- ft_lstdelone ---\n");
	{
		char *content = ft_strdup("deleteme");
		t_list *node = ft_lstnew(content);
		/* del receives the whole node ptr, should free content and node */
		ft_lstdelone(node, del_node);
		/* Can't assert much after free, but no crash = pass */
		g_test_pass++;
	}

	/* --- ft_lstclear --- */
	printf("--- ft_lstclear ---\n");
	{
		t_list *lst = NULL;
		char *c1 = ft_strdup("one");
		char *c2 = ft_strdup("two");
		char *c3 = ft_strdup("three");
		ft_lstadd_back(&lst, ft_lstnew(c1));
		ft_lstadd_back(&lst, ft_lstnew(c2));
		ft_lstadd_back(&lst, ft_lstnew(c3));
		ASSERT_EQ_INT(ft_lstsize(lst), 3);
		ft_lstclear(&lst, del_node_for_clear);
		ASSERT_NULL(lst);
	}

	/* --- ft_lstiter --- */
	printf("--- ft_lstiter ---\n");
	{
		int a = 1, b = 2, c = 3;
		t_list *n1 = ft_lstnew(&a);
		t_list *n2 = ft_lstnew(&b);
		t_list *n3 = ft_lstnew(&c);
		n1->next = n2;
		n2->next = n3;
		g_iter_sum = 0;
		ft_lstiter(n1, sum_content);
		ASSERT_EQ_INT(g_iter_sum, 6);
		free(n1);
		free(n2);
		free(n3);
	}
	{
		ft_lstiter(NULL, sum_content);
		g_test_pass++; /* no crash = pass */
	}

	/* --- ft_lstmap --- */
	printf("--- ft_lstmap ---\n");
	{
		int *a = malloc(sizeof(int)); *a = 1;
		int *b = malloc(sizeof(int)); *b = 2;
		int *c = malloc(sizeof(int)); *c = 3;
		t_list *n1 = ft_lstnew(a);
		t_list *n2 = ft_lstnew(b);
		t_list *n3 = ft_lstnew(c);
		n1->next = n2;
		n2->next = n3;

		t_list *mapped = ft_lstmap(n1, map_double, del_content_free_node);
		ASSERT_NOT_NULL(mapped);
		ASSERT_EQ_INT(*(int *)mapped->content, 2);
		ASSERT_EQ_INT(*(int *)mapped->next->content, 4);
		ASSERT_EQ_INT(*(int *)mapped->next->next->content, 6);
		ASSERT_NULL(mapped->next->next->next);
		ASSERT_EQ_INT(ft_lstsize(mapped), 3);

		/* Cleanup mapped list */
		ft_lstclear(&mapped, del_content_free_node);

		/* Cleanup original list */
		free(a); free(b); free(c);
		free(n1); free(n2); free(n3);
	}
	{
		t_list *mapped = ft_lstmap(NULL, map_double, del_content_free_node);
		ASSERT_NULL(mapped);
	}

	TEST_SUMMARY("Linked list functions", pass, fail);
}
