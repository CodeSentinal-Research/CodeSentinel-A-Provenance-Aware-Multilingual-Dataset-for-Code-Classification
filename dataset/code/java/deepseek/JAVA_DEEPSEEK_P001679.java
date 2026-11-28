import java.util.*;

public class Main {
    static class Node {
        int value;
        Node left, right;

        Node(int value) {
            this.value = value;
            left = right = null;
        }
    }

    static Node root;

    static void buildTree(int[] nodes) {
        Queue<Node> q = new LinkedList<>();
        root = new Node(nodes[0]);
        q.add(root);

        int i = 1;
        while (!q.isEmpty() && i < nodes.length) {
            Node temp = q.poll();

            if (nodes[i] != -1) {
                temp.left = new Node(nodes[i]);
                q.add(temp.left);
            }
            i++;

            if (i < nodes.length && nodes[i] != -1) {
                temp.right = new Node(nodes[i]);
                q.add(temp.right);
            }
            i++;
        }
    }

    static int maxSumLevel(Node root) {
        if (root == null)
            return -1;

        Queue<Node> q = new LinkedList<>();
        q.add(root);

        int level = 0;
        int maxSum = Integer.MIN_VALUE;
        int maxLevel = -1;

        while (!q.isEmpty()) {
            int size = q.size();
            int sum = 0;
            while (size-- > 0) {
                Node temp = q.poll();
                sum += temp.value;

                if (temp.left != null)
                    q.add(temp.left);
                if (temp.right != null)
                    q.add(temp.right);
            }
            level++;
            if (sum > maxSum) {
                maxSum = sum;
                maxLevel = level;
            }
        }
        return maxLevel;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nodes = new int[n];
        for (int i = 0; i < n; i++)
            nodes[i] = sc.nextInt();
        buildTree(nodes);
        System.out.println(maxSumLevel(root));
    }
}
