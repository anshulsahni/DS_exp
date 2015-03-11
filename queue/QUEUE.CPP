# include<iostream.h>
# include<conio.h>

//constants
#define SIZE 100

//class for queue
class QUEUE
 {
	private:
		int rear;		//variable pointing at rear position
		int front;		//variable pointing at front position
		int data[SIZE];		//array to hold values
	public:
		QUEUE()
		  {rear=front=-1;}	//initialization of pointers
		int enqueue(int);	//function to insert values
		int dqueue();		//function to remove values
		void showQueue();	//function to display queue elements
 };

 int QUEUE::enqueue(int x)
 {
	if(front==-1 && rear==-1)
	{
		front++; rear++;  data[front]=x;
	}
	else if(rear>SIZE-1)
		return -1;
	else if(front>rear)
		return -1;
	else
		data[++rear]=x;
	return 0;
 }

 int QUEUE::dqueue()
 {
	if(front==rear==-1)
		return -1;
	if(front>rear)
		return -1;
	else
		return data[front++];
 }

 void QUEUE::showQueue()
 {
	for(int i=front;i<=rear;i++)
		cout<<data[i]<<" ";
 }

//QUEUE implementation
 void main()
 {
	clrscr();
	QUEUE q1;
	int ans=1,ch,val;

	while(ans)
	{
		clrscr();
		cout<<"1. Enqueue Value\n2. Dqueue Value\n3. Show Queue\n0. Exit\n\n\tEnter your choice:\t"; cin>>ch;
		switch(ch)
		{
			case 1:
				clrscr();
				cout<<"Enter the value:\t"; cin>>val;
				if(q1.enqueue(val)==-1)
					cout<<"\n\nQueue overflow";
				else
					cout<<"\n\nValue Inserted";
			break;
			case 2:
				clrscr();
				val=q1.dqueue();
				if(val==-1)
					cout<<"\n\nQueue Underflow";
				else
					cout<<"Value:\t"<<val<<"\tdqueued";
			break;
			case 3:
				clrscr();
				cout<<"Current queue list:\t";q1.showQueue();
			break;
			case 0:
				ans=0;
				continue;
			default:
				continue;
		}
		cout<<"\n\n\tDo you want to continue(Y=1/N=0):\t"; cin>>ans;
	}
	cout<<"\n\nPress any key to exit...";
	getch();
 }
