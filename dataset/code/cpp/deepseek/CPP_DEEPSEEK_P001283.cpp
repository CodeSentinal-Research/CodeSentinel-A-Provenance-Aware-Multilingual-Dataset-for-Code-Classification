Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person {
    int height;
    int count;

    Person(int h, int c) : height(h), count(c) {}

    bool operator<(const Person& p) const {
        return height > p.height;
    }
};

vector<Person> reconstructQueue(vector<Person>& people) {
    sort(people.begin(), people.end());

    vector<Person> result;
    for (Person& person : people) {
        result.insert(result.begin() + person.count, person);
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<Person> people;
    for (int i = 0; i < n; i++) {
        int height, count;
        cin >> height >> count;
        people.push_back(Person(height, count));
    }

    vector<Person> result = reconstructQueue(people);

    for (Person& person : result) {
        cout << person.height << " " << person.count << endl;
    }

    return 0;
}

This code first defines a `Person` struct to represent each person. It then defines a `reconstructQueue` function that sorts the people in descending order of their height. This ensures that the person with the greatest height is processed first.

In the `reconstructQueue` function, each person is inserted into the result vector at the index of their count. This ensures that the person with the maximum height is processed first.

Finally, in the `main` function, the code reads the number of people and their heights from standard input, creates a list of `Person` objects, and calls the `reconstructQueue` function to reconstruct the queue. The result is printed to standard output.