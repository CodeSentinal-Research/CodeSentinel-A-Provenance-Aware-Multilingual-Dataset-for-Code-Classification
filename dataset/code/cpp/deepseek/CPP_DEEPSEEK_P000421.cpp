Here is the C++ code for the given problem:

#include <iostream>
#include <vector>
#include <ctime>

struct Membership {
    int id;
    time_t expiryDate;
};

std::vector<Membership> findExpiredMemberships(std::vector<Membership>& memberships, time_t currentTime) {
    std::vector<Membership> expiredMemberships;
    for (const auto& membership : memberships) {
        if (difftime(membership.expiryDate, currentTime) < 0) {
            expiredMemberships.push_back(membership);
        }
    }
    return expiredMemberships;
}

int main() {
    std::vector<Membership> memberships;
    time_t currentTime = time(NULL);
    std::vector<Membership> expiredMemberships = findExpiredMemberships(memberships, currentTime);
    return 0;
}

This code defines a struct for a Membership with an id and an expiry date. The `findExpiredMemberships` function takes a vector of Membership objects and the current time, and returns a vector of Membership objects that have expired. The `main` function is for input and output, assuming you have a function to input the memberships and output the expired memberships. The code assumes you have a function to input the memberships and current time.