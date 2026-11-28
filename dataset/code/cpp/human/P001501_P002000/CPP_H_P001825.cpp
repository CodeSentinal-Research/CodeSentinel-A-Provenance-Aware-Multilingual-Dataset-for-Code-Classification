#include <iostream>
#include <vector>
#include <algorithm>   // for std::max, std::abs
using namespace std;

// ============================================
// 1. TreeNode for normal Binary Search Tree
// ============================================
struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int k) : key(k), left(nullptr), right(nullptr) {}
};

// ============================================
// 2. BST class
// ============================================
class BST {
private:
    TreeNode* root;

    TreeNode* insertRec(TreeNode* node, int key) {
        if (node == nullptr) return new TreeNode(key);
        if (key < node->key) node->left = insertRec(node->left, key);
        else if (key > node->key) node->right = insertRec(node->right, key);
        return node;
    }

    void inorderRec(TreeNode* node) {
        if (node != nullptr) {
            inorderRec(node->left);
            cout << node->key << " ";
            inorderRec(node->right);
        }
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) node = node->left;
        return node;
    }

    TreeNode* deleteRec(TreeNode* node, int key) {
        if (node == nullptr) return nullptr;
        if (key < node->key) {
            node->left = deleteRec(node->left, key);
        } else if (key > node->key) {
            node->right = deleteRec(node->right, key);
        } else {
            // Node found
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }
            if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            // Two children: copy successor's key and delete successor
            TreeNode* successor = findMin(node->right);
            node->key = successor->key;
            node->right = deleteRec(node->right, successor->key);
        }
        return node;
    }

public:
    BST() : root(nullptr) {}

    bool search(int key) {
        TreeNode* p = root;
        while (p != nullptr) {
            if (key == p->key) return true;
            if (key < p->key) p = p->left;
            else p = p->right;
        }
        return false;
    }

    void insert(int key) {
        root = insertRec(root, key);
    }

    void deleteKey(int key) {
        root = deleteRec(root, key);
    }

    void inorder() {
        inorderRec(root);
        cout << endl;
    }

    TreeNode* getRoot() { return root; }
    bool isEmpty() { return root == nullptr; }
};

// ============================================
// 3. AVLNode for AVL tree
// ============================================
struct AVLNode {
    int key;
    int height;
    AVLNode* left;
    AVLNode* right;
    AVLNode(int k) : key(k), height(0), left(nullptr), right(nullptr) {}
};

// ============================================
// 4. AVLTree class
// ============================================
class AVLTree {
private:
    AVLNode* root;

    int height(AVLNode* node) {
        return node ? node->height : -1;
    }

    void updateHeight(AVLNode* node) {
        node->height = 1 + max(height(node->left), height(node->right));
    }

