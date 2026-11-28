#include <iostream>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    string serialize(TreeNode* root) {
        stringstream ss;
        serializeHelper(root, ss);
        return ss.str();
    }

    TreeNode* deserialize(string data) {
        queue<string> q;
        size_t pos = 0;
        string token;
        while ((pos = data.find(",")) != string::npos) {
            token = data.substr(0, pos);
            data.erase(0, pos + 1);
            q.push(token);
        }
        q.push(data);

        TreeNode* root = deserializeHelper(q);
        return root;
    }

private:
    void serializeHelper(TreeNode* node, stringstream& ss) {
        if (node == NULL) {
            ss << "N,";
        } else {
            ss << node->val << ",";
            serializeHelper(node->left, ss);
            serializeHelper(node->right, ss);
        }
    }

    TreeNode* deserializeHelper(queue<string>& q) {
        if (q.front() == "N") {
            q.pop();
            return NULL;
        }

        TreeNode* node = new TreeNode(stoi(q.front()));
        q.pop();
        node->left = deserializeHelper(q);
        node->right = deserializeHelper(q);

        return node;
    }
};

int main() {
    return 0;
}