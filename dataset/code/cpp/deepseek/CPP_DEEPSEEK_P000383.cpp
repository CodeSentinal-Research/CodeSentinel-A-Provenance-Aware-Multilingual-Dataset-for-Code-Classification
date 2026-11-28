#include <iostream>
#include <vector>
#include <string>

struct Member {
    int id;
    std::string name;
};

int main() {
    int n, queryId;
    std::cin >> n;

    std::vector<Member> members(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> members[i].id >> members[i].name;
    }

    std::cin >> queryId;

    bool found = false;
    for (const Member& member : members) {
        if (member.id == queryId) {
            std::cout << member.name << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Member Not Found\n";
    }

    return 0;
}