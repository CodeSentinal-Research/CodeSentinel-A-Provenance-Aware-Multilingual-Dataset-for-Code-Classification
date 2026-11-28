import java.util.HashMap;
import java.util.Map;

class Node {
    int val;
    Node left, right, random;
    Node(int val) { this.val = val; }
}

public class Solution {
    private Map<Node, Node> cloned = new HashMap<>();

    private Node cloneStructure(Node node) {
        if (node == null) return null;
        Node copy = new Node(node.val);
        cloned.put(node, copy);
        copy.left = cloneStructure(node.left);
        copy.right = cloneStructure(node.right);
        return copy;
    }

    private void connectRandom(Node node) {
        if (node == null) return;
        if (node.random != null) {
            cloned.get(node).random = cloned.get(node.random);
        }
        connectRandom(node.left);
        connectRandom(node.right);
    }

    public Node copyRandomBinaryTree(Node root) {
        if (root == null) return null;
        cloned.clear();
        Node newRoot = cloneStructure(root);
        connectRandom(root);
        return newRoot;
    }
}