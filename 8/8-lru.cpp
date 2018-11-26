
#include<bits/stdc++.h>

using namespace std;
int pageFaults(int pages[], int n, int capacity)
{

    set<int> s;

  map<int, int> indexes;


    int page_faults = 0;
    for (int i=0; i<n; i++)
    {

        if (s.size() < capacity)
        {

            if (s.find(pages[i])==s.end())
            {
                s.insert(pages[i]);


                page_faults++;
            }


            indexes[pages[i]] = i;
        }


        else
        {

            if (s.find(pages[i]) == s.end())
            {
                int lru = INT_MAX ,val;
               int it;
                for ( it=0; it<s.size(); it++)
                {
                    if (indexes[it] < lru)
                    {
                        lru = indexes[it];
                        val = it;
                    }
                }


                s.erase(val);


                s.insert(pages[i]);


                page_faults++;
            }

              indexes[pages[i]] = i;
        }
    }

    return page_faults;
}

int main()
{int m;int capacity;
    cout<<"Enter the no. of pages"<<endl;
    cin>>m;
    int pages[m];
    cout<<"Enter the pages"<<endl;
    for (int i=0; i<m; i++)
	{
    cin>>pages[i];
	}
    cout<<"Enter capacity"<<endl;
    cin>>capacity;
    int n = sizeof(pages)/sizeof(pages[0]);
    cout << pageFaults(pages, n, capacity);
	return 0;
}
