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
        dfs(nodes[0], null);
        System.out.println(maxLength);
    }

    static void dfs(Node node, Node parent) {
        int max1 = 0, max2 = 0;
        for (Node child : node.children) {
            if (child != parent) {
                dfs(child, node);
                if (child.value - node.value == 1) {
                    if (child.maxLength + 1 > max1) {
                        max2 = max1;
                        max1 = child.maxLength + 1;
                    } else if (child.maxLength + 1 > max2) {
                        max2 = child.maxLength + 1;
                   }
                }
            }
        }
        node.maxLength = max1;
        maxLength = Math.max(maxLength, max1 + (parent != null ? max2 : 0));
    }

    static class Node {
        int value;
        List<Node> children;
        int maxLength;

        Node(int value) {
            this.value = value;
            children = new ArrayList<>();
        }
    }
}
