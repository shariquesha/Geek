//Single Link List
#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node * next;
};

class linklist
{
	struct node *first;
	public:
	linklist()
	{first=NULL;}
	void additem_beg(int);
	void additem_end(int);
	void delitem_beg();
	void delitem_end();
	void delitem_spec(int);
	void display();
	node* ret_first();
	void swap_nodes(int ,int );
	void rev_list();
	void merge_list(linklist,linklist);
	//void rev_list_size();
	int search(int);
	int getNthnode(int);
	int ret_middle();
	int ret_nth_end(int);
	void del_list();
	void count_rep();
	int detect_loop();
	void ins_sort(int);
	void del_using_pointer(int);
	void check_palindrome();
};
void linklist::additem_beg(int d)
{
	struct node* newnode;
	newnode=new (struct node);
	newnode->data=d;
	newnode->next=first;
	first=newnode;
}
void linklist::additem_end(int d)
{
	struct node* newnode,*temp;
	newnode = new (struct node);
	newnode->data=d;
	if(first==NULL)
	{
		first=newnode;
		first->next=NULL;
	}
	else
	{
		temp=first;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->next=NULL;
	}
	
}
void linklist::delitem_beg()
{
	struct node* temp=first;
	if(first==NULL)
	{
		cout<<"Underflow"<<endl;
	}
	else
	{
		first=temp->next;
		delete temp;
	}
}
void linklist::delitem_end()
{
	struct node* temp=first,*p;
	if(first->next==NULL)
	{
		cout<<"Underflow"<<endl;
	}
	else
	{
		while(temp->next!=NULL)
		{
			p=temp;
			temp=temp->next;
		}
		p->next=NULL;
		delete temp;
	}
}

void linklist::delitem_spec(int d)
{
	struct node* temp=first,*p;
	if(first==NULL)
	{
		cout<<"Underflow"<<endl;
	}
	else
	{
		while(temp->data!=d)
		{
			p=temp;
			temp=temp->next;
		}
		p->next=temp->next;
		delete temp;
	}
}
int rec_iter(struct node*temp)
{
	if(temp->next==NULL)
		return 1;
	else
		return rec_iter(temp->next)+1;
}

node* linklist::ret_first()
{
	return first;
}

