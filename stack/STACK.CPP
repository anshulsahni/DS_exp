# include <iostream.h>
# include <conio.h>

//constants
#define SIZE 100

class stack                              //class stack
  {
	private:
	  int data[SIZE];
	  int pos;
	public:
	  stack()                     //constructor to initialize pos
	  {pos=-1;}
	  int push(int);             //function to push value
	  int  pop();               //function to pop value
	  int empty();              //function to check whether stack is empty
	  void showList();          //function to show current values in stack
  };

int stack::push(int x)
 {
	if(pos>=SIZE-1)
		return -1;	//if stack is overflowed
	else
	{
		data[++pos]=x;
		return 0;
	}
 }


int stack::pop()
 {
	if(pos<=-1)
		return -1;      //if stack is underflowed
	else
		return data[pos--];
 }

int stack::empty()
 {
	if(pos<=-1)
		return 1;	//if stack is empty
	else
		return 0;	//if stack is not empty
 }

void stack::showList()
 {
	for(int i=0;i<=pos;i++)
	 cout<<data[i]<<" ";
 }

//stack implementation
void main()
 {
	clrscr();
	stack s1;
	int ch,ans=1,val;

	while(ans)
	{
		clrscr();
		cout<<"1. Push Opertation\n2. Pop Operation\n3. Show Stack\n4. Is Stack Empty?\n0. Exit\n\t\tEnter your choice:\t"; cin>>ch;
		switch(ch)
		{
			case 1:
				clrscr();
				cout<<"Enter the value to be entered:\t"; cin>>val;
				if(s1.push(val)==-1)
					cout<<"\n\t\aStack Overflow";
				else
					cout<<"\n\t\aValue Entered";
			break;
			case 2:
				clrscr();
				val=s1.pop();
				if(val==-1)
					cout<<"\n\t\aStack Underflow";
				else
					cout<<"\n\t\aValue:\t"<<val<<" poped out of stack";
			break;
			case 3:
				clrscr();
				cout<<"Current stack status is:\t"; s1.showList();
			break;
			case 4:
				clrscr();
				if(s1.empty()==1)
					cout<<"Stack is Empty";
				else
					cout<<"Stack still has space to accomodate";
			break;
			case 0:
				ans=0;
				continue;
			default:
				continue;
		}
		cout<<"\n\n\t\tWant to continue(Y=1/N=0):\t"; cin>>ans;
	}
	cout<<"\nPress any key to exit application\a.\a.\a.";
	getch();
 }