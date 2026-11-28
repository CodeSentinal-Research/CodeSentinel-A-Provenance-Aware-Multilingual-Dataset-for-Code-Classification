// ******************ERRORS********************************
// Throws UnderflowException as appropriate

import java.util.ArrayList;

class UnderflowException extends RuntimeException {
    /**
     * Construct this exception object.
     *
     * @param message the error message.
     */
    public UnderflowException(String message) {
        super(message);
    }
}

public class Tree {
    private BinaryNode root;  // Root of tree
    private String treeName;     // Name of tree

    /**
     * Create an empty tree
     * @param label Name of tree
     */
    public Tree(String label) {
        treeName = label;
        root = null;
    }

    /**
     * Create tree from list
     * @param arr   List of elements
     * @param label Name of tree
     * @ordered true if we want an ordered tree
     */
    public Tree(Integer[] arr, String label, boolean ordered) {
        treeName = label;
        if (ordered) {
            root = null;
            for (int i = 0; i < arr.length; i++) {
                bstInsert(arr[i]);
            }
        } else root = buildUnordered(arr, 0, arr.length - 1);
    }


    /**
     * Build a NON BST tree by inorder
     * @param arr nodes to be added
     * @return new tree
     */
    private BinaryNode buildUnordered(Integer[] arr, int low, int high) {
        if (low > high) return null;
        int mid = (low + high) / 2;
        BinaryNode curr = new BinaryNode(arr[mid], null, null);
        curr.left = buildUnordered(arr, low, mid - 1);
        curr.right = buildUnordered(arr, mid + 1, high);
        return curr;
    }


    /**
     * Change name of tree
     * @param name new name of tree
     */
    public void changeName(String name) {
        this.treeName = name;
    }

    /**
     * Return a string displaying the tree contents as a single line
     * runs in O(n)
     */
    public String toString() {
        if (root == null)
            return treeName + " Empty tree";
        else

            return treeName + "\n" + toString(root, "");
    }

    public String toString(BinaryNode t, String indent){
        if (t == null) return "";

        String node = "";
        node += toString(t.right, indent + "  ");
        node += indent + t.element.toString() + "\n";
        node += toString(t.left, indent + "  ");
        return node;
    }
    /**
     * Return a string displaying the tree contents as a single line
     */
    public String toString2() {
        if (root == null)
            return treeName + " Empty tree";
        else
            return treeName + " " + toString2(root);
    }

    /**
     * Internal method to return a string of items in the tree in order
     * This routine runs in O(n)
     *
     * @param t the node that roots the subtree.
     */
    public String toString2(BinaryNode t) {
        if (t == null) return "";
        StringBuilder sb = new StringBuilder();
        sb.append(toString2(t.left));
        sb.append(t.element.toString() + " ");
        sb.append(toString2(t.right));
        return sb.toString();
    }


    /**
     * The complexity of finding the deepest node is O(n)
     * @return
     */
    public Integer deepestNode() {
        return deepestNode(root, 0).value;
    }

    private DeepestLevel deepestNode(BinaryNode t, int level) {
        if (t == null) {
            return new DeepestLevel(level - 1, null);
        }
        if (t.left == null && t.right == null) {
            return new DeepestLevel(level, t.element);
        }
        DeepestLevel deepestLevel;

        DeepestLevel left = deepestNode(t.left, level + 1);
        DeepestLevel right = deepestNode(t.right, level + 1);

        if (left.level > right.level) {
            deepestLevel = left;
        } else {
            deepestLevel = right;
        }

        return deepestLevel;
    }


    private static class DeepestLevel {
        Integer value;
        Integer level;

        private DeepestLevel(Integer level, Integer value) {
            this.level = level;
            this.value = value;
        }

    }

    /**
     * The complexity of finding the flip is O(n)
     * reverse left and right children recursively
     */
    public void flip() {
        flip(root);
    }

