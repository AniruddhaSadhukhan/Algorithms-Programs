#include<iostream>
using namespace std;

//Program to implement Selection Sort
//		by Aniruddha


void selectionSort(int *a,int n)
{
        for(int i = 0;i<n-1;i++)
        {
                int min = i;
                for(int j=i+1;j<n;j++)
                        if(a[j] < a[min])
                                min = j;
                //swap
                a[min]=a[min]+a[i]-(a[i]=a[min]);
        }
}

int main()
{
        int n,min,max;
        cout<<"Enter no of elements :";
        cin>>n;
        int arr[n];
        cout<<"Enter elements :";
        for(int i=0;i<n;i++)
                cin>>arr[i];
        selectionSort(arr,n);
        cout<<"After sorting: ";
         for(int i=0;i<n;i++)
                cout<<arr[i]<<" ";
        return 0;
}

/*Sample Output
Enter no of elements :5
Enter elements :10 5 15 25 20
After sorting: 5 10 15 20 25
*/
