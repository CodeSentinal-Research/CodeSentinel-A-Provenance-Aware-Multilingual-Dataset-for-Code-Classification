#include <iostream>
using namespace std;

// Binary Tree / BST Node Structure
struct Node {
   int data;
   Node* left;
   Node* right;

   Node(int val) {
       data = val;
       left = NULL;
       right = NULL;
   }
};

// =================================================================
// 1. TRAVERSALS (Pre-Order, In-Order, Post-Order)
// =================================================================
void preOrder(Node* root) {
   if (root == NULL) return;
   cout << root->data << " ";
   preOrder(root->left);
   preOrder(root->right);
}

void inOrder(Node* root) {
   if (root == NULL) return;
   inOrder(root->left);
   cout << root->data << " ";
   inOrder(root->right);
}

void postOrder(Node* root) {
   if (root == NULL) return;
   postOrder(root->left);
   postOrder(root->right);
   cout << root->data << " ";
}

// =================================================================
// 2. TREE STATS (Height, Total Nodes, Leaf Nodes, Sum)
// =================================================================
int treeHeight(Node* root) {
   if (root == NULL) return 0;
   int leftH = treeHeight(root->left);
   int rightH = treeHeight(root->right);
   if (leftH > rightH)
       return leftH + 1;
   else 
       return rightH + 1;
}  