    private void flip(BinaryNode t){

        if (t == null) {
            return;
        }

        flip(t.left);
        flip(t.right);

        BinaryNode left = t.left;
        t.left = t.right;
        t.right = left;
    }

    /**
     * Counts number of nodes in specified level
     * The complexity of nodesInLevel is O(n)
     * @param level Level in tree, root is zero
     * @return count of number of nodes at specified level
     */
    public int nodesInLevel(int level) {

        return nodesInLevel(root, level, 0);
    }

    public int nodesInLevel(BinaryNode n, int level, int currLevel) {
        if (n == null) {
            return 0;
        }
        if (level == currLevel) {
            return 1;
        }
        int left = nodesInLevel(n.left, level, currLevel + 1);
        int right = nodesInLevel(n.right, level, currLevel + 1);

        return left + right;
    }

    /**
     * Print all paths from root to leaves
     * The complexity of printAllPaths is O(n log n)
     */
    public void printAllPaths() {
        printAllPaths(root, "");
    }

    public void printAllPaths(BinaryNode n, String path) {
        if (n == null) {
            return;
        }
        path += n.element.toString() + " ";
        if (n.left == null && n.right == null) {
            System.out.println(path);
        }

        printAllPaths(n.left, path);
        printAllPaths(n.right, path);
    }


    /**
     * Counts all non-null binary search trees embedded in tree
     *  The complexity of countBST is O(n^2)
     * @return Count of embedded binary search trees
     */
    public Integer countBST() {
        if (root == null) return 0;
        return countBST(root);
    }

    public Integer  countBST(BinaryNode n) {
        if (n == null) {
            return 0;
        }
        int level = 0;

        if (isBST(n, Integer.MIN_VALUE, Integer.MAX_VALUE)) {
            level = 1;
        }

        int countLeft = countBST(n.left);
        int countRight = countBST(n.right);

        return countLeft + countRight + level;
    }

    /**
     * Check if the node is a bst to count it above
     *
     * @param n node
     * @param min minimum value to check
     * @param max maximum value to check
     * @return if node is a BST from node - below
     */
    public boolean isBST(BinaryNode n, int min, int max) {
        if (n == null) {
            return true;
        }
        if (n.element < min || n.element > max) {
            return false;
        }

        return isBST(n.left, min, n.element) && isBST(n.right, n.element, max);
    }


    /**
     * Insert into a bst tree; duplicates are allowed
     * The complexity of bstInsert depends on the tree.  If it is balanced the complexity is O(log n)
     * @param x the item to insert.
     */
    public void bstInsert(Integer x) {

        root = bstInsert(x, root);
    }

    /**
     * Internal method to insert into a subtree.
     * In tree is balanced, this routine runs in O(log n)
     * @param x the item to insert.
     * @param t the node that roots the subtree.
     * @return the new root of the subtree.
     */
    private BinaryNode bstInsert(Integer x, BinaryNode t) {
        if (t == null)
            return new BinaryNode (x, null, null);
        int compareResult = x.compareTo(t.element);
        if (compareResult < 0) {
            t.left = bstInsert(x, t.left);
        } else {
            t.right = bstInsert(x, t.right);
        }
        return t;
    }

    /**
     * Determines if item is in tree
     * @param item the item to search for.
     * @return true if found.
     */
    public boolean contains(Integer item) {
        return contains(item, root);
    }

    /**
     * Internal method to find an item in a subtree.
     * This routine runs in O(log n) as there is only one recursive call that is executed and the work
     * associated with a single call is independent of the size of the tree: a=1, b=2, k=0
     *
     * @param x is item to search for.
     * @param t the node that roots the subtree.
     * @return node containing the matched item.
     */
    private boolean contains(Integer x, BinaryNode t) {
        if (t == null)
            return false;

        int compareResult = x.compareTo(t.element);

        if (compareResult < 0)
            return contains(x, t.left);
        else if (compareResult > 0)
            return contains(x, t.right);
        else {
            return true;    // Match
        }
    }
    /**
     * Remove all paths from tree that sum to less than given value
     * @param sum: minimum path sum allowed in final tree
     */
    public void pruneK(Integer sum) {
        pruneK(root, sum, 0);
    }