void linklist::swap_nodes(int t1,int t2)
{
	struct node* temp=first,*temp1,*temp2,*temp3,*temp4;
	while(temp!=NULL)
	{
		if(temp->data == t1)
		{
			if(temp==first)
				temp3=first;
			temp1=temp;
			break;
		}
		temp3=temp;
		temp=temp->next;
	}
	temp=first;
	
	while(temp!=NULL)
	{
		if(temp->data == t2)
		{
			temp2=temp;			
			break;
		}
		temp4=temp;
		temp=temp->next;
	}
	//cout<<"|temp1="<<temp1<<"|temp2="<<temp2<<"|temp3="<<temp3<<"|temp4="<<temp4<<endl;
	temp3->next=temp2;
	temp4->next=temp1;
	temp1->next=temp2->next;
	temp2->next=temp1->next;
	if(temp1==first&&temp3==first&&temp4==first)
		first=temp2;
}
void linklist :: rev_list()
{
	struct node *temp=first,*p,*q;
	p=temp;
	q=temp->next;
	temp->next=NULL;
	while(q!=NULL)
	{
		temp=q;
		q=temp->next;
		temp->next=p;
		p=temp;
	}
	first=p;
}
void linklist::merge_list(linklist l1,linklist l2)
{
	
	while(1)
	{
		if(l1.first!=NULL && l2.first!=NULL)
		{

			if(l1.first->data >= l2.first->data)
			{
				this->additem_end(l2.first->data);
				l2.delitem_beg();
			}
			else
			{
				this->additem_end(l1.first->data);
				l1.delitem_beg();
			}
		}
		else if(l1.first==NULL && l2.first!=NULL)
		{	
				//cout<<"check";
				this->additem_end(l2.first->data);
				l2.delitem_beg();
		}
		else if(l1.first!=NULL && l2.first==NULL)
		{	
				//cout<<"check";
				this->additem_end(l1.first->data);
				l1.delitem_beg();
		}
		else 
			break;
	}
}
/*void linklist::rev_list_size(int k)
{
	int count=1;
	struct node *temp=first,*p,*q;
	p=temp;
	q=temp->next;
	temp->next=NULL;
	while(count!=k)
	{
		temp=q;
		q=temp->next;
		temp->next=p;
		p=temp;
	}
	first=p;	
}*/
int linklist::search(int n)
{
	struct node* temp=first;
	while(temp!=NULL)
	{
		if(temp->data == n)
			return 1;
		temp=temp->next;
	}
	return 0;
}
int linklist::getNthnode(int n)
{
	jump:int count=1;
	struct node* temp=first;
	while(temp!=NULL && count!=n)
	{
		temp=temp->next;
		count++;
	}
	if(temp==NULL){
		cout<<"Node number exceeded\nEnter node number again"<<endl;
		cin>>n;
		goto jump;
	}

	return temp->data;
}
int linklist::ret_middle()
{
	struct node *temp1,*temp2;
	temp1=first;
	temp2=first;
	while(temp2->next!=NULL && temp2!=NULL )
	{
		//cout<<temp1<<" "<<temp2<<endl;
		//cout<<"check"<<endl;
		temp2=temp2->next->next;
		temp1=temp1->next;
	}
	//cout<<"check";
	return temp1->data;
}
int linklist::ret_nth_end(int n)
{
	struct node *temp1=first,*temp2=first;
	while(n)
	{
		temp2=temp2->next;
		n--;
	}
	while(temp2!=NULL)
	{
		temp2=temp2->next;
		temp1=temp1->next;
	}
	return temp1->data;
}
void linklist::del_list()
{
	while(first!=NULL)
		this->delitem_beg();
}
void linklist::count_rep()
{
	struct node* temp=first; 
	int a[1000]={0},i=0;
	while(temp!=NULL)
	{
		a[temp->data]++;
		temp=temp->next;
	}
	while(i!=1000)
	{	
		if(a[i])
		cout<<i<<"=="<<a[i]<<" ";
		i++;
	}
}
int linklist::detect_loop()
{
	struct node *temp1=first,*temp2=first;
	if(first!=NULL)
	{
		while(1)
		{
			temp1=temp1->next;
			temp2=temp2->next->next;
			if(temp2==NULL)
			{
				cout<<"List has not any loop"<<endl;
				break;
			}
			else if(temp1==temp2)
			{
				cout<<"List has loop"<<endl;
				break;
			}
		}
	}
	else
	{
		cout<<"Create list first"<<endl;
	}
	return 0;	
}
void linklist::ins_sort(int n)
{
	struct node *temp=first;
	struct node *newnode;
	newnode=new(struct node);
	newnode->data=n;
	if(first->data > n)
	{
		newnode->next=first;
		first=newnode;
	}
	else
	{
		while(temp->next!=NULL)
		{
			if(temp->next->data > n)
			{
				newnode->next = temp->next;
				temp->next=newnode;
				break;
			}
			temp=temp->next;
		}
		if(temp->next == NULL && temp->data < n)
		{
			temp->next=newnode;
			newnode->next=NULL;
		}
	}

}
void linklist::del_using_pointer(int n)
{
	struct node *temp=first,*ptr;
	while(temp->next->data!=n)
		temp=temp->next;
	ptr=temp->next;
	//now using ptr,delete the node
	temp=first;
	while(temp!=ptr)
		temp=temp->next;
	temp->data=temp->next->data;
	temp->next=temp->next->next;
	//delete temp;
}
void  linklist::check_palindrome()
{
	cout<<"hello";
}
void linklist::display()
{
	struct node* current=first;
	if(first!=NULL)
	{
		while(current!=NULL)
		{
			cout<<current->data;
			current=current->next;
		}
	}
	else
		cout<<"List not found"<<endl;
}
int main()
{
	linklist l1,l2,l3;
	int i,n;
	cout<<"1.insert at first\t2.insert at end\n3.delete from first\t4.delete from end\n5.delete a spec item\t6.show list\n7.lenght of a linklist\t8.swap node without swapping data\n9.Reverse the List\t10.Merge two sorted linklist\n11.Reverse a Linked List in groups of given size\t12.Search an item\n13.Get Nth data\t\t14.Find Middle element of the linklist\n";
while(1)
{
	cout<<"\nEnter your choice"<<endl;
	cin>>i;
	switch(i)	{
		case 1:
			cout<<"enter data"<<endl;
			cin>>n;
			l1.additem_beg(n);
			break;
			case 2:
				cout<<"enter data"<<endl;
				cin>>n;
				l1.additem_end(n);
				break;
				case 3:
					l1.delitem_beg();
					break;
					case 4:
						l1.delitem_end();
						break;
						case 5:
							cout<<"enter data"<<endl;
							cin>>n;
							l1.delitem_spec(n);
							break;
							case 6:
								l1.display();
								break;
								case 7:
									struct node *temp;
									temp=l1.ret_first();
									cout<<"node count using recursion"<<rec_iter(temp)<<endl;
									break;
									case 8:
										int d1,d2;
										cout<<"enter nodes "<<endl;
										cin>>d1>>d2;
										l1.swap_nodes(d1,d2);
										break;
										case 9:
											l1.rev_list();
											break;
											case 10:
												int n,i,item;
												cout<<"Enter number of elements in list 1"<<endl;
												cin>>n;
												for(i=0;i<n;i++)
												{
													cin>>item;
													l1.additem_end(item);
												}
												cout<<"Enter number of elements in list 2"<<endl;
												cin>>n;
												for(i=0;i<n;i++)
												{
													cin>>item;
													l2.additem_end(item);
												}
												l3.merge_list(l1,l2);
												cout<<"sorted List"<<endl;
												l3.display();
												break;
												case 11:
													/*int k;
													cout<<"Enter group size"<<endl;
													cin>>k;
													l1.rev_list_size(k);*/
													break;
													case 12:
														//int n;
														cout<<"enter Data to be searched"<<endl;
														cin>>n;
														if(l1.search(n))
															cout<<"Data Found"<<endl;
														else
															cout<<"Data not found"<<endl;
														break;
														case 13:
															cout<<"Enter Node number"<<endl;
															cin>>n;
															cout<<"node data is "<<l1.getNthnode(n)<<endl;
															break;
															case 14:
																cout<<"check"<<endl;
																cout<<"Middle element is:"<<l1.ret_middle()<<endl;
																break;
																case 15:
																	cout<<"enter n"<<endl;
																	cin>>n;
																	cout<<"Nth node from end = "<<l1.ret_nth_end(n)<<endl;
																	break;
																	case 16:
																		l1.del_list();
																		break;
																		case 17:
																			l1.count_rep();
																			break;
																			case 18:
																				l1.detect_loop();
																				break;
																				case 19:
																					cout<<"Enter data"<<endl;
																					cin>>n;
																					l1.ins_sort(n);
																					break;
																					case 20:
																						cout<<"Enter Node"<<endl;
																						cin>>n;
																						l1.del_using_pointer(n);
																						break;
																						case 21:
																							l1.check_palindrome();




												
	}
}
	return 0;
}
