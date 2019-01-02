#include<iostream>
#include<vector>
using namespace std;

//Program to implement Heap Sort
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

void heapsort(int *a,int n) 
{
	buildMaxHeap(a,n);
	//one by one extract an element from heap
	for(int i=n-1;i>=0;i--)
	{
		//move current root to end
		a[i] = a[i] + a[0] - (a[0] = a[i] );
		//call MaxHeapify on reduced heap
		maxHeapify(a,i,0);	
	}
}

int main()
{	
	int n,i,a;
	cout<<"Enter size: ";
	cin>>n;
	vector<int> arr;
	cout<<"Enter "<<n<<" elements : ";
	for(i=0;i<n;i++)
		cin>>a,arr.push_back(a);
	heapsort(&arr[0],n);
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


