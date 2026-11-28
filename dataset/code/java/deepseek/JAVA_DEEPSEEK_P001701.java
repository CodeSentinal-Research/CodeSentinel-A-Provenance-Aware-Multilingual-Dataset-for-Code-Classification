import java.util.*;

public class Main {
    static class Node {
        int val;
        Node left;
        Node right;
        Node parent;

        Node(int val) {
            this.val = val;
        }
    }

    static Node root;
    static Map<Node, Node> parentMap = new HashMap<>();
    static Map<Node, List<Node>> levelMap = new HashMap<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] values = new int[n];
        for (int i = 0; i < n; i++) {
            values[i] = sc.nextInt();
        }
        root = new Node(0);
        parentMap.put(root, null);
        levelMap.put(root, new ArrayList<>());
        for (int i = 0; i < n; i++) {
            Node parent = levelMap.get(root).isEmpty() ? root : levelMap.get(root).get(0);
            Node child = new Node(values[i]);
            if (parent.left == null) {
                parent.left = child;
            } else {
                parent.right = child;
            }
            levelMap.get(root).add(child);
            parentMap.put(child, parent);
            levelMap.put(child, new ArrayList<>());
        }
        replaceValues(root);
        inorderTraversal(root);
    }

    public static void replaceValues(Node node) {
        if (node == null) {
            return;
        }
        Node parent = parentMap.get(node);
        Node grandParent = parentMap.get(parent);
        List<Node> siblings = levelMap.get(grandParent);
        siblings.remove(parent);
        int sum = 0;
        for (Node sibling : siblings) {
            sum += sibling.val;
        }
        node.val = sum;
        replaceValues(node.left);
        replaceValues(node.right);
    }

    public static void inorderTraversal(Node node) {
        if (node == null) {
            return;
        }
        inorderTraversal(node.left);
        System.out.print(node.val + " ");
        inorderTraversal(node.right);
    }
}
