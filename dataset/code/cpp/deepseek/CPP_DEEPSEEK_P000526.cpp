#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

string countOfAtoms(string formula) {
    map<string, int> count;
    map<string, int> next;
    map<string, int> prev;

    int i = 0;
    while (i < formula.size()) {
        if (formula[i] == '(') {
            i++;
            int bracketCount = 1;
            while (bracketCount != 0) {
                if (formula[i] == '(') bracketCount++;
                else if (formula[i] == ')') bracketCount--;
                i++;
            }
        } else {
            string atom;
            if (isupper(formula[i])) {
                while (i < formula.size() && isupper(formula[i])) {
                    atom += formula[i];
                    i++;
                }
                count[atom]++;
            } else {
                atom += formula[i];
                i++;
                while (i < formula.size() && isdigit(formula[i])) {
                    atom += formula[i];
                    i++;
                }
                count[atom]++;
            }
        }
    }

    for (auto& pair: count) {
        cout << pair.first << " : " << pair.second << endl;
    }

    return "";
}

int main() {
    string formula = "H2O(OH)2(SO3)2";
    countOfAtoms(formula);
    return 0;
}