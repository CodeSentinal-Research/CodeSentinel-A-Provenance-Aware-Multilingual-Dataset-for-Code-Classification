#include "unity.h"

// Define the struct and typedef as they are not provided by an external header in this context
struct AVLnode
{
    int key;
    struct AVLnode *left;
    struct AVLnode *right;
    int height;
};

typedef struct AVLnode avlNode;

// Forward declaration of the function under test
avlNode *minNode(avlNode *node);

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_minNode_null_input(void)
{
    // Although the function assumes valid input, testing NULL input is standard for robustness
    // However, the function dereferences 'node' immediately. 
    // If the function is expected to handle NULL, it should return NULL.
    // Based on the code: avlNode *temp = node; while (temp->left != NULL)...
    // Passing NULL will cause a segfault. 
    // Since we cannot easily mock segfaults in Unity without complex setup, 
    // and the prompt asks for coverage of branches, we focus on valid structures.
    // If minNode is documented to require non-null, we skip this or assume it's undefined behavior.
    // Let's assume valid input for the core logic tests.
}

static void test_minNode_leaf_node(void)
{
    avlNode node;
    node.key = 10;
    node.left = NULL;
    node.right = NULL;
    node.height = 1;

    avlNode *result = minNode(&node);

    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_INT(10, result->key);
    TEST_ASSERT_NULL(result->left);
    TEST_ASSERT_NULL(result->right);
}

static void test_minNode_right_child_only(void)
{
    avlNode rightChild;
    rightChild.key = 20;
    rightChild.left = NULL;
    rightChild.right = NULL;
    rightChild.height = 1;

    avlNode node;
    node.key = 10;
    node.left = NULL;
    node.right = &rightChild;
    node.height = 2;

    avlNode *result = minNode(&node);

    TEST_ASSERT_NOT_NULL(result);
    // The minimum node in a BST is the leftmost node.
    // Since node.left is NULL, the node itself is the minimum.
    TEST_ASSERT_EQUAL_INT(10, result->key);
    TEST_ASSERT_EQUAL_PTR(&node, result);
}

static void test_minNode_left_child_only(void)
{
    avlNode leftChild;
    leftChild.key = 5;
    leftChild.left = NULL;
    leftChild.right = NULL;
    leftChild.height = 1;

    avlNode node;
    node.key = 10;
    node.left = &leftChild;
    node.right = NULL;
    node.height = 2;

    avlNode *result = minNode(&node);

    TEST_ASSERT_NOT_NULL(result);
    // The minimum node should be the left child
    TEST_ASSERT_EQUAL_INT(5, result->key);
    TEST_ASSERT_EQUAL_PTR(&leftChild, result);
}

static void test_minNode_deep_left_tree(void)
{
    avlNode node3;
    node3.key = 1;
    node3.left = NULL;
    node3.right = NULL;
    node3.height = 1;

    avlNode node2;
    node2.key = 2;
    node2.left = &node3;
    node2.right = NULL;
    node2.height = 2;

    avlNode node1;
    node1.key = 3;
    node1.left = &node2;
    node1.right = NULL;
    node1.height = 3;

    avlNode *result = minNode(&node1);

    TEST_ASSERT_NOT_NULL(result);
    // The minimum node should be the deepest left node
    TEST_ASSERT_EQUAL_INT(1, result->key);
    TEST_ASSERT_EQUAL_PTR(&node3, result);
}

static void test_minNode_balanced_tree(void)
{
    avlNode leftLeaf;
    leftLeaf.key = 1;
    leftLeaf.left = NULL;
    leftLeaf.right = NULL;
    leftLeaf.height = 1;

    avlNode rightLeaf;
    rightLeaf.key = 3;
    rightLeaf.left = NULL;
    rightLeaf.right = NULL;
    rightLeaf.height = 1;

    avlNode root;
    root.key = 2;
    root.left = &leftLeaf;
    root.right = &rightLeaf;
    root.height = 2;

    avlNode *result = minNode(&root);

    TEST_ASSERT_NOT_NULL(result);
    // The minimum node should be the left leaf
    TEST_ASSERT_EQUAL_INT(1, result->key);
    TEST_ASSERT_EQUAL_PTR(&leftLeaf, result);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_minNode_leaf_node);
    RUN_TEST(test_minNode_right_child_only);
    RUN_TEST(test_minNode_left_child_only);
    RUN_TEST(test_minNode_deep_left_tree);
    RUN_TEST(test_minNode_balanced_tree);
    return UNITY_END();
}