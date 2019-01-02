#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

//Program to impliment Kruskal's algorithm to find minimum spanning tree
//		by Aniruddha
typedef	pair< int,pair<int,int> > Edge;
typedef vector < pair< int,pair<int,int> > > EdgeArray;

int find(int x,int *parents)
{
	if(parents[x] == x)
		return x;
	return find(parents[x],parents);
}

void kruskalMST(Edge *edges,int V,int E)
{
	int *parents = new int[V+1];
	for(int i=0;i<=V;i++) parents[i]=i;
	
	int mst_w=0,mst_e=0;
	
	sort(edges,edges+E);
	
	cout<<"\n\nEdges and their weights in MST : \n";
	
	int u,v,w,fu,fv;
	for(int i=0;i<E && mst_e < V-1 ;i++)
	{
		u = edges[i].second.first;
		v = edges[i].second.second;
		w = edges[i].first;
		
		fu = find(u,parents);
		fv = find(v,parents);
		
		if(fu != fv)
		{
			parents[v] = u;
			mst_e++;
			mst_w += w;
			
			cout<<u<<" - "<<v<<" : "<<w<<endl;
		}
	}
	
	cout<<endl<<"Total weight of MST : "<<mst_w<<endl;	
}

int main()
{	
	int v,e;			
	cout<<"Enter number of vertices : ";
	cin>>v;
	cout<<"Enter number of edges    : ";
	cin>>e;	
	
	EdgeArray edges;
	
	int x,y,w;
	cout<<"Enter two vertices and weight of edges between them : \n";
	for(int i = 0;i<e;i++)
	{
		cin>>x>>y>>w;
		edges.push_back(make_pair(w,make_pair(x,y)));
		//edges.push_back(make_pair(w,make_pair(y,x)));//for undirected graph
	}
	
	kruskalMST(&edges[0],v,e);
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


Edges and their weights in MST : 
2 - 3 : 5
2 - 4 : 6
2 - 6 : 11
1 - 2 : 14
4 - 5 : 16

Total weight of MST : 52

*/