int countNodes(Node* root) {
   if (root == NULL) return 0;
   return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeafNodes(Node* root) {
   if (root == NULL) return 0;
   if (root->left == NULL && root->right == NULL) return 1;
   return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int sumOfTree(Node* root) {
   if (root == NULL) return 0;
   return root->data + sumOfTree(root->left) + sumOfTree(root->right);
}

// =================================================================
// EXTRA ESSENTIAL STATS (Fixed: Added Missing Functions)
// =================================================================
int sumLeafNodes(Node* root) {
   if (root == NULL) return 0;
   if (root->left == NULL && root->right == NULL) return root->data;
   return sumLeafNodes(root->left) + sumLeafNodes(root->right);
}

int sumParentNodes(Node* root) {
   if (root == NULL) return 0;
   if (root->left == NULL && root->right == NULL) return 0; // Leaf node skip karo
   return root->data + sumParentNodes(root->left) + sumParentNodes(root->right);
}

int countOneChildNodes(Node* root) {
   if (root == NULL) return 0;
   if ((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL)) {
       return 1 + countOneChildNodes(root->left) + countOneChildNodes(root->right);
   }
   return countOneChildNodes(root->left) + countOneChildNodes(root->right);
}

// =================================================================
// 3. TREE OPERATIONS (Mirror & Identical Check)
// =================================================================
void mirrorTree(Node* root) {
   if (root == NULL) return;
   mirrorTree(root->left);
   mirrorTree(root->right);
   Node* temp = root->left;
   root->left = root->right;
   root->right = temp;
}

bool isIdentical(Node* root1, Node* root2) {
   if (root1 == NULL && root2 == NULL) return true;
   if (root1 == NULL || root2 == NULL) return false;
   if (root1->data != root2->data) return false;
   return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
}

// =================================================================
// 4. BALANCE CHECK (Without cmath)
// =================================================================
int checkBalancedHelper(Node* root) {
   if (root == NULL) return 0;
   int leftH = checkBalancedHelper(root->left);
   if (leftH == -1) return -1;
   int rightH = checkBalancedHelper(root->right);
   if (rightH == -1) return -1;

   int diff = leftH - rightH;
   if (diff < 0) diff = -diff;
   if (diff > 1) return -1;

   if (leftH > rightH) return leftH + 1;
   else return rightH + 1;
}

bool isBalanced(Node* root) {
   return checkBalancedHelper(root) != -1;
}

// =================================================================
// 5. BST CORE: SEARCH, MINIMUM, INSERTION, DELETION
// =================================================================
bool searchBST(Node* root, int target) {
   if (root == NULL) return false;
   if (root->data == target) return true;

   if (target < root->data) return searchBST(root->left, target);
   return searchBST(root->right, target);
}

Node* findMin(Node* root) {
   if (root == NULL) return NULL;
   if (root->left == NULL) return root;
   return findMin(root->left);
}

Node* insertIntoBST(Node* root, int val) {
   if (root == NULL) return new Node(val);
   if (val < root->data) root->left = insertIntoBST(root->left, val);
   else if (val > root->data) root->right = insertIntoBST(root->right, val);
   return root;
}

Node* createBSTFromUnsortedArray(int arr[], int n) {
   if (n == 0) return NULL;
   Node* root = NULL;
   for (int i = 0; i < n; i++) root = insertIntoBST(root, arr[i]);
   return root;
}

Node* deleteNode(Node* root, int key) {
   if (root == NULL) return NULL;

   if (key < root->data) {
       root->left = deleteNode(root->left, key);
   }
   else if (key > root->data) {
       root->right = deleteNode(root->right, key);
   }
   else {
       if (root->left == NULL) {
           Node* temp = root->right;
           delete root;
           return temp;
       }
       else if (root->right == NULL) {
           Node* temp = root->left;
           delete root;
           return temp;
       }

       Node* temp = findMin(root->right);
       root->data = temp->data;
       root->right = deleteNode(root->right, temp->data);
   }
   return root;
}

// =================================================================
// 6. FIND 1st, 2nd, AND 3rd MAXIMUM ELEMENTS
// =================================================================
void findTopThreeMaxHelper(Node* root, int& first, int& second, int& third) {
   if (root == NULL) return;
   findTopThreeMaxHelper(root->right, first, second, third);

   if (root->data > first) {
       third = second;
       second = first;
       first = root->data;
   }
   else if (root->data > second && root->data != first) {
       third = second;
       second = root->data;
   }
   else if (root->data > third && root->data != first && root->data != second) {
       third = root->data;
   }

   findTopThreeMaxHelper(root->left, first, second, third);
}

void printTopThreeMax(Node* root) {
   int first = -999999;
   int second = -999999;
   int third = -999999;
   findTopThreeMaxHelper(root, first, second, third);

   cout << "1st Maximum (Largest): " << first << endl;
   if (second != -999999) cout << "2nd Maximum: " << second << endl;
   if (third != -999999) cout << "3rd Maximum: " << third << endl;
}
void findKthLargestHelper(Node* root, int k, int& count, int& result) {
if (root == NULL || count >= k) {
   return;
}

// 1. Pehle RIGHT subtree par jao (Kyunki bade elements right par hote hain)
findKthLargestHelper(root->right, k, count, result);

// 2. Ab ROOT (Current Node) par kaam karo
count++; // Ek bada element visit ho gaya
if (count == k) {
   result = root->data; // Element mil gaya!
   return;
}

// 3. Phir LEFT subtree par jao (Chote elements ki taraf)
findKthLargestHelper(root->left, k, count, result);
}

int kthLargest(Node* root, int k) {
   int count = 0;
   int result = -1;

   findKthLargestHelper(root, k, count, result);

   return result;
}

// =================================================================
// 7. PALINDROME & UTILITIES
// =================================================================
void storeInOrder(Node* root, int arr[], int& index) {
   if (root == NULL) return;
   storeInOrder(root->left, arr, index);
   arr[index] = root->data;
   index++;
   storeInOrder(root->right, arr, index);
}

bool isBSTPalindrome(Node* root, int totalNodes) {
   if (root == NULL) return true;

   int* tempArr = new int[totalNodes];
   int index = 0;
   storeInOrder(root, tempArr, index);

   int start = 0;
   int end = totalNodes - 1;
   bool palindromeFlag = true;

   while (start < end) {
       if (tempArr[start] != tempArr[end]) {
           palindromeFlag = false;
           break;
       }
       start++;
       end--;
   }

   delete[] tempArr;
   return palindromeFlag;
}

int countNodesGreaterThanX(Node* root, int x) {
   if (root == NULL) return 0;
   if (root->data > x) {
       return 1 + countNodesGreaterThanX(root->left, x) + countNodesGreaterThanX(root->right, x);
   }
   return countNodesGreaterThanX(root->left, x) + countNodesGreaterThanX(root->right, x);
}

bool isStrictBinaryTree(Node* root) {
   if (root == NULL) return true;
   if (root->left == NULL && root->right == NULL) return true;
   if (root->left != NULL && root->right != NULL) {
       return isStrictBinaryTree(root->left) && isStrictBinaryTree(root->right);
   }
   return false;
}

// =================================================================
// MAIN FUNCTION
// =================================================================
int main() {
   int myUnsortedArr[] = { 40, 20, 10, 35, 85, 70, 90, 55, 100 };
   int n = sizeof(myUnsortedArr) / sizeof(myUnsortedArr[0]);

   cout << "--- Creating BST from Unsorted Array ---" << endl;
   Node* root = createBSTFromUnsortedArray(myUnsortedArr, n);

   cout << "\n--- Traversals ---" << endl;
   cout << "In-Order (Sorted): "; inOrder(root); cout << endl;
   cout << "Pre-Order:         "; preOrder(root); cout << endl;
   cout << "Post-Order:        "; postOrder(root); cout << endl;

   cout << "\n--- Testing Search ---" << endl;
   cout << "Searching for 35: " << (searchBST(root, 35) ? "Found" : "Not Found") << endl;
   cout << "Searching for 99: " << (searchBST(root, 99) ? "Found" : "Not Found") << endl;

   cout << "\n--- Stats Before Deletion ---" << endl;
   cout << "Total Nodes:      " << countNodes(root) << endl;
   cout << "Height of Tree:   " << treeHeight(root) << endl;
   cout << "Is Tree Balanced? " << (isBalanced(root) ? "Yes" : "No") << endl;
   printTopThreeMax(root);

   cout << "\n--- Advanced Stats ---" << endl;
   cout << "Sum of Leaf Nodes:          " << sumLeafNodes(root) << endl;
   cout << "Sum of Parent Nodes:        " << sumParentNodes(root) << endl;
   cout << "Sum of Entire Tree:         " << sumOfTree(root) << endl;
   cout << "Total Leaf Nodes Count:     " << countLeafNodes(root) << endl;
   cout << "Nodes with exactly 1 Child: " << countOneChildNodes(root) << endl;
   cout << "Is this a Strict Binary Tree? " << (isStrictBinaryTree(root) ? "Yes" : "No") << endl;

   int x = 50;
   cout << "Nodes Greater than " << x << ":     " << countNodesGreaterThanX(root, x) << endl;
   cout << "Is this BST a Palindrome?   " << (isBSTPalindrome(root, countNodes(root)) ? "Yes" : "No") << endl;

   // --- TEST: IDENTICAL TREE CHECK ---
   cout << "\n--- Testing Identical Tree Logic ---" << endl;
   Node* root2 = createBSTFromUnsortedArray(myUnsortedArr, n);
   cout << "Is Tree1 Identical to Tree2? " << (isIdentical(root, root2) ? "Yes" : "No") << endl;

   // --- TEST: DELETION ---
   cout << "\n--- Deleting Node 85 (Node with 2 children) ---" << endl;
   root = deleteNode(root, 85);

   cout << "In-Order after deletion: "; inOrder(root); cout << endl;
   cout << "Total Nodes now:         " << countNodes(root) << endl;

   // --- TEST: MIRROR TREE ---
   cout << "\n--- Mirroring the Tree ---" << endl;
   mirrorTree(root);
   cout << "In-Order after Mirror (Should be reversed): "; inOrder(root); cout << endl;

   return 0;
}