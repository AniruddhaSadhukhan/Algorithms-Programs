#include<iostream>
using namespace std;

//Program to implement insertion_sort
//		by Aniruddha

void insertionSort(int *a,int n)
{
        int i,j,temp;
        for(i = 1;i<n;i++)
        {
                temp = a[i];
                for(j=i;j>0 && temp<a[j-1];j--)
                       a[j]=a[j-1];
                a[j]=temp;
        }
}

int main()
{
        int n;
        cout<<"Enter no of elements :";
        cin>>n;
        int *arr = new int[n];
        cout<<"Enter elements :";
        for(int i=0;i<n;i++)
                cin>>arr[i];
        insertionSort(arr,n);
        cout<<"After sorting: "<<endl;
         for(int i=0;i<n;i++)
                cout<<arr[i]<<" ";
        return 0;
}

/*Sample Output
Enter no of elements :5
Enter elements :10 5 15 25 20
After sorting: 
5 10 15 20 25
*/
