#include <stdio.h>

typedef	struct s_list{
	void *content;
	struct s_list *next;
} t_list;

int	main()
{
	t_list h;
	t_list	*ptr;


//	h.content = "hello";
//	h.next = NULL;

	ptr -> content = "hello";
	ptr -> next = NULL;
	printf("cont = %s\n",(char *)(h.content));
	printf("ptr = %s\n",(char *)(ptr -> content));
}
