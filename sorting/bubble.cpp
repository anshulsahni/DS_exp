// bubble sort
# include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int ar[n];
	for(int i=0;i<n;i++)
		cin>>ar[i];
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<n-i;j++)
		{
			if(ar[j]<ar[j-1])
			{
				ar[j]=ar[j]+ar[j-1];
				ar[j-1]=ar[j]-ar[j-1];
				ar[j]-=ar[j-1];
			}
		}
	}

	for(int i=0;i<n;i++)
		cout<<ar[i]<<",";
	cout<<endl;
	return 0;
}