    public boolean pruneK(BinaryNode n, Integer sum, Integer total) {
        if (n == null) {
            return false;
        }

        total += n.element;

        boolean keepLeft = pruneK(n.left, sum, total);
        boolean keepRight = pruneK(n.right, sum, total);

        if (!keepLeft) {
            n.left = null;
        }
        if (!keepRight) {
            n.right = null;
        }
        if (n.left == null && n.right == null) {
            return total >= sum;
        }
        return true;
    }

    /**
     * Build tree given inOrder and preOrder traversals.  Each value is unique
     * @param inOrder  List of tree nodes in inorder
     * @param preOrder List of tree nodes in preorder
     */
    public void buildTreeFromTraversals(Integer[] inOrder, Integer[] preOrder) {
        root = null;
    }

    /**
     * Find the least common ancestor of two nodes
     * @param a first node
     * @param b second node
     * @return String representation of ancestor
     */
    public BinaryNode lca(BinaryNode  n, Integer a, Integer b) {
        if (n == null) return null;

        if (a > n.element && b> n.element) {
            return lca(n.right, a, b);
        }
        if (a < n.element && b < n.element) {
            return lca(n.left, a, b);
        }

        return n;
    }

    public Integer sumAll(){
        BinaryNode  r =   root;
        return sumAll(r);
    }
    public Integer sumAll(BinaryNode  t){
        if (t==null) return 0;
        return t.element + sumAll(t.left) + sumAll(t.right);
    }

    public Integer lca(Integer a, Integer b) {

        if (!contains(a) || !contains(b)) {
            return null;
        }

         BinaryNode n = lca(root,a,b);

         if ( n==null ) return null;

         return n.element;

    }
    /**
     * Balance the tree
     */
    public void balanceTree() {
        ArrayList<Integer> treeList = new ArrayList<>();
        getTree(root, treeList);

        root = balanceTree(treeList, 0, treeList.size() - 1);
    }

    /**
     * Create a list of the tree
     *
     * @param n starting binary node
     * @param tree list of the tree
     */
    private void getTree(BinaryNode n, ArrayList<Integer> tree) {
        if (n == null) {
            return;
        }
        getTree(n.left, tree);
        tree.add(n.element);
        getTree(n.right, tree);
    }

    private BinaryNode balanceTree(ArrayList<Integer> tree, int start, int end) {
        if (start > end) {
            return null;
        }
        int mid = (start + end) / 2;
        BinaryNode node = new BinaryNode(tree.get(mid));

        node.left = balanceTree(tree, start, mid - 1);
        node.right = balanceTree(tree, mid + 1, end);

        return node;
    }

    /**
     * In a BST, keep only nodes between range
     *
     * @param a lowest value
     * @param b highest value
     */
    public void keepRange(Integer a, Integer b) {
        root = keepRange(root, a, b);
    }

    public BinaryNode keepRange(BinaryNode n, Integer min, Integer max) {
        if (n == null) {
            return null;
        }
        if (n.element < min) {
            return keepRange(n.right, min, max);
        }

        if (n.element > max) {
            return keepRange(n.left, min, max);
        }

        n.left = keepRange(n.left, min, max);
        n.right = keepRange(n.right, min, max);
        return n;
    }

    // Basic node stored in unbalanced binary  trees
    public static class BinaryNode  {
        Integer element;            // The data in the node
        BinaryNode left;   // Left child
        BinaryNode  right;  // Right child

        // Constructors
        BinaryNode(Integer theElement) {
            this(theElement, null, null);
        }

        BinaryNode(Integer theElement, BinaryNode lt, BinaryNode rt) {
            element = theElement;
            left = lt;
            right = rt;
        }

        // toString for BinaryNode
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append("Node:");
            sb.append(element);
            return sb.toString();
        }

    }


}
