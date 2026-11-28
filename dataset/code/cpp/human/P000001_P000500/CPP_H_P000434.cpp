#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <ctime>

using namespace std;

const int MAX = 100;

void updateFile(int DATA[], int N)
{
    ofstream fout("data.txt");

    for (int i = 1; i <= N; i++)
    {
        fout << DATA[i] << " ";
    }

    fout.close();
}

void display(int DATA[], int N)
{
    cout << "Current Array: ";

    for (int i = 1; i <= N; i++)
    {
        cout << DATA[i] << " ";
    }

    cout << endl;
}

int menu()
{
    int choice;

    cout << "\n--- MENU ---\n";
    cout << "1. Insert\n";
    cout << "2. Delete\n";
    cout << "3. Search\n";
    cout << "4. Display\n";
    cout << "5. Exit\n";

    cout << "Enter your choice: ";
    cin >> choice;

    return choice;
}

// FIRST occurrence search
int binarySearchFirst(int DATA[], int LB, int UB, int ITEM)
{
    int BEG = LB;
    int END = UB;
    int MID;
    int LOC = -1;

    while (BEG <= END)
    {
        MID = (BEG + END) / 2;

        if (DATA[MID] == ITEM)
        {
            LOC = MID;
            END = MID - 1;
        }
        else if (ITEM < DATA[MID])
        {
            END = MID - 1;
        }
        else
        {
            BEG = MID + 1;
        }
    }

    return LOC;
}

// LAST occurrence delete
int binarySearchLast(int DATA[], int LB, int UB, int ITEM)
{
    int BEG = LB;
    int END = UB;
    int MID;
    int LOC = -1;

    while (BEG <= END)
    {
        MID = (BEG + END) / 2;

        if (DATA[MID] == ITEM)
        {
            LOC = MID;
            BEG = MID + 1;
        }
        else if (ITEM < DATA[MID])
        {
            END = MID - 1;
        }
        else
        {
            BEG = MID + 1;
        }
    }

    return LOC;
}

// insertion position
int findInsertPosition(int DATA[], int N, int ITEM)
{
    int BEG = 1;
    int END = N;
    int MID;
    int POS = N + 1;

    while (BEG <= END)
    {
        MID = (BEG + END) / 2;

        if (DATA[MID] <= ITEM)
        {
            BEG = MID + 1;
        }
        else
        {
            POS = MID;
            END = MID - 1;
        }
    }

    return POS;
}

int main()
{
    int DATA[MAX + 1];
    int N, ITEM, LOC, choice;

    cout << "Enter number of elements: ";
    cin >> N;

    if (N > MAX)
    {
        cout << "Overflow!\n";
        return 0;
    }

    // ⭐ RANDOM GENERATION ADDED HERE
    srand(time(0));

    cout << "Randomly generating " << N << " elements...\n";

    for (int i = 1; i <= N; i++)
    {
        DATA[i] = rand() % 100; // 0 - 99 random values
    }

    cout << "\nBefore Sorting:\n";
    display(DATA, N);

    // Bubble Sort
    for (int i = 1; i <= N - 1; i++)
    {
        for (int j = 1; j <= N - i; j++)
        {
            if (DATA[j] > DATA[j + 1])
            {
                int temp = DATA[j];
                DATA[j] = DATA[j + 1];
                DATA[j + 1] = temp;
            }
        }
    }

    cout << "\nAfter Sorting:\n";
    display(DATA, N);

    updateFile(DATA, N);

    while (true)
    {
        choice = menu();

        // INSERT
        if (choice == 1)
        {
            if (N >= MAX)
            {
                cout << "Array Overflow!\n";
                continue;
            }

            cout << "Enter ITEM to insert: ";
            cin >> ITEM;

            int K = findInsertPosition(DATA, N, ITEM);

            for (int J = N; J >= K; J--)
            {
                DATA[J + 1] = DATA[J];
            }

            DATA[K] = ITEM;
            N++;

            updateFile(DATA, N);
            cout << "Inserted successfully.\n";
        }

        // DELETE
        else if (choice == 2)
        {
            if (N == 0)
            {
                cout << "Array Underflow!\n";
                continue;
            }

            cout << "Enter ITEM to delete: ";
            cin >> ITEM;

            LOC = binarySearchLast(DATA, 1, N, ITEM);

            if (LOC == -1)
            {
                cout << "Item not found.\n";
            }
            else
            {
                for (int J = LOC; J <= N - 1; J++)
                {
                    DATA[J] = DATA[J + 1];
                }

                N--;
                updateFile(DATA, N);

                cout << "Deleted successfully.\n";
            }
        }

        // SEARCH
        else if (choice == 3)
        {
            cout << "Enter ITEM to search: ";
            cin >> ITEM;

            LOC = binarySearchFirst(DATA, 1, N, ITEM);

            if (LOC == -1)
                cout << "Item not found.\n";
            else
                cout << "Item found at location: " << LOC << endl;
        }

        // DISPLAY
        else if (choice == 4)
        {
            display(DATA, N);
        }

        // EXIT
        else if (choice == 5)
        {
            updateFile(DATA, N);
            cout << "Data saved to file. Exiting...\n";
            break;
        }

        else
        {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}