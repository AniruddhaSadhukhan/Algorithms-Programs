#include<iostream>
#include<climits>
using namespace std;

//Program to impliment Prim's algorithm to find minimum spanning tree
//		by Aniruddha

void printMST(int *parent,int v,int **W)
{
	int sum = 0 ;
	cout<<"\n\nMinimum Spanning Tree : \nEdge \t\tWeight\n";
	for(int i = 2;i<=v;i++)	
	{
		cout<<parent[i]<<" - "<<i<<"\t\t"<<W[parent[i]][i]<<endl ;
		sum+=W[parent[i]][i];
	}
	cout<<endl<<"Total weight of MST : "<<sum<<endl;	
}

void primMST(int **W,int v)
{
	int parent[v+1];	//array to store constructed MST
	int key[v+1];		//key value used to pick minimum weight edge in cut
	bool visited[v+1] = {0};	
	
	for(int i = 2;i<=v;i++) key[i] = INT_MAX;
	
	//Always include first vertex in MST
	key[1] = 0;	//so that it is picked at first
	parent[1] = -1;	//1st vertex has no parent
	
	cout<<"\nExecution Order : \n";
	//MST will have V vertex
	for(int n = 1;n<=v;n++)
	{
		//pick unvisited vertex with min key
		int min=INT_MAX,u;
		for(int i = 1;i<=v;i++) 
			if(visited[i] == false && key[i]<min)
				min = key[i] , u = i;
		
		
		//mark picked vertex as visited 
		visited[u] = true;
		
		//printing execution
		cout<<parent[u]<<" - "<<u<<endl;
		
		//Update key value and parent index of adjacent vertices 
		//of visited vertex considering only the unvisited vertices
		for(int i = 1;i<=v;i++)
			// W[u][i] is non zero only for adjacent vertices of u
			//Update only if key[i] is smaller than W[u][i]
			if(visited[i] == false && W[u][i] && W[u][i]<key[i])
				key[i] = W[u][i] , parent[i] = u;
	}
	
	//printing MST
	printMST(parent,v,W);
}

int main()
{	
	int v,e;			
	cout<<"Enter number of vertices : ";
	cin>>v;
	cout<<"Enter number of edges    : ";
	cin>>e;	
	
	int **W = new int*[v+1];
	for(int i = 1;i<=v;i++)	W[i] = new int[v+1];
	
	int x,y,w;
	cout<<"Enter two vertices and weight of edges between them : \n";
	for(int i = 0;i<e;i++)
	{
		cin>>x>>y>>w;
		W[x][y]=w;W[y][x]=w;
	}
	cout<<"\nAdjacency matrix:\n";
	for(int i = 1;i<=v;i++)
	{
		for(int j = 1;j<=v;j++)
			(W[i][j]==0)?cout<<"-\t":cout<<W[i][j]<<"\t";
		cout<<endl;
	}
	
	primMST(W,v);
	
	for(int i = 1;i<=v;i++)	delete [] W[i];
	delete [] W;
}
/*Sample Input1:
8
13
1 2 5
1 4 6
1 7 7
1 5 4
2 3 2
2 4 4
2 6 5
3 4 1
4 6 7
5 8 3
6 7 4
6 8 6
7 8 2
*/

/*Sample Input2:
6
10
1 2 14
1 6 18
1 5 17
2 6 11
2 4 6
2 3 5
3 4 10
4 6 13
4 5 16
5 6 30
*/
/*Sample Output
Enter number of vertices : 6
Enter number of edges    : 10
Enter two vertices and weight of edges between them : 
1 2 14
1 6 18
1 5 17
2 6 11
2 4 6
2 3 5
3 4 10
4 6 13
4 5 16
5 6 30

Adjacency matrix:
-	14	-	-	17	18	
14	-	5	6	-	11	
-	5	-	10	-	-	
-	6	10	-	16	13	
17	-	-	16	-	30	
18	11	-	13	30	-	

Execution Order : 
-1 - 1
1 - 2
2 - 3
2 - 4
2 - 6
4 - 5


Minimum Spanning Tree : 
Edge 		Weight
1 - 2		14
2 - 3		5
2 - 4		6
4 - 5		16
2 - 6		11

Total weight of MST : 52

*/
