#include <stdio.h>

#include <libftasm.h>

int	main(void)
{
	t_list	*first_list;
	t_list	*bckup;
	t_list	*second_list;
	t_list	*other_mesh;
	t_list	*fdp;
	int		i;

	second_list = NULL;
	first_list = ft_lstcrt("First mesh!", 11);
	other_mesh = ft_lstcrt("Second mesh bro!", 16);
	ft_lstaddtail(&first_list, other_mesh);
	other_mesh = ft_lstcrt("This is the third...", 20);
	ft_lstaddtail(&first_list, other_mesh);
	other_mesh = ft_lstcrt("Fouuuuuur!", 10);
	ft_lstaddtail(&first_list, other_mesh);
	bckup = first_list;
	while (first_list)
	{
		printf("%p: %s\n", first_list, (char *)first_list->data);
		first_list = first_list->next;
	}
	ft_lstdel(&bckup);
	other_mesh = ft_lstcrt("trying lstadd with NULL list", 28);
	ft_lstaddtail(&second_list, other_mesh);
	other_mesh = ft_lstcrt("good, another one...", 20);
	ft_lstaddtail(&second_list, other_mesh);
	bckup = second_list;
	while (second_list)
	{
		printf("%p: %s\n", second_list, (char *)second_list->data);
		second_list = second_list->next;
	}
	ft_lstdel(&bckup);
	first_list = ft_lstcrt("First mesh!", 11);
	other_mesh = ft_lstcrt("Second mesh bro!", 16);
	ft_lstaddhead(&first_list, other_mesh);
	other_mesh = ft_lstcrt("This is the third...", 20);
	ft_lstaddhead(&first_list, other_mesh);
	other_mesh = ft_lstcrt("Fouuuuuur!", 10);
	ft_lstaddhead(&first_list, other_mesh);
	bckup = first_list;
	while (first_list)
	{
		printf("%p: %s\n", first_list, (char *)first_list->data);
		first_list = first_list->next;
	}
	ft_lstdel(&first_list);
	fdp = ft_lstcrt("enumeration", 11);
	first_list = fdp;
	for (i = 0; i < 4096; i++)
	{
		fdp = ft_lstcrt(&i, sizeof(i));
		ft_lstaddtail(&first_list, fdp);
	}
	i = 0;
	fdp = first_list;
	while (first_list)
	{
		if (i == 0)
			printf("%s\n", first_list->data);
		else
			printf("%d\n", *(int *)first_list->data);
		first_list = first_list->next;
		i++;
	}
	ft_lstdel(&fdp);
	return (0);
}
