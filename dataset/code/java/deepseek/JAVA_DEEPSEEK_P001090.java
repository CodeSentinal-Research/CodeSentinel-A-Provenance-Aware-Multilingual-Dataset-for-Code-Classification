import java.util.Scanner;

public class Main {
    static class Node {
        int id;
        Node parent;
        Node(int id) {
            this.id = id;
        }
    }

    static Node[] nodes;
    static int[] sizes;
    static int diameter;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        nodes = new Node[n + 1];
        for (int i = 1; i <= n; i++) {
            nodes[i] = new Node(i);
        }
        for (int i = 1; i < n; i++) {
            int parent = scanner.nextInt();
            nodes[parent].parent = nodes[i];
        }
        scanner.close();
        sizes = new int[n + 1];
        diameter = 0;
        dfs(1);
        System.out.println(diameter);
    }

    static int dfs(int id) {
        int size = 1;
        if (nodes[id].parent != null) {
            size += dfs(nodes[id].parent.id);
        }
        sizes[id] = size;
        diameter = Math.max(diameter, size);
        return size;
    }
}
