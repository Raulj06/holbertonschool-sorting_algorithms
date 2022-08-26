#include "sort.h"
8
/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * using the Insertion sort algorithm
 * @list: pointer to the first element of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted, *unsorted, *node_1, *node_2;

	if (!list || !(*list)->next)
		return;

	sorted = *list;
	unsorted = sorted->next;
	while (unsorted)
	{
		if (unsorted->n < sorted->n)
		{
			node_swap(sorted, unsorted);
			if (*list == sorted)
				*list = unsorted;
			unsorted = unsorted->next;
			sorted = unsorted->prev;
			print_list(*list);

			node_1 = sorted;
			node_2 = node_1->prev;
			while (node_2 && node_1->n < node_2->n)
			{
				node_swap(node_2, node_1);
				if (node_2 == *list)
					*list = node_1;
				print_list(*list);
				node_2 = node_1->prev;
			}
		}
		sorted = unsorted;
		unsorted = unsorted->next;
	}
}

/**
 * node_swap - swaps nodes in a doubly linked list
 * @sorted: first pointer
 * @unsorted: second pointer
 */
void node_swap(listint_t *sorted, listint_t *unsorted)
{
	sorted->next = unsorted->next;
	unsorted->prev = sorted->prev;
	if (unsorted->prev)
		unsorted->prev->next = unsorted;
	sorted->prev = unsorted;
	if (sorted->next)
		sorted->next->prev = sorted;
	unsorted->next = sorted;
}
