//file to implement circular queue in c++
#include <iostream>
//#include <conio>
#define MAX 5
using namespace std;

class circular_queue
{
	private:
		int arr[10];
		int rear,front;
	public:

		circular_queue()
		{	rear=front=-1; }
		int enqueue(int);
		int dqueue();
		void display();
};

int circular_queue::enqueue(int val)
{
	cout<<"\n"<<front<<"?"<<rear;
	if((front==0 && rear==MAX-1) || front==rear+1)
		return -1;
	else if(front==-1)
	{
		arr[++rear]=val;
		front++;
	}
	else if(rear==MAX-1)
	{
		rear=0;
		arr[rear]=val;
	}
	else
		arr[++rear]=val;
	return 0;

}

int circular_queue::dqueue()
{
	cout<<"\n"<<front<<"?"<<rear;
	if(front==-1 || front>rear)
		return -1;
	else
	{
		int x=arr[front];
			arr[front]=0;
		if(front==MAX-1)	
			{
				if(rear==MAX-1)
					{ front=-1; rear=-1;}
				else
					front=0;
			}
		else
			front++;
		return x;
	}
}

void circular_queue::display()
{
	if(front==-1 || front>rear)
		cout<<"Queue empty";
	else
	{
		int i=front;
		while(i!=rear)
		{
			cout<<arr[i]<<".";
			if(i==MAX-1)
				i=0;
			else
				i++;
		}
		cout<<arr[i];
	}
	cout<<endl;

}

int main()
{
 circular_queue cq;
	int ans=1,ch,val;

	while(ch)
	{
		//clrscr();
		cout<<"1. Enqueue Value\n2. Dqueue Value\n3. Show Queue\n0. Exit\n\n\tEnter your choice:\t"; cin>>ch;
		switch(ch)
		{
			case 1:
				//clrscr();
				cout<<"Enter the value:\t"; cin>>val;
				if(cq.enqueue(val)==-1)
					cout<<"\n\nQueue overflow"<<endl;
				else
					cout<<"\n\nValue Inserted"<<endl;
			break;
			case 2:
				//clrscr();
				val=cq.dqueue();
				if(val==-1)
					cout<<"\n\nQueue Underflow"<<endl;
				else
					cout<<"Value:\t"<<val<<"\tdqueued"<<endl;
			break;
			case 3:
				//clrscr();
				cout<<"Current queue list:\t";cq.display();
			break;
			case 0:
				ans=0;
				continue;
			default:
				continue;
		}
	}
	cout<<"\n\nPress any key to exit...";


}