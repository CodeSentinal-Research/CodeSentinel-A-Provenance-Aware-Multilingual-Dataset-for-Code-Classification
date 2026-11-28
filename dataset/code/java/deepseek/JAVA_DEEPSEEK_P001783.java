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

    static Node buildTree(int[] nodes) {
        Node[] nodeList = new Node[nodes.length];
        for (int i = 0; i < nodes.length; i++) {
            nodeList[i] = new Node(i);
        }
        for (int i = 0; i < nodes.length; i++) {
            if (nodes[i] != -1) {
                nodeList[i].left = nodeList[nodes[i]];
            }
            if (i + 1 < nodes.length && nodes[i + 1] != -1) {
                nodeList[i].right = nodeList[i + 1];
            }
       
       }
       return nodeList[0];
    }

    static int countNodes(Node root) {
        if (root == null) {
            return 0;
        }
        return 1 + countNodes(root.left) + countNodes(root.right);
    }

    static Node findCentroid(Node root, int totalNodes) {
        Queue<Node> queue = new LinkedList<>();
        queue.offer(root);
        while (!queue.isEmpty()) {
            Node node = queue.poll();
            if (node != null) {
                if (countNodes(node) == totalNodes / 2) {
                    return node;
                }
                queue.offer(node.left);
                queue.offer(node.right);
            }
        }
        return null;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nodes = new int[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = scanner.nextInt();
        }
        Node root = buildTree(nodes);
        int totalNodes = countNodes(root);
        Node centroid = findCentroid(root, totalNodes);
        System.out.println(centroid.val);
    }
}
