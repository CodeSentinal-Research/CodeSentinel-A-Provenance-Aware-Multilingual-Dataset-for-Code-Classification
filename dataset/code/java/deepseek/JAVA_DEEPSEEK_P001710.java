import java.util.*;

public class Main {
    class Node {
        int data;
        Node left, right, random;
        Node(int data) {
            this.data = data;
            left = right = random = null;
        }
    }

    Map<Node, Node> map = new HashMap<>();

    Node clone(Node root) {
        if (root == null) return null;
        if (map.containsKey(root)) return map.get(root);
        Node clone = new Node(root.data);
        map.put(root, clone);
        clone.left = clone(root.left);
        clone.right = clone(root.right);
        clone.random = clone(root.random);
        return clone;
    }
}
