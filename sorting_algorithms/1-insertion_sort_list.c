#include "sort.h"
#include <stdio.h>
void swap(listint_t **head, listint_t *mv_back, listint_t *mv_forw);
/**
 * insertion_sort_list - sort a list using insertion sort
 * @list: list to sort
 * Description: Function to sort a doubly linked list using
 * the insertion sort algorithm
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *next, *current = (*list)->next;

	if (list == NULL || *list == NULL)
		return;

	while (current != NULL)
	{
		next = current->next;
		if (current->n < current->prev->n)
		{
			temp = current;
			while (temp->prev != NULL && temp->n < temp->prev->n)
			{
				swap(list, temp, temp->prev);
				print_list(*list);
			}
		}

		current = next;
	}
}

/**
 * swap - swap two nodes in a dll
 * @head: head of dll to swap in
 * @mv_back: node to move backwards
 * @mv_forw: node to move forward
 * Description: Function to swap the pointer positions
 * of two nodes in a doubly linked list
 */

void swap(listint_t **head, listint_t *mv_back, listint_t *mv_forw)
{
	listint_t *back_prev, *forw_next;

	back_prev = mv_forw->prev;
	forw_next = mv_back->next;

	if (back_prev != NULL)
		back_prev->next = mv_back;
	else
		*head = mv_back;
	mv_forw->prev = mv_back;
	mv_forw->next = forw_next;
	mv_back->prev = back_prev;
	mv_back->next = mv_forw;
	if (forw_next)
		forw_next->prev = mv_forw;
}
