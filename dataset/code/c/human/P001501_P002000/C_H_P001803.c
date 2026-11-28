/*******************************************************************************
 * B-TREE LIBRARY - HEADER FILE
 * 
 * This header defines the interface for a complete B-Tree implementation.
 * A B-Tree is a self-balancing search tree that generalizes the binary search 
 * tree by allowing nodes with more than two children. They are heavily used 
 * in databases and file systems due to their ability to minimize disk I/O.
 * 
 * KEY CONCEPTS & RULES TO REMEMBER:
 * 
 * 1. THE MINIMUM DEGREE (t)
 *    Every B-Tree has a parameter 't' (min_degree) >= 2.
 *    It dictates the capacity limits of EVERY node (except the root):
 *    - Minimum keys per node:  t - 1
 *    - Maximum keys per node:  2t - 1
 *    - Minimum children:       t      (internal nodes only)
 *    - Maximum children:       2t     (internal nodes only)
 * 
 * 2. STRUCTURAL PROPERTIES
 *    - All leaves are at the exact same depth (the tree is perfectly balanced perfectly).
 *    - Keys within a node are stored in strictly increasing order.
 *    - For an internal node, the key separates the subtrees:
 *        child_1 < key_1 < child_2 < key_2 < child_3
 * 
 * 3. MEMORIZATION TRIGGERS (For Exams)
 *    "Full means 2t-1." -> Split it BEFORE descending into it!
 *    "Deficient means t-2." -> Steal/merge when you come back up (or prepare going down).
 *    "Split brings one key up." -> The median key (index t-1) moves up to the parent.
 *    "Merge brings one key down." -> The separator key from parent joins the two children.
 * 
 * TIME COMPLEXITY:
 * - Search: O(log_t N) disk accesses, O(t log_t N) CPU comparisons
 * - Insert: O(log_t N) disk accesses
 * - Delete: O(log_t N) disk accesses
 * 
 * DIFFERENCES BETWEEN VERSIONS:
 * - b_tree_simple.c:    Uses explicit shifting (loops), modular functions, HIGHLY commented.
 * - b_tree_optimized.c: Uses memcpy/memmove for block shifts, fewer loops.
 ******************************************************************************/

#ifndef B_TREE_H
#define B_TREE_H

#include <stdio.h>
#include <stdlib.h>

/*******************************************************************************
 * DATA STRUCTURES
 ******************************************************************************/

/**
 * BTreeNode Structure
 * 
 * Represents a single node in the B-Tree space.
 * 
 * Visual Representation of a Node (t=3):
 * 
 *    Max capacity: 2t-1 = 5 keys, 2t = 6 children
 * 
 *      val1   val2   val3   ---    ---
 *    ┌──────┬──────┬──────┬──────┬──────┐
 *    │  10  │  20  │  30  │      │      │   <-- keys array (size 5)
 *    └──────┴──────┴──────┴──────┴──────┘
 *    |      |      |      |      |      |
 *   C0     C1     C2     C3     C4     C5   <-- children pointers (size 6)
 * 
 * Notice that child 0 holds values < 10.
 * Child 1 holds values between 10 and 20.
 * Child 2 holds values between 20 and 30.
 * Child 3 holds values > 30.
 */
typedef struct BTreeNode {
    int  min_degree;
    int  num_keys;
    int  is_leaf;
    int* keys;
    struct BTreeNode** children;
} BTreeNode;


/**
 * BTree Structure
 * 
 * A simple wrapper to hold the root pointer and the degree mapping.
 */
typedef struct {
    int        min_degree;
    BTreeNode* root;
} BTree;


/*******************************************************************************
 * CORE FUNCTIONS - Creation and Utility
 ******************************************************************************/

/**
 * Create a new B-Tree
 * 
 * @param min_degree The minimal degree 't' (must be >= 2)
 * @return Initialized BTree structure
 */
BTree* createBTree(int min_degree);

/**
 * Free the memory allocated for the B-Tree
 * 
 * Runs a recursive destruction across all branches.
 * 
 * @param tree Pointer to the BTree
 */
void freeBTree(BTree* tree);

/**
 * Print the B-Tree keys in-order (Ascending sequence)
 * 
 * Useful for validating the Structural Property
 * 
 * @param node Starting node (usually tree->root)
 */
void traverseBTree(BTreeNode* node);

/**
 * Get the exact node and index containing a given key 
 * 
 * Evaluates in log(t) N time. Returning NULL if missing.
 * 
 * @param node Starting node (usually tree->root)
 * @param key The target integer seeking
 * @return The Node containing the key, or NULL
 */
BTreeNode* searchKey(BTreeNode* node, int key);


/*******************************************************************************
 * PRIMARY MUTATIONS
 ******************************************************************************/

/**
 * Insert a key into the B-Tree
 * 
 * Follows the "Proactive Split" approach. 
 * If a node is full on the way down, it splits it, ensuring that we never
 * violate capacity limits.
 * 
 * @param tree Pointer to the B-Tree
 * @param key The integer to insert
 */
void insertKey(BTree* tree, int key);

/**
 * Delete a key from the B-Tree
 * 
 * Uses the complex standard deletion algorithm.
 * Guarantees properties are maintained after deletion (shrinking naturally).
 * 
 * @param tree Pointer to the B-Tree
 * @param key The integer to delete
 */
void deleteKey(BTree* tree, int key);

#endif // B_TREE_H
