Here is the C++ code for the problem:

#include <iostream>
using namespace std;

int tour(int n, int petrol[], int distance[])
{
    int curr_petrol = 0, start_point = 0;

    for (int i = 0; i < n; i++)
    {
        curr_petrol += petrol[i] - distance[i];

        if (curr_petrol < 0)
        {
            start_point = i + 1;
            curr_petrol = 0;
        }
    }

    if (start_point == n && curr_petrol >= 0)
    {
        return -1;
    }

    return start_point;
}

int main()
{
    int n;
    cin >> n;

    int petrol[n], distance[n];

    for (int i = 0; i < n; i++)
    {
        cin >> petrol[i] >> distance[i];
    }

    cout << tour(n, petrol, distance);

    return 0;
}

This program reads the number of petrol pumps and the petrol and distance arrays from the standard input. It then calls the `tour` function with these inputs and prints the result. The `tour` function iterates over the petrol pumps, accumulating the current petrol level and the starting point of a possible tour. If it encounters a petrol pump where the remaining petrol level is negative, it sets the starting point to the next petrol pump and resets the current petrol level. If it has checked all petrol pumps and the current petrol level is nonnegative, it returns -1. Otherwise, it returns the starting point.