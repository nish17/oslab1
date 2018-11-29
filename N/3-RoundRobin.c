#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
int main()
{
  int at[10], bt[10], ct[10], rt[10], wt[10], id[10], tat[10];
  int count, i, j, time_quant, time = 0, n, remains, temp;

  cout << "Enter number of processes: ";
  cin >> n;

  for (i = 0; i < n; i++)
  {
    cout << "Enter process id, arrival time and burst time: ";
    cin >> id[i] >> at[i] >> bt[i];
    rt[i] = bt[i];
  }

  for (i = 0; i < n; i++)
  {

    for (j = i + 1; j < n; j++)
    {
      if (at[i] > at[j])
      {
        temp = at[i];
        at[i] = at[j];
        at[j] = temp;

        temp = bt[i];
        bt[i] = bt[j];
        bt[j] = temp;

        temp = rt[i];
        rt[i] = rt[j];
        rt[j] = temp;

        temp = id[i];
        id[i] = id[j];
        id[j] = temp;
      }
    }
  }

  cout << "Enter time quantum value: ";
  cin >> time_quant;
  remains = n;
  count = 0;
  time = 0;

  while (remains != 0)
  {
    if (rt[count] <= time_quant && rt[count] > 0)
    {
      time = time + rt[count];
      ct[count] = time;
      rt[count] = 0;
      remains--;
    }

    else if (rt[count] > time_quant)
    {
      time = time + time_quant;
      rt[count] = rt[count] - time_quant;
    }

    if (count == n - 1)
    {
      count = 0;
    }
    else if (at[count + 1] < time)
    {
      count++;
    }
    else
    {
      count = 0;
    }
  }

  cout << "\nID\TAT\tBT\tCT\tTAT\tWT\n";
  for (i = 0; i < n; i++)
  {

    tat[i] = ct[i] - bt[i];
    wt[i] = tat[i] - at[i];

    cout << id[i] << "\t" << at[i] << "\t" << bt[i] << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << endl;
  }

  return 0;
}
