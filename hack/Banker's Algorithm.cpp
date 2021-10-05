#include<bits/stdc++.h>
using namespace std;
const int res=10;
class process
{
	public:
		int need[res];
		int max[res];
		int alloc[res];
		int id;
		int flag;	
};
int main()
{
	int n;
	cout<<"Enter no. of processes"<<endl;
	cin>>n;
	cout<<"Enter the type of instances"<<endl;
	int type;
	cin>>type;
	process p[n];
	int avail[type];
	for(int i=0;i<type;i++)
	cin>>avail[i];
	for(int i=0;i<n;i++)
	{   
		cout<<"Enter the resources for process "<<i+1<<":"<<endl;
		p[i].id=i+1;
		p[i].flag=0;
		for(int j=0;j<type;j++)
		cin>>p[i].alloc[j];
		for(int j=0;j<type;j++)
		cin>>p[i].max[j];
		for(int j=0;j<type;j++)
		p[i].need[j]=p[i].max[j]-p[i].alloc[j];
	}
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<type;j++)
	    {
	        avail[j]-=p[i].alloc[j];
	    }
	}
	cout<<"Do you need any resource request y or n"<<endl;
	char choice;
	cin>>choice;
	if(choice=='y')
	{
		int pno;
		int req[type];
		cout<<"Enter process no."<<endl;
		cin>>pno;
		cout<<"Enter required resources"<<endl;
		for(int i=0;i<type;i++)
		{
			cin>>req[i];
			p[pno-1].alloc[i]+=req[i];
			avail[i]-=req[i];
		}
		
	}
	vector <int> seq;
	int completed=0; int k=0;
	while(completed!=n)
	{
		if(k==n)
		{   
			cout<<"No Safe Sequence Exists"<<endl;
			if(choice=='y')
			cout<<"Request cannot be granted"<<endl;
			break;
		}
		if(p[k].flag==0)
		{int j;
			for(j=0;j<type;j++)
			{
				if(p[k].need[j]<=avail[j])
				continue;
				else
				break;
			}
		if(j==type)
		{
			seq.push_back(p[k].id);
			p[k].flag=1;
			for(int j=0;j<type;j++)
			avail[j]+=p[k].alloc[j];
			k=0;
			completed++;
		}
		else
		k++;
		}
		else
		k++;
	}
	if(completed==n)
	{
	cout<<"Safe Sequence is"<<endl;
	for(int i=0;i<seq.size();i++)
	cout<<seq[i]<<" ";
	if(choice=='y')
	{   cout<<endl;
	    cout<<"Therefore, request can be granted";
	}
	}
return 0;	
}
