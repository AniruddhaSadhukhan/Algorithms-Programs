#include<iostream>
#include<climits>
using namespace std;

//Program to implement Chain Matrix Multiplication showing all steps
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
	{
		m[i][i]=0;
		cout<<"m["<<i<<"]["<<i<<"]=0"<<endl;
	}
		
		
	for(int L=2;L<n;L++)
	{
		for(int i=1;i<n-L+1;i++)
		{
			int j = i+L-1;
			m[i][j] = INT_MAX;
			cout<<"\nm["<<i<<"]["<<j<<"]= min {"<<endl;
			for(int k=i;k<=j-1;k++)
			{
				int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				cout<<"\tm["<<i<<"]["<<k<<"] + m["<<k+1<<"]["<<j<<"] + p["<<i-1<<"].p["<<k<<"].p["<<j<<"] = ";
				cout<<m[i][k]<<" + "<<m[k+1][j]<<" + "<<p[i-1]<<" * "<<p[k]<<" * "<<p[j];
				cout<<" = "<<q<<endl;
				if(q < m[i][j])
				{
					m[i][j] = q;
					bracket[i][j] = k;
				}
			}
			cout<<"\t     }\n\t= "<<m[i][j]<<endl;
		}
	}
	
	cout<<"\n\nTable m : \n\n";
	for(int i=1;i<n;i++)
		cout<<"    "<<i<<"  ";
	cout<<endl;
	for(int i=1;i<n;i++)
		cout<<"--------";
	for(int i=1;i<n;i++)
	{
		cout<<endl<<i<<" | ";
		for(int j=1;j<n;j++)
		{
			if(i>j)
				cout<<"\t";
			else
				cout<<m[i][j]<<"\t";
		}
	}
	
	cout<<"\n\nTable s : \n\n    ";
	for(int i=1;i<n;i++)
		cout<<""<<i<<"\t";
	cout<<endl;
	for(int i=1;i<n;i++)
		cout<<"--------";
	for(int i=1;i<n;i++)
	{
		cout<<endl<<i<<" | ";
		for(int j=1;j<n;j++)
		{
			if(i>=j)
				cout<<"\t";
			else
				cout<<bracket[i][j]<<"\t";
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
m[1][1]=0
m[2][2]=0
m[3][3]=0
m[4][4]=0

m[1][2]= min {
	m[1][1] + m[2][2] + p[0].p[1].p[2] = 0 + 0 + 40 * 20 * 30 = 24000
	     }
	= 24000

m[2][3]= min {
	m[2][2] + m[3][3] + p[1].p[2].p[3] = 0 + 0 + 20 * 30 * 10 = 6000
	     }
	= 6000

m[3][4]= min {
	m[3][3] + m[4][4] + p[2].p[3].p[4] = 0 + 0 + 30 * 10 * 30 = 9000
	     }
	= 9000

m[1][3]= min {
	m[1][1] + m[2][3] + p[0].p[1].p[3] = 0 + 6000 + 40 * 20 * 10 = 14000
	m[1][2] + m[3][3] + p[0].p[2].p[3] = 24000 + 0 + 40 * 30 * 10 = 36000
	     }
	= 14000

m[2][4]= min {
	m[2][2] + m[3][4] + p[1].p[2].p[4] = 0 + 9000 + 20 * 30 * 30 = 27000
	m[2][3] + m[4][4] + p[1].p[3].p[4] = 6000 + 0 + 20 * 10 * 30 = 12000
	     }
	= 12000

m[1][4]= min {
	m[1][1] + m[2][4] + p[0].p[1].p[4] = 0 + 12000 + 40 * 20 * 30 = 36000
	m[1][2] + m[3][4] + p[0].p[2].p[4] = 24000 + 9000 + 40 * 30 * 30 = 69000
	m[1][3] + m[4][4] + p[0].p[3].p[4] = 14000 + 0 + 40 * 10 * 30 = 26000
	     }
	= 26000


Table m : 

    1      2      3      4  
--------------------------------
1 | 0	24000	14000	26000	
2 | 	0	6000	12000	
3 | 		0	9000	
4 | 			0	

Table s : 

    1	2	3	4	
--------------------------------
1 | 	1	1	3	
2 | 		2	3	
3 | 			3	
4 | 				


Optimal Solution : ((A(BC))D)
Optimal Cost     : 26000

*/
