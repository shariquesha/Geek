//Linked List geeksforgeeks questions 

#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
	int data;
	struct node *next;
};
//hash table
int hash[1000000]={0};

//print the linked list
void print_list(struct node *temp)
{
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
//insert data at the begigning of linked list
void insert_beg(struct node **head,int n)
{
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data=n;
	newnode->next=*head;
	*head=newnode;
}
//insert data at the end of a linked list
void insert_end(struct node **head,int n)
{
	struct node *newnode,*temp=*head;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data=n;
	newnode->next=NULL;
	if(*head==NULL)
	{
		*head=newnode;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
			temp->next=newnode;
	} 
}
//print reverse of a list using recursion
void print_rev(struct node *temp)
{
	if(temp==NULL)
		return;
	print_rev(temp->next);
	printf("%d",temp->data);
}

//remove duplicate elements of a sorted list
void remove_dup_sorted(struct node* temp)
{
	while(temp->next!=NULL)
	{
		if(temp->data!=temp->next->data)
		{
			temp=temp->next;
		}
		else
		{
			free(temp->next);
			temp->next=temp->next->next;
		}
	}
}
//remove duplicate elements of a unsorted list
void remove_dup_unsorted(struct node* temp)
{
	struct node *prev;
	while(temp!=NULL)
	{
		//printf("echo\n");
		
		if(!hash[temp->data])
		{
			hash[temp->data]=1;
			//printf("%d\n",temp->data );
			prev=temp;
			temp=temp->next;
		}
		else
		{

			prev->next=temp->next;
			temp=prev->next;
		}
	}
}
//swap elements of a list in pair
void swap_pair(struct node* temp)
{
	struct node *prev,*next_,*swp;
	while(1)
	{
		if(temp->next!=NULL)
		{
			prev=temp;
			next_=temp->next;
			swp->data=prev->data;
			prev->data=next_->data;
			next_->data=swp->data;
		}
		else 
			break;
		if(temp->next->next!=NULL)
		temp=temp->next->next;
		else
			temp=temp->next;

	}
}
//move last element to the front of the list
void mv_lst_frnt(struct node **head)
{
	struct node *temp1=*head,*temp2;
	while(temp1->next!=NULL)
	{
		temp2=temp1;
		temp1=temp1->next;
	}
	temp2->next=NULL;
	temp1->next=*head;
	*head=temp1;
}
/*void intrsct_sorted_lst(struct node *temp1,struct node *temp2)
{
	int hash_2[1000000]={0};
	while(temp1!=NULL)
	{
		hash_2[temp1]=1;
		temp1=temp1->next;
	}
	while(temp2!=NULL)
	{
		if(hash_2[temp2])
			printf("%d ",temp2);
		temp2=temp2->next;
	}

}*/
//delete alternate elements of a list
void alter_del(struct node *temp)
{
	struct node * buf;
		temp=temp->next;
		while(temp->next!=NULL)
		{
			temp->data=temp->next->data;
			buf=temp->next;
			temp->next=temp->next->next;
			free(buf);
			temp=temp->next;
		}

}
//alternate elements of a list are removed and inserted into an another list.
void alternating_split(struct node *temp)
{
	struct node *newnode,*buf;
	//temp=temp->next;
	while(temp!=NULL)
	{
		if(temp->next==NULL)
			break;
		buf=temp->next;
		temp->next=temp->next->next;

		insert_end(&newnode,buf->data);
		free(buf);

		temp=temp->next;
	}
	printf("List 1:\n");
	print_list(newnode);
}
//check wheather two linked list are identical or not
bool check_identical(struct node *temp1,struct node *temp2)
{
	while(temp1!=NULL && temp2!=NULL)
	{	
		if(temp1->data!=temp2->data)
			return false;
		temp1=temp1->next;
		temp2=temp2->next;
	}
	return (temp1==NULL && temp2==NULL);
}

/*----Merge sort for linked list---
//split the list 
void split(struct node *head,struct node **front,struct node** back)
{
	struct node *ptr1=head,*ptr2=head;
	if(head==NULL || head->next==NULL)
	{
		*front=head;
		*back=NULL;
	}
	else
	{
		while(ptr2!=NULL)
		{
			ptr1=ptr1->next;
			ptr2=ptr2->next;
			if(ptr2!=NULL)
			ptr2=ptr2->next;
		}
		*front=head;
		*back=ptr1->next;
		ptr1->next=NULL;
	}
}
//sort the list
struct node* sort(struct node *a,struct node *b)
{
	struct node *result;
	if(a==NULL)
		return b;
	else if(b==NULL)
		return a;
	else if(a->data >= b->data)
	{
		result=a;
		result->next=sort(a->next,b);
	}
	else if(a->data <= b->data)
	{
		result=b;
		result->next=sort(a,b->next);
	}

}
//merge the sorted list
void merge_sort(struct node **head)
{
	struct node *a,*b;
	split(*head,&a,&b);
	merge_sort(&a);
	merge_sort(&b);
	*head=sort(a,b);

}
----------------------------------*/
//reverse a linked list in a group of given size
struct node*reverseinGroup(struct node ** head,int k)
{
		struct node *current=*head,*prev,*next,*temp=*head;
		int i=0;
		while(i<k && current!=NULL)
		{	
			//printf("check\n");
			next=current->next;
			current->next=prev;
			prev=current;
			current=next;
			i++;
		}
		if(next!=NULL){
			//printf("check_recursion\n");
			temp->next=reverseinGroup(&next,k);
		}
		return prev;
}
//Reverse node alternately with given size
struct node* reversealtrnate(struct node** head,int k)
{
	struct node *prev,*next,*current=*head,*temp=*head;
	int i=0;
	while(i<k && current!=NULL)
	{
		//printf("check\n");
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
		i++;
	}
	if(current!=NULL){
		//printf("check head\n");
		temp->next=current;
	}
	i=0;
	while(i<k && current!=NULL)
	{
		//printf("check alt\n");
		current=current->next;
		i++;
	}
	if(current!=NULL){
		//printf("check recursion\n");
		current->next=reversealtrnate(&current->next,k);
	}
	return prev;
}
//delete node whose value is greater than right node
void deleteNode(struct node** head)
{
	struct node*temp=*head,*prev,*buff;
	if(temp!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}
	while(temp!=NULL)
	{
		if (temp->data > prev->data)
		{
			prev->data = temp->data;
			if(temp->next!=NULL)
			prev->next = temp->next->next;
			buff=temp;
			temp=temp->next;
			free(buff);
		}
		else
		{
			prev=temp;
			temp=temp->next;
		}
	}
}
void segregatelist(struct node** head)
{
	struct node *temp=*head,*even_head=NULL,*even_tail,*odd_head,*ptr;
	while(temp!=NULL)
	{

		if(temp->data%2==0)
		{	
			//printf("check\n");
			ptr=(struct node*)malloc(sizeof(struct node));
			ptr->data=temp->data;
			ptr->next=even_head;
			if(even_head==NULL)
				even_tail=ptr;
			even_head=ptr;
		}
		else
		{
			//printf("check\n");
			ptr=(struct node*)malloc(sizeof(struct node));
			ptr->data=temp->data;
			ptr->next=odd_head;
			odd_head=ptr;
		}
		temp=temp->next;
		//printf("%d",ptr->data );
	}
	*head=even_head;
	even_tail->next=odd_head;
}
void detectRemoveloop(struct node *head)
{
	struct node *ptr1=head,*ptr2=head;
	int count=1;
	printf("check\n");
	ptr2=ptr2->next;
	//first detect loop using floyed algorithm
	while(ptr1!=ptr2 && ptr2!=NULL)
	{
		ptr1=ptr1->next;
		ptr2=ptr2->next;
		if(ptr2!=NULL)
			ptr2=ptr2->next;

	}

	if(ptr2 == NULL)
	{
		printf("No loop found\n");
		return;
	}
	//count no of nodes in loop
	while(ptr1!=ptr2)
	{
		ptr2=ptr2->next;
		count++;
	}
	ptr1=ptr2=head;
	//move ptr2 to kth position
	while(count)
	{
		ptr2=ptr2->next;
		count--;
	}
	//move ptr1 and ptr2 to start of loop
	while(ptr1!=ptr2)
	{
		ptr1=ptr1->next;
		ptr2=ptr2->next;
	}
	//find last node of loop
	while(ptr2->next!=ptr1)
		ptr2=ptr2->next;
	ptr2->next=NULL;

}

void union_intersec(struct node *head1,struct node* head2)
{
	int i;
	for(i=0;i<1000000;i++)
	hash[i]=0;
	struct node *temp1=head1,*temp2=head2,*union_head=NULL,*intrs_head=NULL;
	while(temp1!=NULL)
	{
		hash[temp1->data]=1;
		struct node* newnode;
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=temp1->data;
		newnode->next=union_head;
		union_head=newnode;
		temp1=temp1->next;
	}
	while(temp2!=NULL)
	{
		if(!hash[temp2->data])
		{
			struct node* newnode;
			newnode=(struct node*)malloc(sizeof(struct node));
			newnode->data=temp2->data;
			newnode->next=union_head;
			union_head=newnode;
		}
		else
		{
			struct node* newnode;
			newnode=(struct node*)malloc(sizeof(struct node));
			newnode->data=temp2->data;
			newnode->next=intrs_head;
			intrs_head=newnode;
		}
		temp2=temp2->next;
	}
	printf("Union:\n");
	print_list(union_head);
	printf("\nIntersection:\n");
	print_list(intrs_head);
}

void even_odd(struct node *head)
{
	struct node *temp1=head,*temp2=head;
	//Increment pointers to skip first node
	if(temp1&&temp2->next)
	{
		temp1=temp1->next;
		temp2=temp2->next->next;
	}
	//temp1 at even position and temp2 at odd position
	while(temp2!=NULL)
	{
		//swap data of temp1 to temp2
		temp1->data=temp1->data+temp2->data;
		temp2->data=temp1->data-temp2->data;
		temp1->data=temp1->data-temp2->data;

		//increment pointers
		temp1=temp1->next;
		temp2=temp2->next;
		if(temp2!=NULL)
			temp2=temp2->next;
	}
}

int main()
{
	int choice,data,k;
	struct node *head;
	while(1)
	{	
		printf("\nEnter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter data\n");
				scanf("%d",&data);
				insert_beg(&head,data);
				printf("\n");
				print_list(head);
				break;
				case 2:
					printf("Enter data\n");
					scanf("%d",&data);
					insert_end(&head,data);
					printf("\n");
					print_list(head);
					break;
					case 3:
						printf("List in reverse order using recursion is :\n");
						print_rev(head);
						break;
						case 4:
							printf("List after removal of duplicates\n");
							remove_dup_sorted(head);
							print_list(head);
							break;
							case 5:
								printf("List after removal of duplicates\n");
								remove_dup_unsorted(head);
								print_list(head);
								break;
								case 6:
									printf("List after swapping in pair\n");
									swap_pair(head);
									print_list(head);
									break;
									case 7:
										printf("List after moving last to front\n");
										mv_lst_frnt(&head);
										print_list(head);
										break;
										case 8:
											/*printf("Intersection of two sorted linked list\n");
											intrsct_sorted_lst(head);
											*/
											break;
											case 9:
												printf("List after deleting nodes alternately\n");
												alter_del(head);
												print_list(head);
												break;
												case 10:
													printf("List after alternating_split\n");
													alternating_split(head);
													printf("\nList 2:\n");
													print_list(head);
													break;
													case 11:
														if(check_identical(head,head))
															printf("identical\n");
														else
															printf("Unidentical\n");
														break;
														case 12:
														    /*
														 	printf("Sorted list using merge sort\n");
														 	merge_sort(&head);
														 	print_list(head);
														 	break;
														 	*/
														 	case 13:
														 		printf("Enter group size\n");
														 		scanf("%d",&k);
														 		head=reverseinGroup(&head,k);
														 		print_list(head); 
														 		break;
														 		case 14:
														 			printf("Enter group size\n");
														 			scanf("%d",&k);
														 			head=reversealtrnate(&head,k);
														 			print_list(head);
														 			break;
														 			case 15:
														 				deleteNode(&head);
														 				print_list(head);
														 				break;
														 				case 16:
														 					segregatelist(&head);
														 					print_list(head);
														 					break;
														 					//detect and remove loop
														 					case 17:
														 						detectRemoveloop(head);
														 						break;
														 						//union and intersection 
														 						case 18:
														 							union_intersec(head,head);
														 							break;
														 							case 19:
														 								even_odd(head);
														 								print_list(head);
														 								break;


        }
		
	}	
	return 0;
}