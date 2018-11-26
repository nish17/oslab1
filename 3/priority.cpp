

#include<iostream>
#define n 4

using namespace std;
int main()
{
	int AT[n],BT[n],P[n],ID[n],CT[n]={0},WT[n];
	int i,j,temp,count=0;
	int pro[4],f=0;
	int id,a,b,p;
	
	for(i = 0 ; i < n ; i++ )
	{
		cout<<endl<<"Enter at, bt, priority";
		cin>>AT[i]>>BT[i]>>P[i];
		ID[i]=i+1;
	}
	
	for(i = 0; i < n ; i++ )
	{
		for(j = i+1 ; j < 4 ; j++ )
		{
			if(AT[i] > AT[j])
			{
				temp = AT[i];
				AT[i] = AT[j];
				AT[j] = temp;
				
				temp = BT[i];
				BT[i] = BT[j];
				BT[j] = temp;
				
				temp = P[i];
				P[i] = P[j];
				P[j] = temp;
				
				temp = ID[i];
				ID[i] = ID[j];
				ID[j] = temp;
			}
		}
	}
	
	
	for(i = 0 ; i < n ; i++)
	{
		p=0;
		for(j = 0 ; j < n ; j++ )
		{
			if(AT[j]<=count && CT[j]==0 )
			{
				if(P[i]>p)
				{
					id=i;
				}
			}
		}
		count = count + BT[id];
		CT[id] = count;
	}
	cout<<endl<<"Final table\n";
	
	cout<<"ID\tAT\tBT\tP\tCT";
	
	for(i = 0 ; i < n ; i++)
	{
		cout<<endl<<ID[i]<<"\t"<<AT[i]<<"\t"<<BT[i]<<"\t"<<P[i]<<"\t"<<CT[i];
	}
	return 0;
	
}
