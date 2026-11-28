import java.util.*;

public class Main {
    static int maxLength = 0;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(scanner.nextInt());
        }
        for (int i = 0; i < n - 1; i++) {
            int a = scanner.nextInt() - 1;
            int b = scanner.nextInt() - 1;
            nodes[a].children.add(nodes[b]);
            nodes[b].children.add(nodes[a]);
        }
        dfs(nodes[0], -1, true);
        dfs(nodes[0], -1, false);
        System.out.println(maxLength);
    }

    static void dfs(Node node, int parent, boolean isEven) {
        int max1 = 0, max2 = 0;
        for (Node child : node.children) {
            if (child == node.parent) continue;
            dfs(child, node.val, !isEven);
            if (child.val % 2 == node.val % 2) continue;
            if (isEven && child.maxLengthEven > max1) {
                max2 = max1;
                max1 = child.maxLengthEven;
            } else if (!isEven && child.maxLengthOdd > max1) {
                max2 = max1;
                max1 = child.maxLengthOdd;
           }
        }
        if (isEven) {
            node.maxLengthEven = max1 + 1;
            maxLength = Math.max(maxLength, max1 + 1);
        } else {
            node.maxLengthOdd = max1 + 1;
            maxLength = Math.max(maxLength, max1 + 1);
        }
        if (max2 > 0) {
            maxLength = Math.max(maxLength, max1 + max2 + 1);
        }
    }

    static class Node {
        int val;
        Node parent;
        List<Node> children;
        int maxLengthEven;
        int maxLengthOdd;

        Node(int val) {
            this.val = val;
            children = new ArrayList<>();
        }
    }
}
