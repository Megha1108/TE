#include<iostream>
#define max 20
using namespace std;

int main(){
	struct process{
		int id,AT,TAT,BT,WT,ST,CT,priority;
	}p[20];
	int n,i=0,cur_time=0,completed=0,min_index=-1,is_comp[max];
	float ATA,AWT;
	cout<<"\nEnter no pf processes:";
	cin>>n;
	for(int i=0;i<n;i++){
		p[i].id=i+1;
		cout<<"\nEnter burst time of p["<<i+1<<"]:";
		cin>>p[i].BT;
		cout<<"\nEnter arrival time of p["<<i+1<<"]:";
		cin>>p[i].AT;
		cout<<"\nEnter priority pf p["<<i+1<<"]:";
		cin>>p[i].priority;
		is_comp[i]=0;
	}
	cout<<"Gantt chart"<<endl;
	while(completed!=n){
		int min=-1;
		for(int i=0;i<n;i++){
			if(p[i].AT<=cur_time && is_comp[i]==0){
				if(p[i].priority>min){
					min=p[i].priority;
					min_index=i;
				}
				if(p[i].priority==min){
					if(p[i].AT<p[min_index].AT){
						min=p[i].priority;
						min_index=i;
					}
				}
			}
		}
		if(min_index==-1){
			cur_time++;
		}
		else{
			p[min_index].ST=cur_time;
			p[i].CT=p[min_index].ST+p[min_index].BT;
			p[min_index].TAT=p[i].CT-p[min_index].AT;
			p[min_index].WT=p[min_index].TAT-p[min_index].BT;
			is_comp[min_index]=1;
			ATA+=p[min_index].TAT;
			AWT+=p[min_index].WT;
			cur_time=p[i].CT;
			i++;
			completed++;
			cout<<"|   P"<<p[min_index].id<<"\t";
		}
	}
	cout<<"|";
	cout<<endl<<"0\t";
	for(int i=0;i<n;i++){
		cout<<p[i].CT<<"\t";
	}
	cout<<endl;
	cout<<"\nTURN AROUND TIME";
	for(int i=0;i<n;i++){
		cout<<"\nTurn around time of p["<<i+1<<"] is:"<<p[i].TAT;
	}
	ATA=ATA/n;
	cout<<"\nWAITING TIME";
	for(int i=0;i<n;i++){
		cout<<"\nWating time of p["<<i+1<<"] is:"<<p[i].WT;
	}
	AWT=AWT/n;
	cout<<"\nAverage TAT:"<<ATA;
	cout<<"\nAverage WT:"<<AWT;
	return 0;
}

/*OUTPUT

Enter no pf processes:5
Enter burst time of p[1]:11
Enter arrival time of p[1]:0
Enter priority pf p[1]:2
Enter burst time of p[2]:28
Enter arrival time of p[2]:5
Enter priority pf p[2]:0
Enter burst time of p[3]:2
Enter arrival time of p[3]:12
Enter priority pf p[3]:3
Enter burst time of p[4]:10
Enter arrival time of p[4]:2
Enter priority pf p[4]:1
Enter burst time of p[5]:16
Enter arrival time of p[5]:9
Enter priority pf p[5]:4
Gantt chart
|   P1	|   P5	|   P3	|   P4	|   P2	|
0	11	27	29	39	67	

TURN AROUND TIME
Turn around time of p[1] is:11
Turn around time of p[2] is:62
Turn around time of p[3] is:17
Turn around time of p[4] is:37
Turn around time of p[5] is:18
WAITING TIME
Wating time of p[1] is:0
Wating time of p[2] is:34
Wating time of p[3] is:15
Wating time of p[4] is:27
Wating time of p[5] is:2
Average TAT:29
Average WT:15.6

*/
