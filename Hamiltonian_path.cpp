#include<iostream>
#include<vector>
using namespace std;

//Program to implement Hamiltonian Cycle problem by backtracking
//		by Aniruddha

typedef vector< vector<bool> > Matrix;	//boolean Matrix

Matrix G;
int n;
vector<int> x;

void NextValue(int k)
{
	//x[1:k-1] is a path of k-1 distinct vertices
	//x[k] is assigned 0 to n 
	//0 suggests no valid vertex
	//1 to n suggests the next vertex to be visited
	while(true)
	{
		//at first x[k]=0,for n=4,x[k] becomes (0+1)%5=1,
		//then 2,3,4,and then (5%5)=0 when the function will return
		x[k] = (x[k] + 1)%(n+1);
		
		if(x[k]==0) return;
		
		if(G[x[k-1]][x[k]])	//if an edge exists between x[k-1] and x[k]
		{
			int j;
			for(j=1;j<k;j++)
				if(x[k]==x[j])	break;	//if x[k] is already in x[1:k-1],stop

			if(j==k) //if the loop completes without break
				//if k is last node,then there should be a path between last and first node
				if(k<n || (k==n && G[x[n]][x[1]])) return;		
					
		}
		
		
		
		
		
	}
}

void Hamiltonian(int k=2)
{
	//k = index of Hamiltonian cycle
	while(true)
	{
		NextValue(k);	//provide a legal node for x[k]
		
		if(x[k]==0)	//if no valid node can be provided
			return;
		
		if(k==n)	//x array has been completely filled up with the Hamiltonian cycle nodes
		{
			for(int i=1;i<=n;i++) cout<<x[i]<<"-";cout<<x[1]<<endl;	//print solution
		}
		
		else Hamiltonian(k+1);	//go for next 
	}
}

int main()
{	
	int e,a,b;	
			
	cout<<"Enter number of vertices : ";
	cin>>n;
	cout<<"Enter number of edges    : ";
	cin>>e;
	cout<<"Enter the edges  : \n";
	
	G.resize(n+1,vector<bool>(n+1));	//boolean adjacency matrix n x n
	
	x.resize(n+1);		//store the result,having n location containing path through n locations 
	
	x[1]=1;	//start with 1st node
	
	for(int i=1;i<=e;i++)
	{
		cin>>a>>b;
		G[a][b]=G[b][a]=true;
	}

	cout<<"\nFollowing are Hamiltonian cycles  : \n";
	Hamiltonian();	
}
/*Sample Input
8
11
1 2
2 3
3 4
4 5
5 6
6 7
7 8
1 7
8 2
1 3
3 6

*/
/*Graph:
	  ___________
	 |           |
	(1)---(2)---(3)---(4)
	  \   /	     |     |
	   \ /       |     |
	    X        |     |
	   / \       |     |
	  /   \      |     |
	(8)---(7)---(6)---(5)
	
*/
/*Sample Output
Enter number of vertices : 8
Enter number of edges    : 11
Enter the edges  : 
1 2
2 3
3 4
4 5
5 6
6 7
7 8
1 7
8 2
1 3
3 6

Following are Hamiltonian cycles  : 
1-2-8-7-6-5-4-3-1
1-3-4-5-6-7-8-2-1
*/
