#include "sort.h"
#include <stdio.h>
/**
 * insertion_sort_list - inserion algorithm function
 * @list: list
 * return: not applicable
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *temp;

	
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	
	current = (*list)->next;
	
	while (current != NULL)
	{
		temp = current;
		
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				
			temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;
			
			if (temp->prev != NULL)
				temp->prev->next = temp;
			else
				*list = temp;
			print_list(*list);
		}
		current = current->next;
	}
}
