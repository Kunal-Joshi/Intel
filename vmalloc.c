

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


struct mem_list
{

	int addr;
	int size;
	int used;
	struct mem_list *prev;
	struct mem_list *next;
};


struct mem_list *head = NULL;
static int capacity = 1024;



void PrintList(struct mem_list *head)
{
	struct mem_list *temp;
	temp = head;

	while(temp)
	{
		printf("\nAddress is %d\n", temp->addr);
		printf("\nSize is %d\n", temp->size);
		printf("\nUsed %d\n", temp->used);
		
		temp = temp->next;
	}


}
void deAllocate(struct mem_list *head, int addr)
{
	struct mem_list *temp;
	temp = head;

	while (temp)
	{
		

		temp = temp->next;
	}


}


void Allocate(struct mem_list *n)
{
	printf("Head node is located at %p\n",head);
	printf("Enter size\n");
	int sz;
	scanf("%d", &sz);
	if (sz <= capacity)
	{
		
		struct mem_list *temp;
		temp = head;
		printf("Started Traversing at %p\n", temp);
		while(temp)
		{
			printf("Currently checking condition for %p\n", temp);
			if (sz <= temp->size&&temp->used == 0)
			{
				
				
				n->addr = temp->addr + sz + 1;
				n->used = 0;
				n->size = temp->size - sz;
				n->prev = temp;
				n->next = temp->next;

				temp->size = sz;
				temp->used = 1;
				temp->next = n;
				printf("Joind new node  at %p\n", temp->next);
				capacity = capacity - sz;
				break;



			}
			temp=temp->next;
		

		}
	}
}


int main()
{
	struct mem_list h;
	head = &h;
	printf("%p\n",head);
	head->addr = 0;
	head->size = capacity;
	head->used = 0;
	head->prev = NULL;
	head->next = NULL;
	while (1)
	{
		int choice;
		printf("1. Allocate Memory\n");
		printf("2. De_Allocate Memory\n");
		printf("3. PrintList\n");
		printf("4. Print Current Capacity\n");
		printf("Enter your Choice\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Object Created\n");
			struct mem_list *node =(struct mem_list*)sbrk(sizeof(struct mem_list));

			printf("New Node at %p\n", node);
			Allocate(node);
			break;

		case 2:
			printf("Enter address you want to deallocate");
			int addr;
			scanf("%d", &addr);
			deAllocate(head, addr);
			break;

		case 3:
			PrintList(head);
			break;


		case 4:
			printf("\nCurrent capacity is %d\n",capacity);
			break;

		default:
			printf("Enter Valid Choice");

		}
	}

	return 0;
}
