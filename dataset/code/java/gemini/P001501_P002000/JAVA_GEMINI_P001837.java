import java.util.Stack;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class BSTReverseIterator {
    private Stack<TreeNode> stack = new Stack<>();

    private void pushRight(TreeNode node) {
        while (node != null) {
            stack.push(node);
            node = node.right;
        }
    }

    public BSTReverseIterator(TreeNode root) {
        pushRight(root);
    }

    public int next() {
        TreeNode node = stack.pop();
        pushRight(node.left);
        return node.val;
    }

    public boolean hasNext() {
        return !stack.isEmpty();
    }
}