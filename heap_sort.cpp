#include<iostream>
using namespace std;

//Program to implement Heap Sort
//		by Aniruddha

void heapify(int a[],int n) 
{
	int k,i,j,item;
	for (k=1;k<n;k++) 
	{
		item = a[k];
		i = k;
		j = (i-1)/2;
		while((i>0)&&(item>a[j])) 
		{
			a[i] = a[j];
			i = j;
			j = (i-1)/2;
		}
		a[i] = item;
	}
}

void adjust(int a[],int n) 
{
	int i,j,item;
	j = 0;
	item = a[j];
	i = 2*j+1;
	while(i<=n-1) 
	{
		if(i+1 <= n-1)
		   if(a[i] <a[i+1])
		i++;
		if(item<a[i]) 
		{
			a[j] = a[i];
			j = i;
			i = 2*j+1;
		} 
		else break;
	}
	a[j] = item;
}

void heapsort(int a[],int n) 
{
	int i,t;
	heapify(a,n);
	for (i=n-1;i>0;i--) 
	{
		t = a[0];
		a[0] = a[i];
		a[i] = t;
		adjust(a,i);
	}
}

int main()
{	
	int *arr,n,i;
	cout<<"Enter size: ";
	cin>>n;
	arr =  new int[n];
	cout<<"Enter "<<n<<" elements : ";
	for(i=0;i<n;i++)
		cin>>arr[i];
	heapsort(arr,n);
	cout<<"After sort        : ";
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;		
}

/*Sample Output
Enter size: 10
Enter 10 elements : 564 65 152 54 498 35 16 258 57 47 
After sort        : 16 35 47 54 57 65 152 258 498 564 
*/


