import java.util.*;

public class Main {
    static int count = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        String[] values = sc.nextLine().split(" ");
        Node root = new Node(Integer.parseInt(values[0]));
        for (int i = 1; i < n; i++) {
            insert(root, Integer.parseInt(values[i]));
        }
        countPPPaths(root, new ArrayList<>());
        System.out.println(count);
    }

    static void countPPPaths(Node node, List<Integer> path) {
        if (node == null) {
            return;
        }
        path.add(node.val);
        if (node.left == null && node.right == null) {
            if (isPP(path)) {
                count++;
            }
        } else {
            countPPPaths(node.left, new ArrayList<>(path));
            countPPPaths(node.right, new ArrayList<>(path));
        }
    }

    static boolean isPP(List<Integer> path) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i : path) {
            map.put(i, map.getOrDefault(i, 0) + 1);
        }
        int oddCount = 0;
        for (int v : map.values()) {
            if (v % 2 != 0) {
                oddCount++;
            }
        }
        return oddCount <= 1;
    }

    static Node insert(Node node, int value) {
        if (node == null) {
            return new Node(value);
        }
        if (value < node.val) {
            node.left = insert(node.left, value);
        } else if (value > node.val) {
            node.right = insert(node.right, value);
        }
        return node;
    }

    static class Node {
        int val;
        Node left;
        Node right;

        Node(int val) {
            this.val = val;
        }
    }
}
