#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * listing_t *insert_node - listint_t **head, int number
 * @head: head of linked list
 * @number: number to insert
 * description: function in C that inserts a number into a sorted singly linked list
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number){
        listint_t *newNode = NULL, *buffNode = NULL;
        if(!(*head))
                return (NULL);

	newNode = malloc(sizeof(listint_t));
        if (!newNode)
		return (NULL);
        newNode->n = number;
        if (!(head))
                *head = newNode;
    
        if ((*head)->next->n > number)
		newNode->next = *head;
	for (buffNode = *head; buffNode->next && buffNode->next->n < number; buffNode = buffNode->next);
        
        newNode->next = buffNode->next;
        buffNode->next = newNode;
        
	return (newNode);
}