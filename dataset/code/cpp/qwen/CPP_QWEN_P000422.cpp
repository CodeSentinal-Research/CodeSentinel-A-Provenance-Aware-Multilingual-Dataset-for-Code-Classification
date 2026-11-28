#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n; double min_gpa; int max_income; cin >> n >> min_gpa >> max_income;
    vector<double> gpas(n); vector<int> incomes(n);
    for(int i=0; i<n; i++) { cin >> gpas[i] >> incomes[i]; }
    for(int i=0; i<n; i++) if(gpas[i] >= min_gpa && incomes[i] <= max_income) cout << i+1 << " ";
    cout << endl;
    return 0;
}
