#include <iostream>
#include <string>
#include <vector>
struct Stud { std::string name; double gpa, inc; };
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<Stud> studs(n);
        for (int i = 0; i < n; i++) std::cin >> studs[i].name >> studs[i].gpa >> studs[i].inc;
        double min_gpa, max_inc;
        std::cin >> min_gpa >> max_inc;
        for (const auto& s : studs) {
            if (s.gpa >= min_gpa && s.inc <= max_inc) std::cout << s.name << "\n";
        }
    }
    return 0;
}