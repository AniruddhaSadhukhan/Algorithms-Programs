#include<iostream>
using namespace std;

//Program to implement Binary Search using recursion.
//		by Aniruddha

int binarySearchRecursion(int a[],int beg,int end,int val)
{
	int mid;
	if(beg>end)
		return -1;
	else 
	{
		mid=(beg+end)/2;
		if (val==a[mid])
			return ++mid;
		if(val<a[mid])
			return binarySearchRecursion(a,beg,mid-1,val);
		else return binarySearchRecursion(a,mid+1,end,val);
	}
}

int main()
{	
	int *arr,n,val,x,i;
	cout<<"Enter size: ";
	cin>>n;
	arr =  new int[n];
	cout<<"Enter "<<n<<" elements: ";
	for(i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Search which element?: ";
	cin>>val;
	x=binarySearchRecursion(arr,0,n-1,val);
	if(x==-1)
		cout<<"Not found\n";
	else cout<<"Position = "<<x<<endl;
	
	delete [] arr;
	return 0;
}

/*Sample Output
Enter size: 5   
Enter 5 elements: 8 9 2 47 6
Search which element?: 2
Position = 3

*/

