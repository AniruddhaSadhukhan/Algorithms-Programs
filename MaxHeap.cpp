#include<iostream>
#include<vector>
using namespace std;

//Program to implement Max Heap
//		by Aniruddha

void maxHeapify(int *a,int n,int i) 
{
	int largest = i;	//initialise largest as root
	int l = 2*i + 1;	//left 
	int r = 2*i + 2;	//right
	
	//if left child is larger than root
	if(l<n && a[l] > a[largest])
		largest = l;
		
	//if right child is larger than root
	if(r<n && a[r] > a[largest])
		largest = r;
		
	//if largest is not root
	if(largest != i )
	{
		//move largest to  root 
		a[i] = a[i] + a[largest] - (a[largest] = a[i] );
		
		//recursively heapify the affected subtree
		maxHeapify(a,n,largest);
	}	
}

void buildMaxHeap(int *a,int n) 
{
	for(int i=n/2 -1;i>=0;i--)
		maxHeapify(a,n,i);
}

int parent(int i)
{
	return (i-1)/2;
}
void insert(int *a,int val,int &n)
{
	n++;
	int i = n-1;
	a[i] = val;
	while (i!=0 && a[parent(i)] < a[i]) 
	{
		a[parent(i)] = a[i] + a[parent(i)] - (a[i] = a[parent(i)]);
		i = parent(i);
	}
}

int main()
{	
	int n,i,a;
	cout<<"Enter size: ";
	cin>>n;
	vector<int> arr;
	cout<<"Enter "<<n<<" elements  : ";
	for(i=0;i<n;i++)
		cin>>a,arr.push_back(a);
	buildMaxHeap(&arr[0],n);
	cout<<"After heapify      : ";
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	insert(&arr[0],85,n);
	cout<<"After inserting 85 : ";
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	insert(&arr[0],100,n);
	cout<<"After inserting 100: ";
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;		
}

/*Sample Output
Enter size: 12
Enter 12 elements : 25 4 80 56 92 12 0 10 15 45 5 20 
After heapify      : 92 56 80 25 45 20 0 10 15 4 5 12 
After inserting 85 : 92 56 85 25 45 80 0 10 15 4 5 12 20 
After inserting 100: 100 56 92 25 45 80 85 10 15 4 5 12 20 0
*/


