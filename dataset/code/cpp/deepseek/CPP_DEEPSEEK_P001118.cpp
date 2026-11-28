#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct Node {
    int id;
    int in_degree;
    vector<int> children;
    Node(int i): id(i), in_degree(0) {}
};

vector<int> alien_lexicography(int n, vector<string> words) {
    unordered_map<char, Node*> node_map;
    int size = 0;
    for(auto& word : words) {
        for(char c : word) {
            if(node_map.find(c) == node_map.end()) {
                node_map[c] = new Node(size++);
            }
        }
    }

    for(int i=0; i<n-1; i++) {
        string& word1 = words[i];
        string& word2 = words[i+1];
        for(int j=0; j<min(word1.size(), word2.size()); j++) {
            if(word1[j] != word2[j]) {
                node_map[word1[j]]->children.push_back(node_map[word2[j]]->id);
                node_map[word2[j]]->in_degree++;
                break;
            }
        }
    }

    queue<Node*> q;
    for(auto& p : node_map) {
        if(p.second->in_degree == 0) {
            q.push(p.second);
        }
    }

    vector<char> result;
    while(!q.empty()) {
        Node* node = q.front();
        result.push_back(node->id + 'a');
        q.pop();
        for(int id : node->children) {
            node_map[id]->in_degree--;
            if(node_map[id]->in_degree == 0) {
                q.push(node_map[id]);
            }
        }
    }

    if(result.size() == size) {
        for(char c : result) {
            cout << c << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    for(auto& p : node_map) {
        delete p.second;
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<string> words;
    for(int i=0; i<n; i++) {
        getline(cin, line);
        words.push_back(line);
    }

    vector<char> result = alien_lexicography(n, words);

    return 0;
}
This C++ code creates a graph using adjacency lists and performs topological sorting. It first builds a map from characters to their nodes, then it builds a queue with all nodes with no incoming edges, which represent the roots of the trees. Then it removes edges and updates the in-degree of the nodes, and repeats the process until the queue is empty. If the size of the result vector is equal to the number of nodes, then it prints the result, otherwise it prints IMPOSSIBLE.