#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define N 4
//Program to implement 15 puzzle problem
//		by Aniruddha

//Target configuration
int final[N][N]=
	{
		{1 ,2 ,3 ,4 },
		{5 ,6 ,7 ,8 },
		{9 ,10,11,12},
		{13,14,15,0 }
	};

	
class Puzzle
{
	int puzzle[N][N];	//store initial puzzle
	int r,c;	//store initial coordinate of blank
	
	void findBlank()	// find Position of blank
	{
		
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
		    		if (puzzle[i][j] == 0)
		    			r=i , c=j;
	}

	
	struct Node
	{
		// stores parent node of current node
		// helps in tracing path when answer is found
		Node* parent;

		// stores matrix
		int mat[N][N];

		// stores blank tile cordinates
		int x, y;

		// stores the number of misplaced tiles
		int cost;

		// stores the number of moves so far
		int level;
	};


	
	// Function to allocate a new node
	Node* newNode(int mat[N][N],int x,int y,int newX,int newY,int level,Node* parent)
	{
		Node* node = new Node;

		// set pointer for path to root
		node->parent = parent;

		// copy data from parent node to current node
		memcpy(node->mat, mat, sizeof node->mat);

		// move tile by 1 postion
		swap(node->mat[x][y], node->mat[newX][newY]);

		// set number of misplaced tiles
		node->cost = 9999;

		// set number of moves so far
		node->level = level;

		// update new blank tile cordinates
		node->x = newX;
		node->y = newY;

		return node;
	}

	

	// A utility function to count inversions in given
	// array 'arr[]'
	int getInvCount(int arr[])
	{
		int inv_count = 0;
		for (int i = 0; i < N * N - 1; i++)
			for (int j = i + 1; j < N * N; j++)
				// count pairs(i, j) such that i appears
				// before j, but i > j.
				if (arr[j] && arr[i] && arr[i] > arr[j])
					inv_count++;
		return inv_count;
	}
	


	// Function to calculate the the number of misplaced tiles
	// ie. number of non-blank tiles not in their goal position
	int calculateCost(int initial[N][N])
	{
		int count = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (initial[i][j] && initial[i][j] != final[i][j])
		   			count++;
		return count;
	}


	// Function to check if (x, y) is a valid matrix cordinate
	int isSafe(int x, int y)
	{
		return (x >= 0 && x < N && y >= 0 && y < N);
	}


	// Comparison object to be used to order the heap
	struct comp
	{
		bool operator()(const Node* lhs, const Node* rhs) const
		{
			return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);
		}
	};

	
	// Function to print N x N matrix
	int printMatrix(int mat[N][N])
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			    cout<<mat[i][j]<<"\t";
			cout<<endl;
		}
	}
	
	// print path from root node to destination node
	void printPath(Node* root)
	{
		if (root == NULL)
			return;
		printPath(root->parent);
		printMatrix(root->mat);
		cout<<endl;
	}

public:

	void input()
	{
		cout<<"Enter initial state,0 for blank : \n";
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				cin>>puzzle[i][j];
	}
	
	
	// This function returns true if given
	// instance of N*N - 1 puzzle is solvable
	bool isSolvable()
	{
		findBlank();
		// Count inversions in given puzzle
		int invCount = getInvCount((int*)puzzle);
	
		// If grid is odd, return true if inversion
	    	// count is even.
	    	if (N & 1)
			return !(invCount & 1);
	 
		//If grid is even,return true if
		//Blank is in even row counting from the bottom & inv_count is odd.
		//Blank is in odd row counting from the bottom & inv_count is even.
		else    
		{
			if ((N-r) & 1)	
				return !(invCount & 1);
			else			
				return invCount & 1;	
		}
	}



	// Function to solve N*N - 1 puzzle algorithm using
	// Branch and Bound. x and y are blank tile coordinates
	// in initial state
	void solve()
	{
		//position change when blank is moved
		// botton, left, top, right
		int row[] = { 1, 0, -1, 0 };
		int col[] = { 0, -1, 0, 1 };
		
		// Create a priority queue to store live nodes of
		// search tree;
		priority_queue<Node*, std::vector<Node*>, comp> pq;

		// create a root node and calculate its cost
		Node* root = newNode(puzzle, r, c, r, c, 0, NULL);
		root->cost = calculateCost(puzzle);

		// Add root to list of live nodes;
		pq.push(root);

		// Finds a live node with least cost,
		// add its childrens to list of live nodes and
		// finally deletes it from the list.
		while (!pq.empty())
		{
			// Find a live node with least estimated cost
			Node* min = pq.top();

			// The found node is deleted from the list of
			// live nodes
			pq.pop();

			// if min is an answer node
			if (min->cost == 0)
			{
				// print the path from root to destination;
				printPath(min);
				return;
			}

			// do for each child of min
			// max 4 children for a node
			for (int i = 0; i < 4; i++)
			{
				if (isSafe(min->x + row[i], min->y + col[i]))
				{
					// create a child node and calculate
					// its cost
					Node* child = newNode(min->mat, min->x,
					min->y, min->x + row[i],
					min->y + col[i],
					min->level + 1, min);
					child->cost = calculateCost(child->mat);

					// Add child to list of live nodes
					pq.push(child);
				}
			}
		}
	}

	
};



int main()
{	
	Puzzle p;
	
	p.input();
	if(p.isSolvable())
	{
		cout << "The solution is:\n";
		p.solve();
	} 
        else cout << "Sorry! Not Solvable\n";
        
        return 0;
	
                        
        	
}
/*Sample input:

3  9  1  15
14 11 4  6
13 0  10 12 
2  7  8  5

---------------------
1  2  3  4
5  6  0  8
9  10 7  11
13 14 15 12

*/
/*Sample Output
Enter initial state,0 for blank : 
1  2  3  4
5  6  0  8
9  10 7  11
13 14 15 12
The solution is:
1	2	3	4	
5	6	0	8	
9	10	7	11	
13	14	15	12	

1	2	3	4	
5	6	7	8	
9	10	0	11	
13	14	15	12	

1	2	3	4	
5	6	7	8	
9	10	11	0	
13	14	15	12	

1	2	3	4	
5	6	7	8	
9	10	11	12	
13	14	15	0

---------------------------------
Enter initial state,0 for blank : 
3  9  1  15
14 11 4  6
13 0  10 12 
2  7  8  5
Sorry! Not Solvable

*/
