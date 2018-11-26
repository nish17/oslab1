#include<iostream>
# define frames 3
# define pages 20

using namespace std;

void push();
void pop();
int check();
void display();
int Process[pages],Frame_Stack[frames],page_fault=0,i,j,front=-1,rear=-1;
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
		if(rear<frames-1)
		{
			page_fault++;
			cout<<endl<<"Page fault occured at process "<<Process[i];
			push();	
		}
		else
		{
			
			int c = check();
			if(c==0)
			{
				page_fault++;
				cout<<endl<<"Page fault occured at process "<<Process[i];
				pop();
				push();
			}
			
		}
		display();
	}
	cout<<endl<<"Total page faults:: "<<page_fault;
	return 0;
}

void display()
{
	cout<<endl;
	for (int j=0;j<=rear;j++)
	{
		cout<<Frame_Stack[j]<<" ";
	}
}

void push()
{
	if(front==rear)
	{
		front++;
		rear++;
		Frame_Stack[rear] = Process[i];
	}
	else
	{
		rear++;
		Frame_Stack[rear] = Process[i];
	}
}

void pop()
{
	
	for(j=0;j<frames-1;j++)
	{
		Frame_Stack[j] = Frame_Stack[j+1];
	}
	rear--;
}

int check()
{
	int found=0;
	for(j=0;j<frames;j++)
	{
		if(Frame_Stack[j]==Process[i])
		{
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
