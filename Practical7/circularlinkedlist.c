#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct cll
{
	int no;
	struct cll *next;
};

struct cll *first=NULL;
struct cll *new1=NULL;
struct cll *temp=NULL;
struct cll *prev=NULL;


/* main() function starts... */
int main()
{
	int choice,no,pos;

	void insert_end(int);
	void insert_front(int);
	void insert_after(int,int);
	void insert_before(int,int);
	void delete_cll(int);
	void traverse(void);

	clrscr();

	while(1)
	{
		printf("\n\n*****************************");
		printf("\n Menu for operations of CLL...");
		printf("\n 1. Insert at end...");
		printf("\n 2. Insert at front...");
		printf("\n 3. Insert after...");
		printf("\n 4. Insert before...");
		printf("\n 5. Delete node...");
		printf("\n 6. Traverse list...");
		printf("\n 7. Exit...");

		printf("\n\n Enter ur choice...");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\n Enter no:\n");
				scanf("%d",&no);
				insert_end(no);
				break;

			case 2:
				printf("\n Enter no:\n");
				scanf("%d",&no);
				insert_front(no);
				break;

			case 3:
				printf("\n Enter no and position:\n");
				scanf("%d%d",&no,&pos);
				insert_after(no,pos);
				break;

			case 4:
				printf("\n Enter no and position:\n");
				scanf("%d%d",&no,&pos);
				insert_before(no,pos);
				break;

			case 5:
				printf("\n Enter no to be deleted:\n");
				scanf("%d",&no);
				delete_cll(no);
				break;

			case 6:
				traverse();
				break;

			case 7:
				printf("\n Program is terminated successfully...");
				getch();
				exit(0);

			default:
				printf("\n Enter valid choice...\n");
				getch();

		} // switch ends...

	} // while ends...

} // main() function ends...



/* insert_front() starts... */
void insert_front(int x)
{
	/* prepare a new node... */
	new1=(struct cll*)malloc(sizeof(struct cll));

	new1->no=x;

	/* if list is empty... */
	if(first==NULL)
	{
		first=new1;
		new1->next=first;
		return;
	}

	/* traverse to reach last node... */
	temp=first;

	while(temp->next!=first)
	{
		temp=temp->next;
	}

	/* insert new node at front... */
	new1->next=first;
	first=new1;

	/* last node points to new first... */
	temp->next=first;

} // insert_front() ends...



/* insert_end() starts... */
void insert_end(int x)
{
	/* prepare a new node... */
	new1=(struct cll*)malloc(sizeof(struct cll));

	new1->no=x;

	/* if list is empty... */
	if(first==NULL)
	{
		first=new1;
		new1->next=first;
		return;
	}

	/* traverse to reach last node... */
	temp=first;

	while(temp->next!=first)
	{
		temp=temp->next;
	}

	/* insert new node at end... */
	temp->next=new1;
	new1->next=first;

} // insert_end() ends...



/* insert_after() starts... */
void insert_after(int x,int pos)
{
	/* if list is empty... */
	if(first==NULL)
	{
		printf("\n CLL is empty...");
		getch();
		return;
	}

	/* prepare a new node... */
	new1=(struct cll*)malloc(sizeof(struct cll));

	new1->no=x;

	/* traverse to reach proper position... */
	temp=first;

	do
	{
		if(temp->no==pos)
		{
			/* insert new node after temp... */
			new1->next=temp->next;
			temp->next=new1;

			return;
		}

		temp=temp->next;

	}while(temp!=first);

	/* position not found... */
	printf("\n Node with given position is not available...");
	getch();

} // insert_after() ends...



/* insert_before() starts... */
void insert_before(int x,int pos)
{
	/* if list is empty... */
	if(first==NULL)
	{
		printf("\n CLL is empty...");
		getch();
		return;
	}

	/* if node is to be inserted before first node... */
	if(first->no==pos)
	{
		insert_front(x);
		return;
	}

	/* prepare a new node... */
	new1=(struct cll*)malloc(sizeof(struct cll));

	new1->no=x;

	/* traverse to reach proper position... */
	temp=first;

	do
	{
		prev=temp;
		temp=temp->next;

		if(temp->no==pos)
		{
			/* insert new node before temp... */
			new1->next=temp;
			prev->next=new1;

			return;
		}

	}while(temp!=first);

	/* position not found... */
	printf("\n Node with given position is not available...");
	getch();

} // insert_before() ends...



/* delete_cll() starts... */
void delete_cll(int x)
{
	/* if list is empty... */
	if(first==NULL)
	{
		printf("\n CLL is empty...");
		getch();
		return;
	}

	/* if only one node is present... */
	if(first->next==first)
	{
		if(first->no==x)
		{
			free(first);
			first=NULL;
			return;
		}

		printf("\n Node to be deleted is not available...");
		getch();
		return;
	}

	/* if first node is to be deleted... */
	if(first->no==x)
	{
		temp=first;

		/* find last node... */
		prev=first;

		while(prev->next!=first)
		{
			prev=prev->next;
		}

		/* move first to next node... */
		first=first->next;

		/* last node points to new first... */
		prev->next=first;

		free(temp);

		return;
	}

	/* traverse to reach node to be deleted... */
	temp=first;

	do
	{
		prev=temp;
		temp=temp->next;

		if(temp->no==x)
		{
			/* delete node... */
			prev->next=temp->next;
			free(temp);

			return;
		}

	}while(temp!=first);

	/* node not found... */
	printf("\n Node to be deleted is not available...\n");
	getch();

} // delete_cll() ends...



/* traverse() starts... */
void traverse()
{
	/* if list is empty... */
	if(first==NULL)
	{
		printf("\n The CLL is empty...");
		getch();
		return;
	}

	temp=first;

	printf("\n The CLL is : ");

	/* circular traversal */
	do
	{
		printf("%d  ",temp->no);
		temp=temp->next;

	}while(temp!=first);

	printf("\n");

} // traverse() ends...