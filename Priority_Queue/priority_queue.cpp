# include <iostream>
using namespace std;

struct node
{
	int priority;
	int val;
	node *next;
};

class Priority_Queue
{
	private:
		node *front;
	public:
		Priority_Queue()
		{
			front=NULL;
		}

		void insert(int,int);
		int del();
		void display();
};

void Priority_Queue::insert(int x,int priority)
{
	node *tmp,*q;
	tmp=new node;
	tmp->val=x;
	tmp->priority=priority;
	tmp->next=NULL;

	if(front==NULL)
		{front=tmp; cout<<1;}
	else if(tmp->priority < front->priority)
	{
		tmp->next=front;
		front=tmp;
	}
	else
	{
		q=front;
		while(q->next!=NULL && tmp->priority >= q->next->priority)
			q=q->next;
		tmp->next=q->next;
		q->next=tmp;
	}

}

int Priority_Queue::del()
{
	if(front->next==NULL)
		return -1;
	else
	{
		int x=front->val;
		front=front->next;
		return x;
	}
}

void Priority_Queue::display()
{
	node *q;
	q=front;
	cout<<"Front>>";
	while(q!=NULL)
	{
		cout<<q->val<<">>";
		q=q->next;
	}
	cout<<"--";
}

int main(int argc,char *argv[])
{
	Priority_Queue pq;
	int ch,val,prio;

	while(ch)
	{
		cout<<"1. Insert Value\n2. Delete Value\n3. Display Queue\n0. Exit\n\n\t\tEnter Your Choice:\t"; cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter the value:\t"; cin>>val;
				cout<<"\nEnter the priority:\t"; cin>>prio;
				pq.insert(val,prio);
				cout<<"\n\tValue Inserted"<<endl;
				break;
			case 2:
				val=pq.del();
				if(val==-1)
					cout<<"\n\n\tQueue Underflow"<<endl;
				else
					cout<<"\n\n\tEelement "<<val<<" removed"<<endl;
				break;
			case 3:
				cout<<"\n\n";
				pq.display();
				cout<<"\n\n";
			case 0:
				continue;
			default:
				continue;
		}
	}
	cout<<"\n\n\tPress any key to exit...."<<endl;
}