import java.util.*;

public class Main {
    static class Node {
        int data;
        Node left, right;

        Node(int item) {
            data = item;
            left = right = null;
        }
    }

    static Node root;
    static Map<Integer, Integer> countMap = new HashMap<>();

    static int countNodes(Node node) {
        if (node == null)
            return 0;

        int left = countNodes(node.left);
        int right = countNodes(node.right);

        int count = left + right;
        countMap.put(count, countMap.getOrDefault(count, 0) + 1);

        return count + 1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        root = new Node(1);
        for (int i = 1; i < n; i++) {
            int parent = scanner.nextInt();
            char childType = scanner.next().charAt(0);
            int childValue = scanner.nextInt();

            Node parentNode = findNode(root, parent);
            if (childType == 'L') {
                parentNode.left = new Node(childValue);
            } else {
                parentNode.right = new Node(childValue);
            }
        }

        int k = scanner.nextInt();
        countNodes(root);
        System.out.println(countMap.getOrDefault(k, 0));
    }

    static Node findNode(Node node, int value) {
        if (node == null)
            return null;
        if (node.data == value)
            return node;

        Node foundNode = findNode(node.left, value);
        if (foundNode != null)
            return foundNode;

        return findNode(node.right, value);
    }
}
