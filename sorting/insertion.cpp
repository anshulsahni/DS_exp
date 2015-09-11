#include <iostream>
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
		int j=i;
		while(j>0 && ar[j]<ar[j-1]){
			int temp=ar[j];
			ar[j]=ar[j-1];
			ar[j-1]=temp;
			j--;
		}
	}

	for(int i=0;i<n;i++)
		cout<<ar[i]<<",";
	cout<<endl;
	return 0;
}