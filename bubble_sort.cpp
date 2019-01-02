#include<iostream>
using namespace std;

//Program to implement Bubble Sort
//		by Aniruddha

void bubbleSort(int *a,int n)
{
        bool sorted = false;
        int last = n-1;

        for(int i=0;(i<last) && !sorted ;i++)
        {
                sorted = true;
                for(int j=last;j>i;j--)
                        if(a[j-1]>a[j])
                        {
                                a[j-1]=a[j-1]+a[j]-(a[j]=a[j-1]);
                                sorted = false;
                        }
        }

}

int main()
{
        int n;
        cout<<"Enter no of elements :";
        cin>>n;
        int *arr=new int[n];
        cout<<"Enter elements :";
        for(int i=0;i<n;i++)
                cin>>arr[i];
        bubbleSort(arr,n);
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
