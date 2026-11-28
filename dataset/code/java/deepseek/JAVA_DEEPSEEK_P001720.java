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

    static void inorder(Node node, int level, int[] levels) {
        if (node == null)
            return;

        inorder(node.left, level + 1, levels);

        if (level >= levels.length) {
            levels = Arrays.copyOf(levels, level + 1);
        }
        levels[level] = levels[level] + node.data;

        inorder(node.right, level + 1, levels);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] values = new int[n];
        for (int i = 0; i < n; i++) {
            values[i] = scanner.nextInt();
        }

        root = new Node(values[0]);
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);

        int i = 1;
        while (!queue.isEmpty() && i < n) {
            Node tempNode = queue.poll();

            if (values[i] != -1) {
                tempNode.left = new Node(values[i]);
                queue.add(tempNode.left);
            }
            i++;

            if (i < n && values[i] != -1) {
                tempNode.right = new Node(values[i]);
                queue.add(tempNode.right);
            }
            i++;
        }

        int[] levels = new int[n];
        inorder(root, 0, levels);
        System.out.println(levels[n - 1]);
    }
}
