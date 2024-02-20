#include "sort.h"
#include <stdio.h>
/**
 * insertion_sort_list - inserion algorithm function
 * @list: list
 * return: not applicable
 */
void insertion_sort_list(listint_t **list)
{
	 listint_t *sorted_list , *current;
	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	
	*sorted_list = *list;
	*current = sorted_list->next;
	
	while (current != NULL)
	{
		listint_t *temp = current;
		int value = temp->n;
		
		while (temp->prev != NULL && temp->prev->n > value)
		{
			temp->n = temp->prev->n;
			temp = temp->prev;
		}
		temp->n = value;
		
		while (temp->prev != NULL && temp->prev->n > temp->n)
		{
			listint_t *prev_node = temp->prev;
			listint_t *next_node = temp->next;
			
			if (prev_node->prev != NULL)
			{
				prev_node->prev->next = temp;
			}
		       	if (next_node != NULL)
			{
				next_node->prev = prev_node;
			}
			temp->prev = prev_node->prev;
			temp->next = prev_node;
			prev_node->prev = temp;
			prev_node->next = next_node;
			
			if (temp->prev == NULL)
			{
				*list = temp;
			}
		}
		current = current->next;
	}
	*list = sorted_list;
	print_list(sorted_list);
}
