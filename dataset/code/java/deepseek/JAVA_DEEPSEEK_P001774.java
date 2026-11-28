import java.util.*;

public class Main {
    static class Node {
        int val;
        Node left, right;
        Node(int val) {
            this.val = val;
            left = right = null;
        }
    }

    static Node buildTree(String[] nodes, int i) {
        if (i >= nodes.length || nodes[i].equals("null"))
            return null;

        Node root = new Node(Integer.parseInt(nodes[i]));
        root.left = buildTree(nodes, 2 * i + 1);
        root.right = buildTree(nodes, 2 * i + 2);
        return root;
    }

    static void countDistinct(Node root, int level, List<Integer>[] counts) {
        if (root == null)
            return;

        counts[level].add(root.val);
        countDistinct(root.left, level + 1, counts);
        countDistinct(root.right, level + 1, counts);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        String[] nodes = scanner.nextLine().split(" ");
        Node root = buildTree(nodes, 0);

        List<Integer>[] counts = new ArrayList[n];
        for (int i = 0; i < n; i++)
            counts[i] = new ArrayList<>();

        countDistinct(root, 0, counts);

        for (int i = 0; i < n; i++) {
            Set<Integer> distinct = new HashSet<>(counts[i]);
            System.out.println(distinct.size());
        }
    }
}
