import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        Node[] nodes = new Node[N];
        for (int i = 0; i < N; i++) {
            nodes[i] = new Node();
        }
        for (int i = 0; i < N; i++) {
            int left = scanner.nextInt() - 1;
            int right = scanner.nextInt() - 1;
            if (left >= 0) {
                nodes[i].left = nodes[left];
                nodes[left].parent = nodes[i];
            }
            if (right >= 0) {
                nodes[i].right = nodes[right];
                nodes[right].parent = nodes[i];
            }
        }
        for (int i = 0; i < N; i++) {
            System.out.println(depth(nodes[i]));
        }
    }

    static int depth(Node node) {
        int depth = 0;
        while (node.parent != null) {
            node = node.parent;
            depth++;
        }
        return depth;
    }

    static class Node {
        Node parent;
        Node left;
        Node right;
    }
}
