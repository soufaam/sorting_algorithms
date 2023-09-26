#include "sort.h"

/**
 * swap_insert - swap the nodes based on sorted insertion
 *
 * @current: The current node
 * @node: Node to be inserted
 * @llist: the list to be sorted
 */

void swap_insert(listint_t **llist, listint_t **current, listint_t *node)
{
	listint_t *tmp = NULL;

	while (*current)
	{
		tmp = *current;
		if (tmp->n > node->n)
		{
			tmp->next = node->next;
			if (node->next)
				node->next->prev = *current;
			node->next = tmp;
			node->prev = tmp->prev;
			tmp->prev = node;
			if (node->prev)
				node->prev->next = node;
			else
				*llist = node;
			print_list(*llist);
		}
		if (!tmp->prev)
		{
			*llist = tmp;
			break;
		}
		tmp = *current;
		*current = (*current)->prev;
	}
}
/**
 * insertion_sort_list - The list to be sorted
 *
 * @list: The list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = NULL;
	listint_t  *next = NULL;

	if (!list || !*list || !(*list)->next)
		return;
	tmp = *list;
	while (tmp)
	{
		next = tmp->next;
		if (next && next->n < tmp->n)
		{
			swap_insert(list, &tmp, next);
		}
		tmp = tmp->next;
	}
}
