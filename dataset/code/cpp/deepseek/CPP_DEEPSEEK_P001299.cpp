#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long minTime(int N, vector<long long> times, long long totalTrips) {
    sort(times.begin(), times.end());
    long long low = 0;
    long long high = totalTrips * N;
    long long mid;
    while(low < high) {
        mid = (low + high) / 2;
        long long sum = 0;
        for(long long i = 0; i < N; i++) {
            sum += mid / times[i];
            if(sum > totalTrips) {
                break;
            }
        }
        if(sum >= totalTrips) {
            high = mid;
        } else {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    return low;
}

int main() {
    int N;
    long long totalTrips;
    cin >> N >> totalTrips;
    vector<long long> times(N);
    for(int i = 0; i < N; i++) {
        cin >> times[i];
    }
    cout << minTime(N, times, totalTrips) << endl;
    return 0;
}