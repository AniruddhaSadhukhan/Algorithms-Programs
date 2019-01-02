#include<iostream>
#include<climits>
using namespace std;

//Program to implement Chain Matrix Multiplication
//		by Aniruddha


void optimalSolution(int i,int j,int n,int *bracket,char &name)
{
	if(i==j)
	{
		cout<<name++;
		return;
	}
	
	cout<<"(";
	
	optimalSolution(i,*((bracket+i*n)+j),n,bracket,name);
	optimalSolution(*((bracket+i*n)+j)+1,j,n,bracket,name);
	
	cout<<")";
}


void chainMatrixMultiplication(int *p,int n)
{
	int m[n][n];
	int bracket[n][n];
	
	for(int i=1;i<n;i++)
		m[i][i]=0;	
		
	for(int L=2;L<n;L++)
	{
		for(int i=1;i<n-L+1;i++)
		{
			int j = i+L-1;
			m[i][j] = INT_MAX;
	
			for(int k=i;k<=j-1;k++)
			{
				int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				
				if(q < m[i][j])
				{
					m[i][j] = q;
					bracket[i][j] = k;
				}
			}
		}
	}
	
	char name = 'A';
	cout<<"\n\n\nOptimal Solution : ";
	optimalSolution(1,n-1,n,(int*)bracket,name);
	cout<<"\nOptimal Cost     : "<<m[1][n-1]<<endl;
}


int main()
{	
	
	int a;	
			
	cout<<"Enter number of arrays :";
	cin>>a;
	
	int *arr = new int[a+1];
	char c = 'A';
	int n=0;
	
	cout<<"Enter dimentions of array :"<<endl;
	for(int i=0;i<a;i++)
	{
		cout<<"Matrix "<<c++<<" : "<<endl;
		if(i==0)
		{
			cout<<"\tRows    :";
			cin>>arr[n++];
		}
		else
			cout<<"\tRows    :"<<arr[n-1]<<endl;
		cout<<"\tColumns :";
		cin>>arr[n++];
	}
	
	//int arr[] = {40, 20, 30, 10, 30},n=sizeof (arr)/sizeof (arr[0]);
	
	chainMatrixMultiplication(arr,n);
	
	return 0;	
}

/*Sample Output
Enter number of arrays :4
Enter dimentions of array :
Matrix A : 
	Rows    :40
	Columns :20
Matrix B : 
	Rows    :20
	Columns :30
Matrix C : 
	Rows    :30
	Columns :10
Matrix D : 
	Rows    :10
	Columns :30


Optimal Solution : ((A(BC))D)
Optimal Cost     : 26000

*/
