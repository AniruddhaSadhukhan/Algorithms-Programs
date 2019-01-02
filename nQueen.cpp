#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

//Program to implement n-Queen's problem by backtracking
//		by Aniruddha

int n;
vector<int> x;

void print()
{
	static int c = 1;
	cout<<"\n\nSolution "<<c<<" : ";
	for(int i=1;i<=n;i++) cout<<x[i]<<" ";
	cout<<"\n\n";
	for(int i=1;i<=n;i++) cout<<"\t"<<i;
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<i<<"\t";
		for(int j=1;j<=n;j++)
			(x[i]==j)?cout<<"Q\t":cout<<"-\t";
		cout<<endl;
	}
	c++;
}

bool place(int k,int i)
{
	//returns true if Q is placed at k-th row and i-th column
	for(int j = 1;j<k;j++)	//check previous k-1 queens that are already placed
	{
		//(x[j]==i) : if in same column
		//x[j] : column of j-th Q
		//i : column of current k-th Q
		//j : row of j-th Q
		//k : row of current k-th Q
		//abs(x[j]-i)==abs(j-k) : if in same diagonal
		if((x[j]==i)||abs(x[j]-i)==abs(j-k))
			return false;
	}
	return true;
}

void nQueens(int k=1)
{
	//n=no. of queen
	//k=queen under consideration
	//using backtracking it finds all possible solution
	for (int i=1;i<=n;i++)	//for k-th queen,try all columns
	{
		if(place(k,i))	//if k-th queen can be placed in i-th column and k-th row
		{
			x[k] = i;	//save the column position for k-th queen
			if(k == n) print();	//if it is the last queen,print the solution
			
			else nQueens(k+1);	//if more queen left,check for next queen
		}
	}
}

int main()
{	
		
	cout<<"Enter N : ";
	cin>>n;
	
	x.resize(n+1);		//x[1...n] stores the n tuple solution
	
	nQueens();	
}

/*Sample Output
Enter N : 4


Solution 1 : 2 4 1 3 

	1	2	3	4
1	-	Q	-	-	
2	-	-	-	Q	
3	Q	-	-	-	
4	-	-	Q	-	


Solution 2 : 3 1 4 2 

	1	2	3	4
1	-	-	Q	-	
2	Q	-	-	-	
3	-	-	-	Q	
4	-	Q	-	-	
*/
