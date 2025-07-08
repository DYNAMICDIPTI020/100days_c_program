#include "stdio.h"

void traverse(int *queue, int front, int rear)
{
	int result = isEmpty(front, rear);
	if (result == 1)
	{
		printf("\nQueue is Empty.\n");
		return;
	}
	printf("The queue elements are :");
	int index;
	for (index = front; index <= rear; index++)
		printf("%d ", queue[index]);
	printf("\n");
}
void enqueue(int *queue, int *front, int *rear, int size)
{
	if (isFull(*rear, size))
	{
		printf("\nQueue is Full.\n");
		return;
	}
	else if (isEmpty(*front, *rear))
		*front = *rear = 0;
	else
		(*rear)++;
	printf("Enter data :");
	scanf("%d", &queue[*rear]);
	printf("Data enqueued successfully.\n");
}
void dequeue(int *queue, int *front, int *rear)
{
	if (isEmpty(*front, *rear))
	{
		printf("\nQueue is Empty.\n");
		return;
	}
	else if (*front == *rear)
	{
		printf("\n%d dequeued successfully.\n", queue[*front]);
		*front = *rear = -1;
	}
	else
	{
		printf("\n%d dequeued successfully.\n", queue[*front]);
		(*front)++;
	}
}
void findPeekElement(int *queue, int front, int rear)
{
	if (isEmpty(front, rear))
	{
		printf("\nQueue is Empty.\n");
		return;
	}
	printf("\nThe peek element is :%d\n", queue[front]);
}
int isEmpty(int front, int rear)
{
	return (rear == -1 && front == -1) ? 1 : 0;
}
int isFull(int rear, int size)
{
	return (rear + 1 == size) ? 1 : 0;
}
int main()
{
	int size;
	printf("Enter the size of the queue :");
	scanf("%d", &size);

	int queue[size];

	int choice, front = -1, rear = -1, result;
	do
	{
		printf("\n1 for traverse.\n");
		printf("2 for enqueue element in the queue.\n");
		printf("3 for dequeue element from the queue.\n");
		printf("4 for display the peek element.\n");
		printf("5 for check empty or not.\n");
		printf("6 for check full or not.\n");
		printf("0 for exit.\n");
		printf("\nEnter your choice :");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			traverse(queue, front, rear);
			break;
		case 2:
			enqueue(queue, &front, &rear, size);
			break;
		case 3:
			dequeue(queue, &front, &rear);
			break;
		case 4:
			findPeekElement(queue, front, rear);
			break;
		case 5:
			result = isEmpty(front, rear);
			if (result == 1)
				printf("\nQueue is Empty.\n");
			else
				printf("\nQueue is not Empty.\n");
			break;
		case 6:
			result = isFull(rear, size);
			if (result == 1)
				printf("\nQueue is Full.\n");
			else
				printf("\nQueue is not Full.\n");
			break;
		case 0:
			printf("\nExiting...\n");
			break;
		default:
			printf("\nInvalid option.\n");
		}
	} while (choice != 0);
}

