/*
Name        : Sushant Patil
Date        : 17/04/2023
Description : WAP for circular queue implementation using array
*/
#include "queue.h"

int create_queue(Queue_t *q, int size)
{
    q->Que = malloc(sizeof(int) * size); // Allocate memory for the array
    if (q->Que == NULL) 
    {
        return FAILURE; // Failed to allocate memory
    }
    q->front = -1; // Initialize front and rear indices
    q->rear = -1;
    q->count = 0; //initilize count
    q->capacity = size; // Set the capacity of the queue
    return SUCCESS; // Successfully created the queue
}

int main()
{
	Queue_t q;
	int size;
	printf("Enter the size of the queue : ");
	scanf("%d", &size);
	if (create_queue(&q, size) == FAILURE)
	{
	    printf("INFO : Queue not created\n");
	    return FAILURE;
	}

	char ch;
	int choice, data;
	printf("1. Enqueue\n2. Dequeue\n3. Print Queue\n4. Exit\nEnter the option : ");
	while (1)
	{
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				/* Function to Enqueue the Queue */
				printf("Enter the element you want to insert : ");
				scanf("%d", &data);
				if (enqueue(&q, data) == FAILURE)
				{
					printf("INFO : Queue full\n");
				}
				break;
			case 2:
				/* Function to dequeueue the queue */
				if (dequeue(&q) == FAILURE)
				{
					printf("INFO : Queue is empty\n");
				}
				else
				{
					printf("INFO : Dequeue successfull\n");
				}
				break;
			case 3:
				/* Function to print the queue */
				print_queue(q);
				break;
			case 4:
				return SUCCESS;
			default:
				printf("Invalid option !!!\n");
		}

	}
}