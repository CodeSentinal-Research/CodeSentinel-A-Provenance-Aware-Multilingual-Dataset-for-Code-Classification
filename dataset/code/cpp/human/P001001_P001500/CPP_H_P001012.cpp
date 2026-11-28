#include <iostream>
#include <vector>
using namespace std;

int calculatePower(int base, int power)
{
    if (power <= 0)
    {
        return 1;
    }

    int half = calculatePower(base, power / 2);

    if (power & 1)
    {
        return half * half * base;
    }

    return half * half;
}

void print(vector<int> &heapArray)
{
    int sizeOfHeap = heapArray.size();
    if (sizeOfHeap <= 0)
    {
        cout << "Bhai! Heap Empty hai.... Print kya karoon main batao......" << endl;
        return;
    }

    cout << endl;
    cout << "Printing Heap: " << endl;
    int index = 0;
    int level = 1;

    while (index < sizeOfHeap)
    {
        int numberOfElementsInCurrentLevel = calculatePower(2, level - 1);

        int totalNumberOfElementsInPreviousLevels = numberOfElementsInCurrentLevel - 1;
        index = totalNumberOfElementsInPreviousLevels;

        // cout << "Index is: "<< index << " and Size is: " << sizeOfHeap << endl;

        // Print Current Level
        // cout << "At Level " << level << ": ";
        while (index < sizeOfHeap && numberOfElementsInCurrentLevel > 0)
        {
            cout << heapArray[index] << " ";
            index++;
            numberOfElementsInCurrentLevel--;
        }
        cout << endl;

        // Increase the level
        level++;
    }
}

void minHeapify(vector<int> &heapArray, int sizeOfHeap, int index)
{
    if (index >= sizeOfHeap - 1 || index < 0)
    {
        return;
    }

    int element = heapArray[index];
    int minElement = heapArray[index];
    int minElementIndex = index;
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;

    if ((rightChildIndex < sizeOfHeap) && (heapArray[rightChildIndex] < minElement))
    {
        minElement = heapArray[rightChildIndex];
        minElementIndex = rightChildIndex;
    }

    if ((leftChildIndex < sizeOfHeap) && (heapArray[leftChildIndex] < minElement))
    {
        minElement = heapArray[leftChildIndex];
        minElementIndex = leftChildIndex;
    }

    if (minElementIndex != index)
    {
        swap(heapArray[index], heapArray[minElementIndex]);
        minHeapify(heapArray, sizeOfHeap, minElementIndex);
    }

    return;
}

void maxHeapify(vector<int> &heapArray, int sizeOfHeap, int index)
{

    if (index >= sizeOfHeap - 1 || index < 0)
    {
        return;
    }

    int element = heapArray[index];
    int maxElement = heapArray[index];
    int maxElementIndex = index;
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;

    if ((rightChildIndex < sizeOfHeap) && (heapArray[rightChildIndex] > maxElement))
    {
        maxElement = heapArray[rightChildIndex];
        maxElementIndex = rightChildIndex;
    }

    if ((leftChildIndex < sizeOfHeap) && (heapArray[leftChildIndex] > maxElement))
    {
        maxElement = heapArray[leftChildIndex];
        maxElementIndex = leftChildIndex;
    }

    if (maxElementIndex != index)
    {
        swap(heapArray[index], heapArray[maxElementIndex]);
        maxHeapify(heapArray, sizeOfHeap, maxElementIndex);
    }

    return;
}

void buildMinHeap(vector<int> &heapArray)
{
    cout << "Building Min Heap........ " << endl;
    int sizeOfHeap = heapArray.size();
    for (int index = sizeOfHeap / 2 - 1; index >= 0; index--)
    {
        minHeapify(heapArray, sizeOfHeap, index);
    }

    return;
}

void buildMaxHeap(vector<int> &heapArray)
{
    cout << "Building Max Heap........ " << endl;
    int sizeOfHeap = heapArray.size();
    for (int index = sizeOfHeap / 2 - 1; index >= 0; index--)
    {
        maxHeapify(heapArray, sizeOfHeap, index);
    }

    return;
}

void heapSort(vector<int> &array)
{
    int sizeOfArray = array.size();
    for (int index = (sizeOfArray / 2) - 1; index >= 0; index--)
    {
        maxHeapify(array, sizeOfArray, index);
    }

    // Swap One Element From Top to the Last Element and decrease size by 1 & Heapify Again Until We have 1 element in array
    while (sizeOfArray > 1)
    {
        swap(array[0], array[sizeOfArray - 1]);
        sizeOfArray--;
        maxHeapify(array, sizeOfArray, 0);
    }

    cout << endl;
    cout << endl;

    cout << "Array after Heap Sort: ";
    for (auto element : array)
    {
        cout << element << " ";
    }
    cout << endl;
    cout << endl;
}

vector<int> mergeTwoMinHeaps(vector<int> &firstMinHeap, vector<int> &secondMinHeap)
{
    // Approach 1: Simply Create a new Min Heap and Insert one by one all Elements into it TC: O( (N+M)*log(N+M) )   &  SC: O(N+M)
    // Approach 2: Simply Merge both Min Heap and Run Build Min Heapify Algorithm TC: O(N+M)   &  SC: O(N+M)

    vector<int> mergedMinHeap = firstMinHeap;
    for (auto element : secondMinHeap)
    {
        mergedMinHeap.push_back(element);
    }

    buildMinHeap(mergedMinHeap);
    return mergedMinHeap;
}



vector<int> mergeTwoMaxHeaps(vector<int> &firstMaxHeap, vector<int> &secondMaxHeap)
{
    // Approach 1: Simply Create a new Max Heap and Insert one by one all Elements into it TC: O( (N+M)*log(N+M) )   &  SC: O(N+M)
    // Approach 2: Simply Merge both Max Heap and Run Build Max Heapify Algorithm TC: O(N+M)   &  SC: O(N+M)

    vector<int> mergedMaxHeap = firstMaxHeap;
    for (auto element : secondMaxHeap)
    {
        mergedMaxHeap.push_back(element);
    }

    buildMaxHeap(mergedMaxHeap);
    return mergedMaxHeap;
}

int main()
{
    vector<int> inputArray;
    // 4 2 1 3 6 5 7 -1
    // 15 60 7 80 9 10 -1
    // 45 20 10 5 15 35 30 25 40 50 60 55 75 70 65 -1
    // 40 20 10 5 15 30 35 35 60 50 45 55 70 65 75 -1
    // 10 5 3 30 -2 2 1 -3 11 -1
    cout << "Please Enter Array to build heap (Enter -1 to stop taking input): ";
    int data = 0;
    cin >> data;

    while (data != -1)
    {
        inputArray.push_back(data);
        cin >> data;
    }

    vector<int> minHeap = inputArray;
    vector<int> maxHeap = inputArray;

    buildMaxHeap(maxHeap);
    buildMinHeap(minHeap);

    print(minHeap);
    print(maxHeap);

    heapSort(maxHeap);
    print(maxHeap);

    vector<int> mergedMaxHeap = mergeTwoMaxHeaps(maxHeap, minHeap);
    vector<int> mergedMinHeap = mergeTwoMinHeaps(maxHeap, minHeap);

    cout << endl;
    cout << endl;
    cout << "Presenting the Merged Max Heap: " << endl;
    print(mergedMaxHeap);

    cout << endl;
    cout << endl;
    cout << "Presenting the Merged Min Heap: " << endl;
    print(mergedMinHeap);

    return 0;
}