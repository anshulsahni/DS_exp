# include <iostream>
using namespace std;

struct node
{
	int val;
	node *next;
	node *prev;
};

class doublyList
{
	private:
		node *head;
		node *tail;
	public:
		doublyList()
		{
			head=NULL;
			tail=NULL;
		}
		void insertBeg(int);
		void insertEnd(int);
		int insertMid(int,int);

		int delBeg();
		int delEnd();
		int delMid(int);

		void display();
		void displayRev();
};

void doublyList::insertBeg(int val)
{
	node *tmp = new node;
	tmp->val=val;
	tmp->next=NULL;
	tmp->prev=NULL;

	if(head==NULL)
	{
		head=tmp;
		tail=tmp;
	}
	else
	{
		tmp->next=head;
		head->prev=tmp;
		head=tmp;
	}
}

void doublyList::insertEnd(int val)
{
	node *tmp=new node;
	tmp->val=val;
	tmp->next=NULL;
	tmp->prev=NULL;

	if(head==NULL)
	{
		head=tmp;
		tail=tmp;
	}
	else
	{
		tail->next=tmp;
		tmp->prev=tail;
		tail=tmp;
	}
}

int doublyList::insertMid(int val,int after)
{
	node *tmp = new node;
	tmp->val=val;
	tmp->next=NULL;
	tmp->prev=NULL;

	if(head==NULL)
		return -1;
	else
	{
		node *q=head;
		while(q!=NULL && q->val!=after)
			q=q->next;
		if(q==NULL)
			return -1;
		else
		{
			tmp->next=q->next;
			tmp->prev=q;
			q->next=tmp;
			if(q!=tail)
				tmp->next->prev=tmp;
			else
				tail=tmp;
			return 0;
		}
	}

}

int doublyList::delBeg()
{
	if(head==NULL)
		return -1;
	else if(head==tail)
	{
		int x=head->val;
		delete head;
		head=tail=NULL;
		return x;
	}
	else
	{
		int x=head->val;	
		head=head->next;
		delete head->prev;
		head->prev=NULL;
		return x;
	}
}

int doublyList::delEnd()
{
	if(head==NULL)
		return -1;
	else if(head==tail)
	{
		int x=head->val;
		delete head;
		head=tail=NULL;
		return x;
	}
	else
	{
		int x=tail->val;
		tail=tail->prev;
		delete tail->next;
		tail->next=NULL;
		return x;
	}
}

int doublyList::delMid(int x)
{
	if(head==NULL)
		return -1;
	else if(head==tail)
	{
		if(head->val==x)
		{
			delete head;
			head=tail=NULL;
			return x;
		}
		else
			return -2;
	}
	else
	{
		node *q=head;
		while(q->next!=NULL && q->val!=x)
			q=q->next;
		if(q->val==x)
		{
			if(q==head)
				return delBeg();
			else if(q==tail)
				return delEnd();
			else
				q->next->prev=q->prev;
				q->prev->next=q->next;
			delete q;
			return x;
		}
		else
			return -2;
	}
}

void doublyList::display()
{
	if(head==NULL)
		cout<<"List Underflow";
	else
	{
		node *q=head;
		while(q!=NULL)
		{
			cout<<q->val<<"<>";
			q=q->next;
			
		}
	}
}

void doublyList::displayRev()
{
	if(head==NULL)
		cout<<"List Underflow";
	else
	{
		node *q=tail;
		while(q!=NULL)
		{
			cout<<q->val<<"<>";
			q=q->prev;
			
		}
	}	
}

int main()
{
	doublyList list;
	int ch;
	int val,after;
	while(ch)
	{
		cout<<"\n1.Insert at Begining\n2. Insert at End\n3. Insert at Middle\n4. Delete at Begining\n5. Delete at End\n6. Delete at Middle\n7. Display List\n8. Reverse Display List\n0. Exit\n\n\tEnter your choice:\t"; cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter the element to be inserted:\t"; cin>>val;
				list.insertBeg(val);
				cout<<"\n\tEelement Inserted at the Begining"<<endl;
				break;
			case 2:
				cout<<"Enter the element to be inserted:\t"; cin>>val;
				list.insertEnd(val);
				cout<<"\n\tElement Inserted at the end"<<endl;
				break;
			case 3:
				cout<<"Enter the element to be inserted:\t"; cin>>val;
				cout<<"Enter the element after which it should be inserted:\t"; cin>>after;
				if(list.insertMid(val,after)==-1)
					cout<<"After element not found";
				else
					cout<<"Element inserted after "<<after<<"in the list"<<endl;
				break;
			case 4:
				val=list.delBeg();
				if(val==-1)
					cout<<"List UnderFlow"<<endl;
				else
					cout<<"Element "<<val<<"removed";
				break;
			case 5:
				val=list.delEnd();
				if(val==-1)
					cout<<"List UnderFlow"<<endl;
				else
					cout<<"Element "<<val<<"removed";
				break;
			case 6:
				cout<<"Enter the element to be removed:\t"; cin>>val;
				val=list.delMid(val);
				if(val==-1)
					cout<<"List UnderFlow"<<endl;
				else if(val==-2)
					cout<<"Element not found"<<endl;
				else
					cout<<"Element "<<val<<" delete"<<endl;
				break;
			case 7:
				cout<<"\n\n";
				list.display();
				cout<<"\n\n";
				break;
			case 8:
				cout<<"\n\n";
				list.displayRev();
				cout<<"\n\n";
			case 0:
				break;
			default:
				break;
		}
	}
}