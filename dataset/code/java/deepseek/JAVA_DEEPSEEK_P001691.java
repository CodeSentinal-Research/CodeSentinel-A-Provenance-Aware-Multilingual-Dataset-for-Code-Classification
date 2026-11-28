import java.io.*;
import java.util.*;

public class Main {
    static class Node {
        int val;
        Node left, right;
        Node(int val) {
            this.val = val;
        }
    }

    static class Pair {
        int withRoot, withoutRoot;
        Pair(int withRoot, int withoutRoot) {
            this.withRoot = withRoot;
            this.withoutRoot = withoutRoot;
        }
    }

    public static Pair helper(Node root) {
        if (root == null) {
            return new Pair(0, 0);
        }
        Pair left = helper(root.left);
        Pair right = helper(root.right);
        return new Pair(root.val + left.withoutRoot + right.withoutRoot, Math.max(left.withRoot, left.withoutRoot) + Math.max(right.withRoot, right.withoutRoot));
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] values = br.readLine().split(" ");
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(Integer.parseInt(values[i]));
        }
        for (int i = 0; i < n; i++) {
            String[] children = br.readLine().split(" ");
            if (!children[0].equals("-1")) {
                nodes[i].left = nodes[Integer.parseInt(children[0])];
            }
            if (!children[1].equals("-1")) {
                nodes[i].right = nodes[Integer.parseInt(children[1])];
            }
        }
        Pair res = helper(nodes[0]);
        System.out.println(Math.max(res.withRoot, res.withoutRoot));
    }
}
