#include<iostream>
using namespace std;

//Program to implement Quick Sort.(Lomuto Partition)
//		by Aniruddha

void swap(int &a, int &b)
{
    a=a+b-(b=a);
}

int partition(int a[],int low,int high)
{
    int pivot=a[high];
    int i = low;
    for(int j=low;j<=high-1;j++)
        if (a[j]<= pivot)
        {
            swap(a[i],a[j]);
            i++;
        }
    swap(a[i],a[high]);
    return i;
}
void quickSort(int a[],int low,int high)
{
    if(low<high)
	{
		int p=partition(a,low,high);
		quickSort(a,low,p-1);
		quickSort(a,p+1,high);
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
	quickSort(arr,0,n-1);
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