    int balance(AVLNode* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    AVLNode* rotateRight(AVLNode* oldRoot) {
        AVLNode* newRoot = oldRoot->left;
        AVLNode* movedSubtree = newRoot->right;
        newRoot->right = oldRoot;
        oldRoot->left = movedSubtree;
        updateHeight(oldRoot);
        updateHeight(newRoot);
        return newRoot;
    }

    AVLNode* rotateLeft(AVLNode* oldRoot) {
        AVLNode* newRoot = oldRoot->right;
        AVLNode* movedSubtree = newRoot->left;
        newRoot->left = oldRoot;
        oldRoot->right = movedSubtree;
        updateHeight(oldRoot);
        updateHeight(newRoot);
        return newRoot;
    }

    AVLNode* rebalance(AVLNode* node) {
        updateHeight(node);
        int bal = balance(node);
        if (bal > 1) {
            if (balance(node->left) < 0)
                node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (bal < -1) {
            if (balance(node->right) > 0)
                node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }

    AVLNode* insertRec(AVLNode* node, int key) {
        if (node == nullptr) return new AVLNode(key);
        if (key < node->key) node->left = insertRec(node->left, key);
        else if (key > node->key) node->right = insertRec(node->right, key);
        else return node;
        return rebalance(node);
    }

    AVLNode* findMin(AVLNode* node) {
        while (node->left != nullptr) node = node->left;
        return node;
    }

    AVLNode* deleteRec(AVLNode* node, int key) {
        if (node == nullptr) return nullptr;
        if (key < node->key) {
            node->left = deleteRec(node->left, key);
        } else if (key > node->key) {
            node->right = deleteRec(node->right, key);
        } else {
            if (node->left == nullptr) {
                AVLNode* temp = node->right;
                delete node;
                return temp;
            }
            if (node->right == nullptr) {
                AVLNode* temp = node->left;
                delete node;
                return temp;
            }
            AVLNode* successor = findMin(node->right);
            node->key = successor->key;
            node->right = deleteRec(node->right, successor->key);
        }
        return rebalance(node);
    }

    void inorderRec(AVLNode* node) {
        if (node != nullptr) {
            inorderRec(node->left);
            cout << node->key << " ";
            inorderRec(node->right);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    bool search(int key) {
        AVLNode* p = root;
        while (p != nullptr) {
            if (key == p->key) return true;
            if (key < p->key) p = p->left;
            else p = p->right;
        }
        return false;
    }

    void insert(int key) {
        root = insertRec(root, key);
    }

    void deleteKey(int key) {
        root = deleteRec(root, key);
    }

    void inorder() {
        inorderRec(root);
        cout << endl;
    }

    AVLNode* getRoot() { return root; }
    bool isEmpty() { return root == nullptr; }

    int getRootKey() { return root ? root->key : -999; }
    int getRootHeight() { return height(root); }
};

// ============================================
// 5. Utility functions
// ============================================

// ---- isAVL (works on any binary tree) ----
int checkHeight(TreeNode* node) {
    if (node == nullptr) return -1;
    int leftH = checkHeight(node->left);
    if (leftH == -999) return -999;
    int rightH = checkHeight(node->right);
    if (rightH == -999) return -999;
    if (abs(leftH - rightH) > 1) return -999;
    return 1 + max(leftH, rightH);
}

bool isAVL(TreeNode* root) {
    return checkHeight(root) != -999;
}

// ---- compareTwo (non‑destructive) ----
void inorderBST(TreeNode* node, vector<int>& list) {
    if (node != nullptr) {
        inorderBST(node->left, list);
        list.push_back(node->key);
        inorderBST(node->right, list);
    }
}

void inorderAVL(AVLNode* node, vector<int>& list) {
    if (node != nullptr) {
        inorderAVL(node->left, list);
        list.push_back(node->key);
        inorderAVL(node->right, list);
    }
}

bool compareTwo(TreeNode* bstRoot, AVLNode* avlRoot) {
    vector<int> bstList, avlList;
    inorderBST(bstRoot, bstList);
    inorderAVL(avlRoot, avlList);
    return bstList == avlList;
}

// ---- compareArrayBSTAVL (destructive) ----
bool compareArrayBSTAVL(const vector<int>& arr, BST& bst, AVLTree& avl) {
    for (int x : arr) {
        if (!bst.search(x) || !avl.search(x))
            return false;
        bst.deleteKey(x);
        avl.deleteKey(x);
    }
    return bst.isEmpty() && avl.isEmpty();
}

// ============================================
// 6. Main – all tests
// ============================================
int main() {
    // -------------------------------
    // BST basic test
    // -------------------------------
    cout << "=== BST Basic ===\n";
    BST bst;
    bst.insert(6);
    bst.insert(3);
    bst.insert(11);
    bst.insert(9);
    bst.insert(8);
    bst.insert(5);
    bst.insert(4);
    cout << "Inorder: ";
    bst.inorder();   // 3 4 5 6 8 9 11
    cout << "Search 8: " << (bst.search(8) ? "true" : "false") << endl;
    cout << "Search 7: " << (bst.search(7) ? "true" : "false") << endl;

    // -------------------------------
    // BST deletion tests
    // -------------------------------
    cout << "\n=== BST Deletion ===\n";
    cout << "Delete leaf 4: ";
    bst.deleteKey(4);
    bst.inorder();
    cout << "Delete node with one child 3: ";
    bst.deleteKey(3);
    bst.inorder();
    cout << "Delete node with two children 6: ";
    bst.deleteKey(6);
    bst.inorder();

    // -------------------------------
    // AVL rotation tests
    // -------------------------------
    cout << "\n=== AVL Rotations ===\n";

    AVLTree avl1;
    avl1.insert(30);
    avl1.insert(20);
    avl1.insert(10);
    cout << "After 30,20,10: root = " << avl1.getRootKey()
         << ", height = " << avl1.getRootHeight() << "\n";

    AVLTree avl2;
    avl2.insert(10);
    avl2.insert(20);
    avl2.insert(30);
    cout << "After 10,20,30: root = " << avl2.getRootKey()
         << ", height = " << avl2.getRootHeight() << "\n";

    AVLTree avl3;
    avl3.insert(30);
    avl3.insert(10);
    avl3.insert(20);
    cout << "After 30,10,20: root = " << avl3.getRootKey()
         << ", height = " << avl3.getRootHeight() << "\n";

    AVLTree avl4;
    avl4.insert(10);
    avl4.insert(30);
    avl4.insert(20);
    cout << "After 10,30,20: root = " << avl4.getRootKey()
         << ", height = " << avl4.getRootHeight() << "\n";

    // -------------------------------
    // AVL deletion test
    // -------------------------------
    cout << "\n=== AVL Deletion ===\n";
    AVLTree avl5;
    int values[] = {10, 20, 30, 40, 50, 25};
    for (int v : values) avl5.insert(v);
    cout << "After insert 10,20,30,40,50,25: root = " << avl5.getRootKey()
         << ", height = " << avl5.getRootHeight()
         << ", inorder: ";
    avl5.inorder();

    cout << "Delete leaf 25:\n";
    avl5.deleteKey(25);
    cout << "  root = " << avl5.getRootKey()
         << ", height = " << avl5.getRootHeight()
         << ", inorder: ";
    avl5.inorder();

    cout << "Delete node with one child 30:\n";
    avl5.deleteKey(30);
    cout << "  root = " << avl5.getRootKey()
         << ", height = " << avl5.getRootHeight()
         << ", inorder: ";
    avl5.inorder();

    cout << "Delete node with two children 20:\n";
    avl5.deleteKey(20);
    cout << "  root = " << avl5.getRootKey()
         << ", height = " << avl5.getRootHeight()
         << ", inorder: ";
    avl5.inorder();

    cout << "Delete root 40:\n";
    avl5.deleteKey(40);
    cout << "  root = " << avl5.getRootKey()
         << ", height = " << avl5.getRootHeight()
         << ", inorder: ";
    avl5.inorder();

    // -------------------------------
    // isAVL tests
    // -------------------------------
    cout << "\n=== isAVL Tests ===\n";
    BST balancedBST;
    balancedBST.insert(20);
    balancedBST.insert(10);
    balancedBST.insert(30);
    cout << "Balanced BST is AVL: "
         << (isAVL(balancedBST.getRoot()) ? "true" : "false") << "\n";

    BST unbalancedBST;
    unbalancedBST.insert(10);
    unbalancedBST.insert(20);
    unbalancedBST.insert(30);
    unbalancedBST.insert(40);
    cout << "Unbalanced BST is AVL: "
         << (isAVL(unbalancedBST.getRoot()) ? "true" : "false") << "\n";

    // -------------------------------
    // compareTwo tests
    // -------------------------------
    cout << "\n=== compareTwo Tests ===\n";
    BST bstA;
    AVLTree avlA;
    int keys1[] = {6, 3, 11, 9, 8, 5, 4};
    int keys2[] = {4, 5, 8, 9, 11, 3, 6};
    for (int k : keys1) bstA.insert(k);
    for (int k : keys2) avlA.insert(k);
    cout << "Same keys? " << (compareTwo(bstA.getRoot(), avlA.getRoot()) ? "true" : "false")
         << " (expected true)\n";
    avlA.deleteKey(5);
    cout << "After deleting 5 from AVL: "
         << (compareTwo(bstA.getRoot(), avlA.getRoot()) ? "true" : "false")
         << " (expected false)\n";

    // -------------------------------
    // compareArrayBSTAVL tests
    // -------------------------------
    cout << "\n=== compareArrayBSTAVL Tests ===\n";
    BST bstB;
    AVLTree avlB;
    int arr[] = {5, 9, 3, 8, 11, 6, 4};
    for (int k : arr) {
        bstB.insert(k);
        avlB.insert(k);
    }
    vector<int> arrVec = {5, 9, 3, 8, 11, 6, 4};
    cout << "Array matches both trees? "
         << (compareArrayBSTAVL(arrVec, bstB, avlB) ? "true" : "false")
         << " (expected true)\n";
    cout << "BST empty after compare? " << (bstB.isEmpty() ? "true" : "false") << "\n";
    cout << "AVL empty after compare? " << (avlB.isEmpty() ? "true" : "false") << "\n";

    return 0;
}