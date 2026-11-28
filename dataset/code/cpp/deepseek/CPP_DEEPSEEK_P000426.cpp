Sure, here is the code:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Restaurant {
    int rating;
    string name;
};

bool comp(Restaurant a, Restaurant b) {
    return a.rating > b.rating;
}

void solve(vector<Restaurant>& restaurants, int threshold) {
    sort(restaurants.begin(), restaurants.end(), comp);

    for (Restaurant& restaurant : restaurants) {
        if (restaurant.rating >= threshold) {
            cout << restaurant.name << endl;
        }
    }
}

int main() {
    int n, threshold;
    cin >> n >> threshold;

    vector<Restaurant> restaurants(n);

    for (int i = 0; i < n; ++i) {
        cin >> restaurants[i].rating >> restaurants[i].name;
    }

    solve(restaurants, threshold);

    return 0;
}

This code will read the number of restaurants and the rating threshold from the standard input. It then reads the ratings and names of the restaurants. The solve function sorts the restaurants in descending order of their ratings, and then prints the names of the restaurants with a rating greater than or equal to the threshold.