import java.util.*;

public class Main {
    static class Node {
        int val;
        Node left;
        Node right;
        Node(int val) {
            this.val = val;
        }
    }

    static Node buildTree(String[] nodes) {
        Node[] nodeList = new Node[nodes.length];
        for (int i = 0; i < nodes.length; i++) {
            if (nodes[i].equals("null")) {
                nodeList[i] = null;
            } else {
                nodeList[i] = new Node(Integer.parseInt(nodes[i]));
           
            }
        }
        for (int i = 0; i < nodes.length; i++) {
            if (nodeList[i] != null) {
                if (2 * i + 1 < nodes.length) {
                    nodeList[i].left = nodeList[2 * i + 1];
                }
                if (2 * i + 2 < nodes.length) {
                    nodeList[i].right = nodeList[2 * i + 2];
                }
            }
        }
        return nodeList[0];
    }

    static void levelAverage(Node root) {
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            int size = queue.size();
            double sum = 0;
            for (int i = 0; i < size; i++) {
                Node node = queue.poll();
                sum += node.val;
                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
            }
            System.out.println(sum / size);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        String[] nodes = new String[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = scanner.next();
        }
        Node root = buildTree(nodes);
        levelAverage(root);
    }
}
