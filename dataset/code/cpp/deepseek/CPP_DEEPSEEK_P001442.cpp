#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    unordered_map<string, vector<string>> map;

    for (int i = 0; i < n; i++) {
        string file_path;
        getline(cin, file_path);
        stringstream ss(file_path);
        string dir, file;
        ss >> dir;
        ss >> file;

        string content;
        getline(cin, content);

        map[content].push_back(file);
    }

    for (auto it : map) {
        if (it.second.size() > 1) {
            for (string filename : it.second) {
                cout << filename << endl;
            }
        }
    }

    return 0;
}
This code reads the number of file paths followed by those file paths from standard input, then reads the contents of those files. For each file, it constructs a key in a map using the file content. The value of the key is a vector of file names, which are the duplicate file paths. Finally, it prints the duplicate file paths for each group of duplicate file contents.