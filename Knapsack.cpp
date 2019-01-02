#include<iostream>
#include<algorithm>	//for sort
#include<iomanip>	//for setprecision
using namespace std;

//Program to implement Knapsack Problem
//		by Aniruddha

struct Item 
{
	int profit,weight;
	double pw;	//pw = profit per unit weight
	
	bool operator< (const Item& other)
	{
		return pw > other.pw;
	}	
};

void Knapsack(Item *item,int n,int m)
{
	sort(&item[1],&item[n+1]);		
	
	int CW = 0;
	double CP = 0.0,x=1.0;
	
	
	//This block is for printing the table
	{
		cout<<"No.\tPi\tWi\tPi/Wi\tXi\tCW\tm-CW\tPiXi\n";
		for(int i=0;i<8;i++) cout<<"--------";
		cout<<endl;
	}
	
	
	for(int i = 1;i<=n;i++)
	{
		if (CW + item[i].weight <= m)
		{
			CW += item[i].weight;
			CP += item[i].profit;	
		}
		else if(m-CW)
		{
			CP += (m-CW)*item[i].pw;
			x = float(m-CW)/item[i].weight;
			CW = m;
		}
		else x=0;
		
		//This block is for printing the table
		{
			cout<<i<<"\t"<<item[i].profit<<"\t"<<item[i].weight;
			cout<<"\t"<<setprecision(4)<<item[i].pw<<"\t";
			cout<<setprecision(4)<<x<<"\t"<<CW<<"\t";
			cout<<m-CW<<"\t"<<x*item[i].profit<<endl;
		}
		
		
	}
	
	//This block is for printing the table
	{
		
		for(int i=0;i<8;i++) cout<<"--------";
		cout<<endl;
		cout<<"\t\t\tMax Profit : \t\t\t"<<CP<<endl;
	}
}


int main()
{	
	int n,m;	
			
	cout<<"Enter number of items : ";
	cin>>n;
	cout<<"Enter Knapsack Capacity : ";
	cin>>m;
	
	Item *item = new Item[n+1];
	
	cout<<"Enter profits and weights of "<<n<<" items : "<<endl;
	for(int i = 1;i<=n;i++)
	{
		cin>>item[i].profit>>item[i].weight;
		item[i].pw = (double)item[i].profit/item[i].weight;
	}
	cout<<endl;
	
	Knapsack(item,n,m);
	
	
}
/*Sample Input
8
110
21 11
11 1
65 55
55 45
43 33
33 23
53 43
31 21


*/
/*Sample Output
Enter number of items : 8
Enter Knapsack Capacity : 110
Enter profits and weights of 8 items : 
21 11
11 1
65 55
55 45
43 33
33 23
53 43
31 21

No.	Pi	Wi	Pi/Wi	Xi	CW	m-CW	PiXi
----------------------------------------------------------------
1	11	1	11	1	1	109	11
2	21	11	1.909	1	12	98	21
3	31	21	1.476	1	33	77	31
4	33	23	1.435	1	56	54	33
5	43	33	1.303	1	89	21	43
6	53	43	1.233	0.4884	110	0	25.88
7	55	45	1.222	0	110	0	0
8	65	55	1.182	0	110	0	0
----------------------------------------------------------------
			Max Profit : 			164.9

*/
