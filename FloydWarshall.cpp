#include<iostream>
#include<limits.h>
using namespace std;

//Program for Floyd Warshall all pairs shortest path algorithm
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

void FloydWarshall(Graph* graph,int v)
{
	int M[v+1][v+1];
	
	for(int i=1;i<=v;i++)
		for(int j=1;j<=v;j++)
			(i==j)?M[i][j] = 0 :M[i][j] = INT_MAX;
			
	for(int i=0;i<graph->E;i++)
		M[graph->edge[i].src][graph->edge[i].dest] = graph->edge[i].wt ;
	
	//This block is for printing steps 
	{
		cout<<"Initially : \n";
		for(int i=1;i<=v;i++)
		{
			for(int j=1;j<=v;j++)
				(M[i][j]==INT_MAX)?cout<<"\xe2\x88\x9e\t":cout<<M[i][j]<<"\t";
			cout<<endl;	
		}
		cout<<endl;
	}	
		
	for(int k=1;k<=v;k++)
	{
		for(int i=1;i<=v;i++)
			for(int j=1;j<=v;j++)
				if(M[i][k]!=INT_MAX && M[k][j]!=INT_MAX && i!=k && j!=k)
					M[i][j] = min(M[i][j] , (M[i][k]+M[k][j]));
			
		
		
		//This block is for printing steps 
		{
			cout<<"After itteration "<<k<<" : \n";
			for(int i=1;i<=v;i++)
			{
				for(int j=1;j<=v;j++)
					(M[i][j]==INT_MAX)?cout<<"\xe2\x88\x9e\t":cout<<M[i][j]<<"\t";
				cout<<endl;	
			}
			cout<<endl;
		}
	}
	
}

int main()
{	
	int v,e;	
			
	cout<<"Total Vertices : ";
	cin>>v;
	cout<<"Total Edges    : ";
	cin>>e;
	
	Graph *graph = createGraph(v,e);
	
	cout<<"Enter source,destination and weight of "<<e<<" edges : "<<endl;
	
	for(int i = 0;i<e;i++)
		cin>>graph->edge[i].src>> graph->edge[i].dest>>graph->edge[i].wt;
	
	cout<<endl;
	
	FloydWarshall(graph,v);
	
	return 0;
}

/*Sample input :  
5 9
1 2 3
1 3 8
1 5 -4 
2 5 7
2 4 1
3 2 4
4 3 5 
4 1 2
5 4 6
*/

/*Sample Output
Total Vertices : 5
Total Edges    : 9
Enter source,destination and weight of 9 edges : 
1 2 3
1 3 8
1 5 -4 
2 5 7
2 4 1
3 2 4
4 3 5 
4 1 2
5 4 6

Initially : 
0	3	8	∞	-4	
∞	0	∞	1	7	
∞	4	0	∞	∞	
2	∞	5	0	∞	
∞	∞	∞	6	0	

After itteration 1 : 
0	3	8	∞	-4	
∞	0	∞	1	7	
∞	4	0	∞	∞	
2	5	5	0	-2	
∞	∞	∞	6	0	

After itteration 2 : 
0	3	8	4	-4	
∞	0	∞	1	7	
∞	4	0	5	11	
2	5	5	0	-2	
∞	∞	∞	6	0	

After itteration 3 : 
0	3	8	4	-4	
∞	0	∞	1	7	
∞	4	0	5	11	
2	5	5	0	-2	
∞	∞	∞	6	0	

After itteration 4 : 
0	3	8	4	-4	
3	0	6	1	-1	
7	4	0	5	3	
2	5	5	0	-2	
8	11	11	6	0	

After itteration 5 : 
0	3	7	2	-4	
3	0	6	1	-1	
7	4	0	5	3	
2	5	5	0	-2	
8	11	11	6	0	


*/
