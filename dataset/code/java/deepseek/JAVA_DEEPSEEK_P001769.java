import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        String[] values = new String[n];
        for (int i = 0; i < n; i++) {
            values[i] = scanner.next();
        }
        scanner.close();

        Node root = buildTree(values);
        List<Integer> minValues = new ArrayList<>();
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            int size = queue.size();
            int min = Integer.MAX_VALUE;
            for (int i = 0; i < size; i++) {
                Node node = queue.poll();
                min = Math.min(min, node.value);
                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
            }
            minValues.add(min);
        }

        for (int value : minValues) {
            System.out.println(value);
        }
    }

    private static Node buildTree(String[] values) {
        Node[] nodes = new Node[values.length];
        for (int i = 0; i < values.length; i++) {
            nodes[i] = new Node(Integer.parseInt(values[i]));
        }
        for (int i = 0; i < values.length; i++) {
            if (2 * i + 1 < values.length) {
                nodes[i].left = nodes[2 * i + 1];
            }
            if (2 * i + 2 < values.length) {
                nodes[i].right = nodes[2 * i + 2];
            }
        }
        return nodes[0];
    }

    static class Node {
        int value;
        Node left;
        Node right;

        Node(int value) {
            this.value = value;
        }
    }
}
