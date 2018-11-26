#include<iostream>
#define frames 3
#define pages 18

using namespace std;
void push();
int check();
int find_min_index();
void display();
void replace();
int Process[pages],Frame_Stack[frames],Index[frames],page_fault=0,i,j,tos=-1;
int main()
{
	
	// take input : Process
	cout<<endl<<"Enter order in which process is to be executed:::\n";
	for(i=0;i<pages;i++)
	{
		cin>>Process[i];
	}
	
	
	//check whether frame stack is full or not
	for(i=0;i<pages;i++)
	{
	//	cout<<endl<<"Process "<<Process[i]<<" has arrived\n";
		if(tos<frames-1)
		{
			push();
		}	
		else
		{
			//check whether element is already in frame
			int c = check();
			
			//if yes then change index bit (no page fault)
			//else page replacement and page fault;
			
			if(c==0)
			{
				replace();
				
			}

		}	
		display();	
	}
	cout<<endl<<"Total page faults = "<<page_fault;
	
return 0;	
}

void display()
{
	cout<<endl;
	for (int j=0;j<=tos;j++)
	{
		cout<<Frame_Stack[j]<<" ";
	}
}
void push()
{
	tos++;
	Index[tos]=i;
	Frame_Stack[tos]=Process[i];
	page_fault++;
	cout<<endl<<"Page fault occured at process "<<Process[i];
}

int check()
{
	int found=0;
	for(j=0;j<frames;j++)
	{
		if(Frame_Stack[j]==Process[i])
		{
			Index[j]=i;
			found=1;
			break;
		}
		else
		{
			continue;
		}
	}
	return found;
}

void replace()
{
	//find min index and replace it
//	cout<<endl<<"Called";
	int indx = find_min_index();
//	cout<<endl<<"Minimum index "<<indx;
	for(j=0;j<=tos;j++)
	{
	
		if(j==indx)
		{
			Frame_Stack[j] = Process[i];
			page_fault++;
			Index[j] = i;
			cout<<endl<<"Page fault occured at process "<<Process[i];
			break;
		}
	}
}

int find_min_index()
{
	int temp=10000,min_index;
	for(j=0;j<=tos;j++)
	{
		if(Index[j]<temp)
		{
			temp=Index[j];
			min_index=j;
		}
	}
	return min_index;
}

