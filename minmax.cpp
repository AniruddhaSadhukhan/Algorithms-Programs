#include<iostream>
using namespace std;

//Program to find min and max using divide and conquer
//		by Aniruddha


void minmax(int *arr,int i,int j,int* min,int* max)
{
        int lmin,rmin,lmax,rmax,mid;

        if(i==j)
        {
                *min=arr[i];
                *max=arr[j];
        }

        else if(j==i+1)
        {
                if (arr[i]>arr[j])
                {
                        *min=arr[j];
                        *max=arr[i];
                }
               else
                {
                        *min=arr[i];
                        *max=arr[j];
                }
        }

        else
        {
                mid = (i+j)/2;
                minmax(arr,i,mid,&lmin,&lmax);
                minmax(arr,mid+1,j,&rmin,&rmax);
                *min=(lmin<rmin)?lmin:rmin;
                *max=(lmax>rmax)?lmax:rmax;
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
        minmax(arr,0,n-1,&min,&max);
        cout<<"Min = "<<min<<"\nMax= "<<max<<endl;
        return 0;
}

/*Sample Output
Enter no of elements :10
Enter elements :564 65 152 54 498 35 16 258 57 47 
Min = 16
Max= 564
*/

