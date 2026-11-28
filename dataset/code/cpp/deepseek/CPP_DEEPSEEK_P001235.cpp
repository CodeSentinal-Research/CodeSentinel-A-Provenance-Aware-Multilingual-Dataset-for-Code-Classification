Here is the C++ code:

#include <iostream>
#include <algorithm>
using namespace std;

struct Job 
{
    int id;     
    int deadline;   
    int profit;    
};

bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}

int main()
{
    int N;
    cin >> N;
    Job arr[N];

    for(int i = 0; i < N; i++)
    {
        arr[i].id = i + 1;
        cin >> arr[i].deadline >> arr[i].profit;
    }

    sort(arr, arr+N, comparison);

    int max_profit = 0;

    for(int i = 0; i < N; i++)
    {
        int min_deadline = min(i+1, arr[i].deadline);

        max_profit += min_deadline * arr[i].profit;
        arr[i].deadline -= min_deadline;

        if(arr[i].deadline > 0)
        {
            int j = i - 1;
            while(arr[j].profit < arr[i].profit && arr[j].deadline > 0)
            {
                j--;
            }

            if(j >= 0)
            {
                max_profit += arr[j].profit;

                arr[j].deadline--;
            }
        }
    }

    cout << max_profit;
    return 0;
}

This program uses a greedy approach to schedule jobs. It first sorts all jobs based on profit. For each job, it finds the smallest possible deadline to complete the job and schedules it. If the deadline becomes zero, it finds a larger job to replace it and schedules it. The maximum profit is obtained by scheduling jobs in this way.