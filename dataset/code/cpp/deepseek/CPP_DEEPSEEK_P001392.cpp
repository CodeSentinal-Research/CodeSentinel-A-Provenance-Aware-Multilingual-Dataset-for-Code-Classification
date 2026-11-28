#include <iostream>
#include <unordered_map>
using namespace std;

long long countSubarrays(int* arr, int n, int k) {
    unordered_map<int, int> um;
    long long ans = 0;
    int sum = 0;
    
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        sum %= k;
        if(sum == 0)
            ans++;
        if(um.find(sum) != um.end())
            ans += um[sum];
        um[sum]++;
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    int* arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << countSubarrays(arr, n, k);
    return 0;
}
This code first asks for the array length (n) and the divisor (k). Then it reads the array elements and calculates the sum of each subarray modulo k. If the sum becomes 0, it means that the subarray is divisible by k, so it increments the count. If the sum already exists in the map, it means that the subarray sum has appeared before, so it increments the count by the value associated with the sum in the map. The map is used to count the occurrence of all possible subarray sums. Finally, it prints the count of all valid subarrays.