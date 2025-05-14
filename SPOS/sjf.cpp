#include<iostream>
#include<string.h>
using namespace std;

void SJF_pre(int n,int BT[],string p[],int AT[])
{
    int Finish_time[10],TA[10],WT[10];
    float cnt=0,count=0;
    for (int i = 0; i<n; i++)
    {
        if(i==0)
        {   Finish_time[i]=BT[i]+AT[i];
            TA[i]=Finish_time[i]-AT[i];
        }
        else
        {
            Finish_time[i]=BT[i]+Finish_time[i-1];
            TA[i]=Finish_time[i]-AT[i];
        }
    }
    cout<<endl;
    cout<<"Premptive"<<endl;
    cout<<"GANTT-CHART"<<endl;
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"  "<<p[i]<<"  ";
    }
    cout<<endl;
    cout<<AT[0];
    int d=BT[0]+AT[0];
    for(int i=0;i<n;i++)
    {
        cout<<"    "<<d;
        d=d+BT[i+1];
    }
    cout<<endl;
    cout<<"TURN-AROUND TIME "<<endl;
    for (int i = 0; i<n; i++)
    {
        cout<<"Turn-around time of "<<p[i]<<"= "<<TA[i]<<" msec"<<endl;
    }
    for (int i = 0; i<n; i++)
    {
        cnt+=TA[i];
    }
    cnt=cnt/n;
    cout<<"Average Turn-around time of = "<<cnt<<" msec"<<endl;
    cout<<endl;
    for (int i = 0; i<n; i++)
    {
        WT[i]=TA[i]-BT[i];
        cout<<"Waiting time of "<<p[i]<<"= "<<WT[i]<<" msec"<<endl;
    }
    for (int i = 0; i<n; i++)
    {
        count+=WT[i];
    }
    count=count/n;
    cout<<"Average Waiting time of = "<<count<<" msec"<<endl;
}

int main()
{
    int n,s, BT[10],AT[10];
    string p[10];
    cout<<"Enter the number of process: ";
    cin>>s;
    for (int i = 0; i<s; i++)
    {
        cout<<"Enter the process name: ";
        cin>>p[i];
        cout<<"Enter the Burst time :";
        cin>>BT[i];
        cout<<"Enter the Arrival time : ";
        cin>>AT[i];
        if(AT[i]!=0)
        {
            if(i>1)
            {
                if(BT[i]<BT[i-1])
                {
                    int c=BT[i];
                    string q=p[i];
                    BT[i]=BT[i-1];
                    p[i]=p[i-1];
                    BT[i-1]=c;
                    p[i-1]=q;
                }
            }
        }
    }
    SJF_pre(s,BT,p,AT);
    return 0;}


/*
output

Enter the number of process: 5
Enter the process name: 1
Enter the Burst time :7
Enter the Arrival time : 1
Enter the process name: 2
Enter the Burst time :3
Enter the Arrival time : 3
Enter the process name: 3
Enter the Burst time :2
Enter the Arrival time : 6
Enter the process name: 4
Enter the Burst time :10
Enter the Arrival time : 7
Enter the process name: 5
Enter the Burst time :8
Enter the Arrival time : 9
Premptive
GANTT-CHART

  1    3    2    5    4  
1    8    10    13    21    31
TURN-AROUND TIME 
Turn-around time of 1= 7 msec
Turn-around time of 3= 7 msec
Turn-around time of 2= 7 msec
Turn-around time of 5= 14 msec
Turn-around time of 4= 22 msec
Average Turn-around time of = 11.4 msec

Waiting time of 1= 0 msec
Waiting time of 3= 5 msec
Waiting time of 2= 4 msec
Waiting time of 5= 6 msec
Waiting time of 4= 12 msec
Average Waiting time of = 5.4 msec

*/
