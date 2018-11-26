
#include <iostream>

using namespace std;
#define res 1

int Allocation[10][2] , Max[10][2] , Available[2], Need[10][2] , c_Available[2]; // 2 resources
   int Request[10][2], n , i , j , flag=0 , counter=0, pcom=0 , rp;

int safety_check();
void resource_request();
int req_allo();
int req_need();
int main()
{
   
   
   cout<<endl<<"Enter number of process: ";
   cin>>n;
   cout<<endl;
   for(i=0;i<n;i++)
   {
       cout<<"Enter Allocation for Process "<<i+1<<endl;
       for(j=0;j<res;j++)
       {
           cin>>Allocation[i][j];
       }
       
       cout<<"Enter Max for Process "<<i+1<<endl;
       for(j=0;j<res;j++)
       {
           cin>>Max[i][j];
       }
   }
   
    cout<<"Enter total Available resources \n";
    for(j=0;j<res;j++)
    {
       cin>>Available[j];
    }
    
    // request and need matrix
    for(i=0;i<n;i++)
    {
        for(j=0;j<res;j++)
        {
            Need[i][j] = Max[i][j] - Allocation[i][j];
//        cout<<endl<<Request[i][j];
        }
    }
    
    //Currently available resource matrix
    for(j=0;j<res;j++)
    {
        for(i=0;i<n;i++)
        {
            Available[j] = Available[j] - Allocation[i][j];
        }
    c_Available[j] = Available[j];
//    cout<<"Available "<<j+1<<" = "<<c_Available[j];
    }
   
    //Deadlock detection 
   
    int result = safety_check();
    int select=0;
// Start allocating resources

	if(result==1)
	{
		while(1)
		{
			cout<<endl<<"Press 1 for resource allocation: ";
			cout<<endl<<"Press 2 to exit"<<endl;
			cin>>select;
			if(select == 2)
			{
				break;
			}
			else
			{
				cout<<endl<<"Enter Requesting Process : ";
   				cin>>rp;
				rp=rp-1;
				cout<<endl<<rp;
    			cout<<"Enter number of instances of resouces requested\n";
    			for(j=0;j<res;j++)
    			{		
        			cin>>Request[rp][j];
    				cout<<Request[rp][j];
    			}
    			cout<<endl<<"Reached";
    			cout<<endl<<Need[rp];
    			if(req_need())
    			{
					if(req_allo())
					{
						for(j=0;j<res;j++)
        				{
            				c_Available[j] = c_Available[j] - Request[rp][j];
            				Allocation[rp][j] = Allocation[rp][j] + Request[rp][j];
            				Need[rp][j] = Need[rp][j] - Request[rp][j];
        				}
        				resource_request();    
					}	
					else
					{
						cout<<endl<<"Request greater than allocation";
					}
				}		
				else
				{
					cout<<endl<<"Request is greater than need";
				}
			}
		}
	}

    
    
   return 0;
}

int safety_check()
{
pcom=0;
 while(pcom<n)
    {
        flag=0;
        for(i=0;i<n;i++)
        {
            counter=0;
            for(j=0;j<res;j++)
            {
                if(Need[i][j] > c_Available[j])
                {
                    flag++;
                    break;
                }
                else
                {
                   counter++; 
                }
            }
            
            if(counter == res)
            {
                c_Available[j] = c_Available[j] + Allocation[i][j];
                pcom++;
       			break;
            }
        }
        if(flag == n )
        {
            cout<<endl<<"Deadlock found!!! It's Unsafe here";
            return 0;	
        }
        else
        {
        //	cout<<"Entered for loop";
		}
    }
    cout<<endl<<pcom;
    if(pcom == n)
    {
        cout<<endl<<"It's absolutely safe here : )";
        return 1;
    }
    else
    {
    	//cout<<"ENtered while loop";
	}
}

void resource_request()
{
	pcom=0;
 while(pcom<n)
    {
        flag=0;
        for(i=0;i<n;i++)
        {
            counter=0;
            for(j=0;j<res;j++)
            {
                if(Need[i][j] > c_Available[j])
                {
                    flag++;
                    break;
                }
                else
                {
                   counter++; 
                }
            }
            
            if(counter == res)
            {
                c_Available[j] = c_Available[j] + Allocation[i][j];
                pcom++;
        break;
            }
        }
        if(flag == n )
        {
            cout<<endl<<"Cannot allocate requested resource!!!";
            for(j=0;j<2;j++)
        	{
            	c_Available[j] = c_Available[j] + Request[rp][j];
            	Allocation[rp][j] = Allocation[rp][j] - Request[rp][j];
            	Need[rp][j] = Need[rp][j] + Request[rp][j];
        	}
            break;
        }
        else
        {
        //	cout<<"Entered for loop";
		}
    }
    cout<<endl<<pcom;
    if(pcom == n)
    {
        cout<<endl<<"Resource successfully allocated : )";
    }
    else
    {
    	//cout<<"ENtered while loop";
	}
}

int req_need()
{
	int success=0;
		for(j=0;j<res;j++)
		{
			if(Request[rp][j]<Need[rp][j])
			{
				success++;
			}
		}
		if(success==res)
			return 1;
		else
			return 0;
}

int req_allo()
{
	int success=0;
		for(j=0;j<res;j++)
		{
			if(Request[rp][j]<Allocation[rp][j])
			{
				success++;
			}
		}
		if(success==res)
			return 1;
		else
			return 0;
}
