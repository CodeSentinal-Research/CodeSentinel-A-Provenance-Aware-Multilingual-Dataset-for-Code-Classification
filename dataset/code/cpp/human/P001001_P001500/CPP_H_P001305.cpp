#include <bits/stdc++.h>
using namespace std;

/*
===============================================================================
💡 PROBLEM STATEMENT: HUFFMAN CODING
===============================================================================

Given a set of characters and their frequencies, build a Huffman Tree and
generate Huffman Codes such that the total cost of encoding is minimized.

🧠 Concept:
------------
- Huffman Coding is a **lossless data compression** algorithm.
- The idea is to assign shorter codes to more frequent characters,
  and longer codes to less frequent ones.
- It uses a **binary tree** where the least frequent nodes are placed deeper.

===============================================================================
📘 Example:
------------
Characters: A, B, C, D, E
Frequencies: 5, 9, 12, 13, 16, 45

👉 Output Huffman Codes (may vary in order):
    A: 1100
    B: 1101
    C: 100
    D: 101
    E: 111
    F: 0

===============================================================================
🔹 Approach (Greedy Algorithm using Min Heap):
===============================================================================

1️⃣ Create a leaf node for each character and insert into a min-heap
    (priority queue based on frequency).

2️⃣ While heap has more than one node:
    - Extract two nodes with minimum frequency.
    - Create a new internal node with frequency = sum of both.
    - Assign left and right children to this node.
    - Push this new node back into the heap.

3️⃣ The remaining node is the root of the Huffman Tree.

4️⃣ Traverse the Huffman Tree:
    - Append ‘0’ when moving left, ‘1’ when moving right.
    - Record codes for all leaf nodes (characters).

===============================================================================
Time Complexity: O(n log n)
Space Complexity: O(n)
===============================================================================
*/


// 🔹 Huffman Tree Node structure
struct Node {
    char ch;         // character
    int freq;        // frequency
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// 🔹 Custom comparator for the min-heap (priority queue)
struct compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq; // smaller freq = higher priority
    }
};

// 🔹 Recursive function to print Huffman Codes
void printCodes(Node* root, string code) {
    if (!root) return;

    // Leaf node → print character and its code
    if (!root->left && !root->right) {
        cout << root->ch << ": " << code << endl;
        return;
    }

    // Traverse left (add '0') and right (add '1')
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}


// 🔹 Function to build Huffman Tree and print codes
void huffmanCoding(vector<char>& chars, vector<int>& freq, int n) {
    // Step 1: Create a min heap and insert all characters
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    for (int i = 0; i < n; i++) {
        minHeap.push(new Node(chars[i], freq[i]));
    }

    // Step 2: Build Huffman Tree
    while (minHeap.size() > 1) {
        // Extract two smallest nodes
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        // Create new internal node with combined frequency
        Node* newNode = new Node('$', left->freq + right->freq); // '$' means internal node
        newNode->left = left;
        newNode->right = right;

        // Insert new node into heap
        minHeap.push(newNode);
    }

    // Step 3: Root of Huffman Tree
    Node* root = minHeap.top();

    cout << "Huffman Codes:\n";
    printCodes(root, "");
}


// 🔹 Driver Function
int main() {
    // Example data
    vector<char> chars = {'A', 'B', 'C', 'D', 'E', 'F'};
    vector<int> freq  = {5, 9, 12, 13, 16, 45};

    int n = chars.size();

    huffmanCoding(chars, freq, n);

    return 0;
}


/*
===============================================================================
🧠 STEP-BY-STEP EXPLANATION:
===============================================================================

Suppose:
Characters: A, B, C, D, E, F
Frequencies: 5, 9, 12, 13, 16, 45

------------------------------------------------------------------------------
1️⃣ Insert all nodes into a min-heap:
     [A:5, B:9, C:12, D:13, E:16, F:45]

2️⃣ Extract 2 smallest → A(5), B(9)
     New Node = 5 + 9 = 14
     Push back 14 into heap.

3️⃣ Now heap = [C:12, D:13, E:16, F:45, (A+B):14]
   Extract 2 smallest again → C(12), D(13)
     New Node = 25

4️⃣ Heap = [E:16, F:45, (A+B):14, (C+D):25]
   Extract 2 smallest → (A+B):14, E(16)
     New Node = 30

5️⃣ Heap = [F:45, (C+D):25, (A+B+E):30]
   Extract 2 smallest → (C+D):25, (A+B+E):30
     New Node = 55

6️⃣ Heap = [F:45, (all others):55]
   Extract 2 smallest → 45, 55
     New Node = 100 (root)

------------------------------------------------------------------------------
Now Huffman Tree is complete ✅

Traverse tree:
- Left edge → ‘0’
- Right edge → ‘1’

Each character gets a unique binary code (no code is prefix of another).

------------------------------------------------------------------------------
✅ Example Output (Codes may differ depending on tree shape):
F: 0
C: 100
D: 101
A: 1100
B: 1101
E: 111
------------------------------------------------------------------------------
Shortest codes are assigned to higher frequencies (greedy property).
===============================================================================
*/
