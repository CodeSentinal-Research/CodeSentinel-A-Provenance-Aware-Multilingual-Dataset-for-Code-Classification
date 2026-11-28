#include <iostream>
#include <vector>

using namespace std;

bool knows(vector<vector<int>> &M, int a, int b) {
    return M[a][b] == 1;
}

int findCelebrity(vector<vector<int>> &M) {
    int n = M.size();
    stack<int> st;
    for (int i = 0; i < n; i++)
        st.push(i);
    while (st.size() > 1) {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        if (knows(M, a, b))
            st.push(b);
        else
            st.push(a);
    }
    int celeb = st.top();
    for (int i = 0; i < n; i++) {
        if (i != celeb && (knows(M, celeb, i) || !knows(M, i, celeb)))
            return -1;
    }
    return celeb;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> M(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> M[i][j];
        }
    }
    int celebrity = findCelebrity(M);
    if (celebrity == -1)
        cout << "No Celebrity\n";
    else
        cout << "Celebrity at index " << celebrity << "\n";
    return 0;
}
This code takes care of finding the celebrity in a party. It first verifies if a person 'knows' another person by comparing the matrix. Then it checks if the found celebrity does not know anyone and everyone knows the celebrity, if both conditions are satisfied, then it is the celebrity. If not, then the person cannot be the celebrity.