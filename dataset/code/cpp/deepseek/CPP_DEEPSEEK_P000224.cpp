#include <iostream>
#include <vector>
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

void printJobSequence(Job sequence[], int n)
{
    for (int i = 0; i < n; i++)
        cout << sequence[i].id << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    Job sequence[n];
    for (int i = 0; i < n; i++)
    {
        sequence[i].id = i + 1;
        cout << "Enter the deadline and profit of job " << i + 1 << ": ";
        cin >> sequence[i].deadline >> sequence[i].profit;
    }

    sort(sequence, sequence + n, comparison);

    cout << "Maximum profit: ";
    int totalProfit = 0;
    for (int i = 0; i < n; i++)
    {
        totalProfit += sequence[i].profit;
    }
    cout << totalProfit << endl;

    cout << "Job sequence: ";
    printJobSequence(sequence, n);

    return 0;
}