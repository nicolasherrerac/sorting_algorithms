#include "sort.h"
/**
 * insertion_sort_list - insertion sort method.
 * @list: unsorted list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *aux;

	if (!list || !(*list)->next || !*list)
		return;

	aux = (*list)->next;

	while (aux)
	{
		while (aux->prev != NULL && aux->n < aux->prev->n)
		{
			aux->prev->next = aux->next;
			if (aux->next != NULL)
			{
				aux->next->prev = aux->prev;
			}
			aux->next = aux->prev;
			aux->prev = aux->prev->prev;
			aux->next->prev = aux;
			if (aux->prev == NULL)
			{
				*list = aux;
			}
			else
			{
				aux->prev->next = aux;
			}
			print_list(*list);
		}
		aux = aux->next;
	}
}
