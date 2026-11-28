import java.util.*;

public class Main {
    static class Node {
        int val;
        Node left;
        Node right;
        Node(int val) {
            this.val = val;
            left = null;
            right = null;
        }
    }

    static int maxSize = 0;

    static boolean isMirror(Node a, Node b) {
        if (a == null && b == null)
            return true;
        if (a == null || b == null)
            return false;
        return (a.val == b.val) && isMirror(a.left, b.right) && isMirror(a.right, b.left);
    }

    static int sizeOfMirrorTree(Node node) {
        if (node == null)
            return 0;
        int size = 1 + sizeOfMirrorTree(node.left) + sizeOfMirrorTree(node.right);
        if (isMirror(node.left, node.right)) {
            maxSize = Math.max(maxSize, size);
        }
        return size;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node[] nodes = new Node[n+1];
        for (int i = 1; i <= n; i++) {
            nodes[i] = new Node(i);
        }
        for (int i = 1; i <= n; i++) {
            int left = sc.nextInt();
            int right = sc.nextInt();
            if (left != 0) {
                nodes[i].left = nodes[left];
            }
            if (right != 0) {
                nodes[i].right = nodes[right];
            }
        }
        sizeOfMirrorTree(nodes[1]);
        System.out.println(maxSize);
    }
}
