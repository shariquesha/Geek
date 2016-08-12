#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node * next;
};

class CLL
{
	struct node * first;
	public:
		CLL(){
			first=NULL;
		}
		void add_item(int);
		void print_list();
		void split_list();

};

void CLL::add_item(int item)
{
	struct node *newnode,*temp=first;
	newnode = new (struct node);
	newnode->data=item;
	
	
	if(first == NULL)
	{
		first=newnode;
		newnode->next=first;
	}
	else //(first!==NULL)
	{
		while(temp->next!=first)
			temp=temp->next;
		
		newnode->next=first;
	    first=newnode;
		temp->next=first;
	}
	
}
void CLL::split_list()
{
	struct node* temp1=first,* temp2=first,*prev=first;
	while(temp2->next!=first)
	{
		prev=temp1;
		temp1=temp1->next;
		temp2=temp2->next;
		if(temp2->next!=first)
			temp2=temp2->next;
	}
	
	prev->next=first;
	CLL::print_list();
	cout<<endl;
	temp2->next=temp1;
	first=temp1;
	CLL::print_list();	
	cout<<endl;
	
}
void CLL::print_list()
{
	struct node * temp=first;
	do
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}while(temp!=first);
}
int main()
{
	CLL l1;
	l1.add_item(1);
	l1.add_item(2);
	l1.add_item(3);
	l1.add_item(4);
	l1.add_item(5);
	l1.add_item(6);
	l1.add_item(7);
	l1.add_item(8);
	l1.add_item(9);
	l1.print_list();
	cout<<endl;
	//split circular ll
	l1.split_list();
	cout<<endl;
}