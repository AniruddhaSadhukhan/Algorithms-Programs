#include<iostream>
#include<vector>
using namespace std;

//Program to implement m-Graph Colouring problem by backtracking
//		by Aniruddha

typedef vector< vector<bool> > Matrix;	//boolean Matrix

Matrix G;
int n,m;
vector<int> x;

void NextValue(int k)
{
	//k-1 nodes have been assigned colours
	//x[k] is assigned 0 to m 
	//0 suggests no valid colour
	//1 to m suggests valid colour
	while(true)
	{
		//at first x[k]=0,for m=4,x[k] becomes (0+1)%5=1,
		//then 2,3,4,and then (5%5)=0 when the function will return
		x[k] = (x[k] + 1)%(m+1);
		if(x[k]==0) return;
		int j;
		for(j=1;j<=n;j++)
		{
			//if there exists a edge between k and j 
			//and has both same colour, it will stop 
			//and try again for other colour
			if(G[k][j] && x[k]==x[j])	
				break;
		}
		if(j==n+1) return;	//if the loop completes without break,required colour is found
	}
}

void mColouring(int k=1)
{
	//k = index of next vertex to colour
	while(true)
	{
		NextValue(k);	//provide colour for k-th node
		
		if(x[k]==0)	//if no valid colour can be provided
			return;
		
		if(k==n)	//x array has been completely filled up with respecive colour
		{
			for(int i=1;i<=n;i++) cout<<x[i]<<" ";cout<<endl;	//print solution
		}
		
		else mColouring(k+1);	//go for next node
		
	}
}

int main()
{	
	int e,a,b;	
			
	cout<<"Enter number of vertices : ";
	cin>>n;
	cout<<"Enter m                  : ";
	cin>>m;
	cout<<"Enter number of edges    : ";
	cin>>e;
	cout<<"Enter the edges  : \n";
	
	G.resize(n+1,vector<bool>(n+1));	//boolean adjacency matrix n x n
	
	x.resize(n+1);		//store the result,having n location containing the colour value of n locations 
	
	for(int i=1;i<=e;i++)
	{
		cin>>a>>b;
		G[a][b]=G[b][a]=true;
	}

	cout<<"\nFollowing are the assigned colours  : \n";
	mColouring();	
}
/*Sample Input
5
3
7
1 3
1 5
1 2
3 5
3 2
2 4
4 5
*/
/*Graph:
	(3)
        /|\
       / | \
      /  |  \
    (1)--|--(5)
      \  |  /
       \ |(4)
        \|/
        (2)   

*/
/*Sample Output
Enter number of vertices : 5
Enter m                  : 3
Enter number of edges    : 7
Enter the edges  : 
1 3
1 5
1 2
3 5
3 2
2 4
4 5

Following are the assigned colours  : 
1 2 3 1 2 
1 2 3 3 2 
1 3 2 1 3 
1 3 2 2 3 
2 1 3 2 1 
2 1 3 3 1 
2 3 1 1 3 
2 3 1 2 3 
3 1 2 2 1 
3 1 2 3 1 
3 2 1 1 2 
3 2 1 3 2 

*/
