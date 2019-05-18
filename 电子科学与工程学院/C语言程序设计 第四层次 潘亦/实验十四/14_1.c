#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct node
{
     int n;
	 struct node *next;
}NODe;
NODe * Create(void);
void display(NODe *head);
void free_all(NODe *head);
int main()
{
	NODe *head=Create();
	display(head);
	free_all(head);
	system("pause");
	return 0;
}
NODe *Create(void)
{
	NODe *p;
	NODe *head;
	p = (NODe*)malloc(sizeof(NODe));
	p->next = NULL;
	head = p;
	for(;;)
	{
		p = (NODe*)malloc(sizeof(NODe));
		cin >> p->n;
		if (p->n != 0)
		{
			p->next = head->next;
			head->next = p;
		}
		else
		{
			free(p);
			break;
		}
	} 
	return head;
}
void display(NODe *head)
{
	NODe *p = head->next;
	while (p!= NULL)
	{
		cout <<p<<" "<< p->n << endl;		
		p = p->next;
	}
}
void free_all(NODe *head)
{
	NODe *p = head->next;
	NODe *t;
	while (p->next!= NULL)
	{
		t = p->next;
		free(p);
		p = t;
	}
}