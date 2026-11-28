import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nodes = new int[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = scanner.nextInt();
        }
        List<Integer> preorder = new ArrayList<>();
        reconstructPreorder(nodes, preorder, Integer.MIN_VALUE, Integer.MAX_VALUE);
        for (int node : preorder) {
            System.out.print(node + " ");
        }
    }

    private static int index = 0;

    private static void reconstructPreorder(int[] nodes, List<Integer> preorder, int min, int max) {
        if (index == nodes.length) {
            return;
        }
        if (nodes[index] < min || nodes[index] > max) {
            return;
        }
        int root = nodes[index++];
        preorder.add(root);
        reconstructPreorder(nodes, preorder, min, root);
        reconstructPreorder(nodes, preorder, root, max);
    }
}
