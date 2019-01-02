#include<iostream>
#include<limits.h>
#define INF INT_MAX
using namespace std;

//Program for Dijkstra's single source shortest path algorithm
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

void Print(int v,bool visited[],int dist[],int prev[])
{
	cout<<endl<<"Vertices  |\t";
	for(int i = 1;i<=v;i++) cout<<i<<"\t";
	cout<<endl;
	for(int i = 0;i<=v+1;i++) cout<<"--------";
	cout<<endl<<"Visited   |\t";
	for(int i = 1;i<=v;i++) cout<<visited[i]<<"\t";
	cout<<endl<<"Distance  |\t";
	for(int i = 1;i<=v;i++) (dist[i]==INF)?cout<<"\xe2\x88\x9e\t":cout<<dist[i]<<"\t";
	cout<<endl<<"Previous  |\t";
	for(int i = 1;i<=v;i++) cout<<prev[i]<<"\t";
	cout<<endl;	
		
}

void Dijkstra(Graph* graph,int v,int s)
{
	
	int dist[v+1],prev[v+1];
	bool visited[v+1]={0};
	
	fill(prev,prev+v+1,s);
	fill(dist,dist+v+1,INF);
	
	visited[s] = 1;
	dist[s] = 0;
	prev[s] = 0;
	
	for(int i = 0;i<graph->E;i++)
	{
		if(graph->edge[i].src == s)
			dist[graph->edge[i].dest] = graph->edge[i].wt;	
	}
	
	Print(v,visited,dist,prev);
	
	for(int z = 2;z<=v;z++)
	{
		int min=INF,u;
		for(int i=1;i<=v;i++)
			if(visited[i]==0 && dist[i]<min)
			{
				min = dist[i];
				u = i;
			}
		visited[u]=1;
		
		
		for(int i = 0;i<graph->E;i++)
			if(graph->edge[i].src == u && visited[graph->edge[i].dest]==0)
			{
				int v=graph->edge[i].dest,w=graph->edge[i].wt;
				if(dist[v]>dist[u]+w)
				{
					dist[v]=dist[u]+w;
					prev[v] = u;
				}			 
			}
			
		Print(v,visited,dist,prev);
	}	
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
	
	Dijkstra(graph,v,s);
	
	return 0;
}

/*Sample input :  
7 24
1 2 3
2 1 3
1 3 6
3 1 6
2 4 4
4 2 4
2 3 2
3 2 2
3 4 1
4 3 1
4 5 2
5 4 2
3 5 4
5 3 4
4 7 4
7 4 4
5 7 1
7 5 1
6 7 1
7 6 1
5 6 2
6 5 2
6 3 2
3 6 2
1
*/
/*Sample Output
Total Vertices : 7
Total Edges    : 24
Enter source,destination and weight of 24 edges : 
1 2 3
2 1 3
1 3 6
3 1 6
2 4 4
4 2 4
2 3 2
3 2 2
3 4 1
4 3 1
4 5 2
5 4 2
3 5 4
5 3 4
4 7 4
7 4 4
5 7 1
7 5 1
6 7 1
7 6 1
5 6 2
6 5 2
6 3 2
3 6 2
Enter Source   : 1


Vertices  |	1	2	3	4	5	6	7	
------------------------------------------------------------------------
Visited   |	1	0	0	0	0	0	0	
Distance  |	0	3	6	∞	∞	∞	∞	
Previous  |	0	1	1	1	1	1	1	

Vertices  |	1	2	3	4	5	6	7	
------------------------------------------------------------------------
Visited   |	1	1	0	0	0	0	0	
Distance  |	0	3	5	7	∞	∞	∞	
Previous  |	0	1	2	2	1	1	1	

Vertices  |	1	2	3	4	5	6	7	
------------------------------------------------------------------------
Visited   |	1	1	1	0	0	0	0	
Distance  |	0	3	5	6	9	7	∞	
Previous  |	0	1	2	3	3	3	1	

Vertices  |	1	2	3	4	5	6	7	
------------------------------------------------------------------------
Visited   |	1	1	1	1	0	0	0	
Distance  |	0	3	5	6	8	7	10	
Previous  |	0	1	2	3	4	3	4	

Vertices  |	1	2	3	4	5	6	7	
------------------------------------------------------------------------
Visited   |	1	1	1	1	0	1	0	
Distance  |	0	3	5	6	8	7	8	
Previous  |	0	1	2	3	4	3	6	

Vertices  |	1	2	3	4	5	6	7	
------------------------------------------------------------------------
Visited   |	1	1	1	1	1	1	0	
Distance  |	0	3	5	6	8	7	8	
Previous  |	0	1	2	3	4	3	6	

Vertices  |	1	2	3	4	5	6	7	
------------------------------------------------------------------------
Visited   |	1	1	1	1	1	1	1	
Distance  |	0	3	5	6	8	7	8	
Previous  |	0	1	2	3	4	3	6	

*/
