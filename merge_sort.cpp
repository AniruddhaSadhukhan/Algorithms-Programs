#include<iostream>
using namespace std;

//Program to implement Merge Sort.
//		by Aniruddha

void merge(int a[],int low,int mid,int high)
{
	int *b=new int[high+1],left,right,i;
	left=low;
	right=mid+1;
	i=low;
	while(left<=mid && right<=high)
	{
		if(a[left]<a[right])
			b[i++]=a[left++];
		else b[i++]=a[right++];
	}
	while(left<=mid)
		b[i++]=a[left++];
	while(right<=high)
		b[i++]=a[right++];
	for(i=low;i<=high;i++)
		a[i]=b[i];
}

void mergeSort(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergeSort(a,low,mid);
		mergeSort(a,mid+1,high);
		merge(a,low,mid,high);
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
	mergeSort(arr,0,n-1);
	cout<<"After sort       : ";
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
		
}

/*Sample Output
Enter size: 5
Enter 5 elements : 5 20 15 10 25
After sort       : 5 10 15 20 25 
*/

