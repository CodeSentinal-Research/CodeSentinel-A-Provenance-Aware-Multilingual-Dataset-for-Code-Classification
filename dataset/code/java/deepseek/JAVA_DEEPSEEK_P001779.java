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

    static int maxLen = 0;
    static List<Integer> maxList = new ArrayList<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(sc.nextInt());
        }
        for (int i = 0; i < n; i++) {
            int left = sc.nextInt() - 1;
            int right = sc.nextInt() - 1;
            if (left != -1) {
                nodes[i].left = nodes[left];
            }
            if (right != -1) {
                nodes[i].right = nodes[right];
            }
        }
        longestIncreasingPath(nodes[0]);
        for (int num : maxList) {
            System.out.print(num + " ");
        }
    }

    private static int longestIncreasingPath(Node node) {
        if (node == null) {
            return 0;
        }
        int left = node.left != null ? longestIncreasingPath(node.left) : 0;
        int right = node.right != null ? longestIncreasingPath(node.right) : 0;
        if (node.left != null && node.left.val < node.val) {
            left++;
        }
        if (node.right != null && node.right.val < node.val) {
            right++;
        }
        if (left + right > maxLen) {
            maxLen = left + right;
            maxList.clear();
            maxList.add(node.val);
            for (int i = 0; i < left; i++) {
                maxList.add(0, node.left.val);
                node.left = node.left.left;
            }
            for (int i = 0; i < right; i++) {
                maxList.add(node.right.val);
                node.right = node.right.right;
            }
        }
        return Math.max(left, right);
    }
}
