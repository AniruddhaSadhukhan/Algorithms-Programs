#include<iostream>
#include<limits.h>
using namespace std;

//Program for Bellman Ford single source shortest path algorithm
//		by Aniruddha

struct Edge
{
	int src,dest,wt;
};

struct Graph
{
	int V,E;
	Edge *edge;
};

Graph* createGraph(int v,int e)
{
	Graph *graph = new Graph;
	graph->V = v;
	graph->E = e;
	graph->edge = new Edge[e];
	return graph;
}

void BellmanFord(Graph* graph,int src)
{
	int *dist = new int[graph->V + 1];
	
	//Step 1: Initialise distances from src to all other vertices as Infinite
	for(int i=1; i <= graph->V ; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;
	
	
	//This block is for showing steps
	{
		cout<<"No.\t  ";
		for(int i=1; i <= graph->V ; i++)
			cout<<i<<"\t  ";
		cout<<endl;
		for(int i=0; i <= graph->V ; i++)
			cout<<"--------";
		cout<<endl;
		cout<<"Initial\t| ";
		for(int i=1;i <= graph->V ; i++)
				(dist[i]==INT_MAX)?cout<<"\xe2\x88\x9e\t":cout<<dist[i]<<"\t";
			cout<<endl;
	}	
		
		
	//Step 2: Do V-1 times : for each edge u-v : dist[v] = min(dist[v],dist[u]+weight of u-v)
	for(int n=1;n<graph->V;n++)
	{
		for(int i=0;i<graph->E;i++)
		{
			int u,v,w;
			u= graph->edge[i].src;
			v= graph->edge[i].dest;
			w= graph->edge[i].wt;
			/*adding positive integer to INT_MAX will cause 
			overflow,wrap around and thus make it negative*/
			if(dist[u] != INT_MAX)	
				dist[v]=min(dist[v],dist[u]+w); 
		}
		
		
		
		//This block is for showing steps
		{
			cout<<n<<"\t| ";
			for(int i=1;i <= graph->V ; i++)
				(dist[i]==INT_MAX)?cout<<"\xe2\x88\x9e\t":cout<<dist[i]<<"\t";
			cout<<endl;
		}
		
		
	}
	
	//Step 3: for each edge u-v :if dist[v] > dist[u]+weight of u-v then Graph has negative edge
	for(int i=0;i<graph->E;i++)
		if(dist[graph->edge[i].dest] > (dist[graph->edge[i].src]+graph->edge[i].wt))
		{
			cout<<"Graph has Negative Weight Cycle";
			break;
		}
		
	delete [] dist;	 
}

int main()
{	
	int v,e,s;	
			
	cout<<"Total Vertices : ";
	cin>>v;
	cout<<"Total Edges    : ";
	cin>>e;
	
	Graph *graph = createGraph(v,e);
	
	cout<<"Enter source,destination and weight of "<<e<<" edges : "<<endl;
	
	for(int i = 0;i<e;i++)
		cin>>graph->edge[i].src>> graph->edge[i].dest>>graph->edge[i].wt;
	
	cout<<"Enter Source   : ";
	cin>>s;
	
	cout<<endl;
	
	BellmanFord(graph,s);
	
	return 0;
}

//Sample input :  5 10 2 3 5 2 4 8 2 5 -4 3 2 -2 4 3 -3 4 5 9 5 3 7 5 1 2 1 2 6 1 4 7 1
/*Sample Output
Total Vertices : 5
Total Edges    : 10
Enter source,destination and weight of 10 edges : 
2 3 5
2 4 8
2 5 -4
3 2 -2
4 3 -3
4 5 9
5 3 7
5 1 2
1 2 6
1 4 7
Enter Source   : 1

No.	  1	  2	  3	  4	  5	  
------------------------------------------------
Initial	| 0	∞	∞	∞	∞	
1	| 0	6	∞	7	∞	
2	| 0	6	4	7	2	
3	| 0	2	4	7	2	
4	| 0	2	4	7	-2	
*/
