Here is the C++ code for your problem:

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

double solveEquation(unordered_map<string, double>& map, string equation) {
    int x = 0, d = 0, f = 0;
    double res = 0.0;
    for (char c : equation) {
        if (c == 'x') {
            x++;
        } else if (c == 'd') {
            d++;
        } else if (c == 'f') {
            f++;
        } else if (isdigit(c)) {
            if (x > 0) {
                res = c - '0';
                x--;
            } else if (d > 0) {
                res *= (c - '0');
                d--;
            } else if (f > 0) {
                res /= (c - '0');
                f--;
            }
        } else if (x > 0) {
            res *= (c - 'a' + 1);
            x--;
        } else if (d > 0) {
            res /= (c - 'a' + 1);
            d--;
        } else if (f > 0) {
            res += (c - 'a' + 1);
            f--;
        }
    }
    return res;
}

int main() {
    unordered_map<string, double> map;
    int E, Q;
    cin >> E;
    while (E--) {
        string var;
        double val;
        cin >> var >> val;
        map[var] = val;
    }
    cin >> Q;
    while (Q--) {
        string equation;
        cin >> equation;
        double res = solveEquation(map, equation);
        if (res == -1.0) {
            cout << "-1.0" << endl;
        } else {
            cout << res << endl;
        }
    }
    return 0;
}

This code first reads the equations and values, storing them in a map. Then it reads the queries, solving each equation and printing the result. If the result cannot be determined, it prints -1.0.