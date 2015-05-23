# include <iostream>
using namespace std;

struct node
{
	int val;
	node *next;
};

class SinglyList
{
	private:
		node *top;
	public:
		SinglyList()
		{
			top=NULL;
		}
		void insertBeg(int);
		void insertEnd(int);
		int insertMid(int,int);
		int delBeg();
		int delEnd();
		int delMid(int);
		void display();
};


void SinglyList::insertBeg(int val)
{
	node *tmp= new node;
	tmp->val=val;
	tmp->next=NULL;	
	if(top==NULL)
		top=tmp;
	else
	{
		tmp->next=top;
		top=tmp;
	}
}

void SinglyList::insertEnd(int val)
{
	node *tmp= new node;
	tmp->val=val;
	tmp->next=NULL;
	if(top==NULL)
		top=tmp;
	else
	{
		node *q=top;
		while(q->next!=NULL)
			q=q->next;
		q->next=tmp;
	}
}

int SinglyList::insertMid(int val,int after)
{
	node *tmp=new node;
	tmp->val=val;
	tmp->next=NULL;
	if(top==NULL)
		return -1;
	else
	{
		node *q=top;
		while(q!=NULL && q->val!=after)
			q=q->next;
		if(q==NULL)
			return -1;
		tmp->next=q->next;
		q->next=tmp;
		return 0;
	}
}

int SinglyList::delBeg()
{
	if(top==NULL)
		return -1;
	int val=top->val;
	top=top->next;
	return val;
}

int SinglyList::delEnd()
{
	if(top==NULL)
		return -1;
	else if(top->next=NULL)
	{
		int x=top->val;
		top=NULL;
		return x;
	}
	node *q=top;
	while(q->next!=NULL && q->next->next!=NULL)
		q=q->next;
	int x=q->next->val;
	q->next=NULL;
	return x;
}

int SinglyList::delMid(int val)
{
	if(top==NULL)
		return -1;
	else if(top->next==NULL)
	{
		int x=top->val;
		top=NULL;
		return x;
	}	
	node *q=top;
	while(q->next!=NULL && q->next->val!=val)
		q=q->next;
	if(q->next==NULL)
		return -2;
	int x=q->next->val;
	q->next=q->next->next;
	return x;
}

void SinglyList::display()
{
	if(top==NULL)
		cout<<"List UnderFlow"<<endl;
	else
	{
		node *q;
		q=top;
		while(q!=NULL)
		{
			cout<<q->val<<"->";
			q=q->next;
		}
	}

}

int main()
{
	SinglyList list;
	int ch,val,after;

	while(ch)
	{
		cout<<"\n1.Insert at Begining\n2. Insert at End\n3. Insert at Middle\n4. Delete at Begining\n5. Delete at End\n6. Delete at Middle\n7. Display List\n0. Exit\n\n\tEnter your choice:\t"; cin>>ch;
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
					cout<<"Element "<<val<<" not found"<<endl;
				break;
			case 7:
				cout<<"\n\n";
				list.display();
				cout<<"\n\n";
				break;
		}
	}
}