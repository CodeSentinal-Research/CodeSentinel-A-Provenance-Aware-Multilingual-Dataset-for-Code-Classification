#include <iostream>
#include <vector>

using namespace std;

int countCollisions(string road) {
    int collisions = 0;
    vector<char> direction(road.length(), ' ');
    for (int i = 0; i < road.length(); i++) {
        if (i > 0 && road[i] != direction[i-1]) {
            if (direction[i-1] == 'R') {
                collisions++;
            }
            direction[i] = road[i];
        } else {
            direction[i] = road[i];
        }
    }
    return collisions;
}

int main() {
    string road;
    cin >> road;
    cout << countCollisions(road) << endl;
    return 0;
}