#include<iostream>
#include<algorithm>	//for sort
using namespace std;

//Program to Job Sequencing with Deadline
//		by Aniruddha

struct Job 
{
	int jobID,profit,deadline;
};

bool comp(Job a,Job b)
{
	return a.profit > b.profit;
}	

void JobSequence(Job *job,int n)
{
	//sorting jobs according to profit
	sort(&job[1],&job[n+1],comp);	
	
	//calculating maximum deadline
	int md = 0;	
	for(int i=1;i<=n;i++)
		md = max(md,job[i].deadline);
	
	//Number of slots = max deadline
	int *slot = new int[md+1];
	
	//CP will hold Current Profit
	int CP  = 0;
	
	//count will keep track of how many slots are filled
	int count = 0;
	
	int i;
	
	//This line is for printing table
	cout<<"Job Considered\tProfit\tDeadline   Action\t\tCurrent Profit\tSlots\n";
	
	for(int i=1;i<=n;i++)
	{
		if(count==md)//This block is for printing table
		{
			cout<<"\t"<<job[i].jobID<<"\t"<<job[i].profit<<"\t";
			cout<<job[i].deadline<<"\t"<<"   Reject,Slots full\t\t"<<CP<<"\t";
			for(int i=1;i<=md;i++) cout<<job[slot[i]].jobID<<" ";
			cout<<endl;
			continue;
		}
		
		int k;
		bool free = false;
		for(k=job[i].deadline;k>0;k--)
		{
			if(slot[k]==0)
			{
				free = true;
				slot[k] = i;
				CP += job[i].profit;
				count++;
				//This block is for printing table
				{
					cout<<"\t"<<job[i].jobID<<"\t"<<job[i].profit<<"\t";
					cout<<job[i].deadline<<"\t"<<"   Given Slot ";
					cout<<k<<"\t\t\t"<<CP<<"\t";
					for(int i=1;i<=md;i++) cout<<job[slot[i]].jobID<<" ";
					cout<<endl;
				}
				break;
			}
				
		}
		if(free==false)	//This block is for printing table
		{
			cout<<"\t"<<job[i].jobID<<"\t"<<job[i].profit<<"\t";
			cout<<job[i].deadline<<"\t"<<"   Reject\t\t\t"<<CP<<"\t";
			for(int i=1;i<=md;i++) cout<<job[slot[i]].jobID<<" ";
			cout<<endl;
		}	
	}

	//printing result
	cout<<endl<<"Total profit = "<<CP<<endl<<"Job sequence : ";
	for(int i=1;i<=md;i++) cout<<job[slot[i]].jobID<<" ";
	cout<<endl;	
	
}


int main()
{	
	int n,m;	
			
	cout<<"Enter number of jobs : ";
	cin>>n;
	
	Job *job = new Job[n+1];
	
	cout<<"Enter jobID, profits and deadlines of "<<n<<" jobs : "<<endl;
	for(int i = 1;i<=n;i++)
	{
		cin>>job[i].jobID >>job[i].profit>>job[i].deadline;
	}
	cout<<endl;
	
	JobSequence(job,n);
	
	
}
/*Sample Input
5
1 10 1
2 1 3
3 15 2
4 20 2
5 5 3


*/
/*Sample Output
Enter number of jobs : 5
Enter jobID, profits and deadlines of 5 jobs : 
1 10 1
2 1 3
3 15 2
4 20 2
5 5 3

Job Considered	Profit	Deadline   Action		Current Profit	Slots
	4	20	2	   Given Slot 2			20	0 4 0 
	3	15	2	   Given Slot 1			35	3 4 0 
	1	10	1	   Reject			35	3 4 0 
	5	5	3	   Given Slot 3			40	3 4 5 
	2	1	3	   Reject,Slots full		40	3 4 5 

Total profit = 40
Job sequence : 3 4 5 

*/
