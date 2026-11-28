import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        List<TreeNode> nodes = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String line = scanner.nextLine();
            String[] parts = line.split(" ");
            int left = Integer.parseInt(parts[0]);
            int right = Integer.parseInt(parts[1]);
            TreeNode node = new TreeNode(left, right);
            nodes.add(node);
        }

        List<Integer> result = boundaryTraversal(nodes);
        for (int value : result) {
            System.out.println(value);
        }
    }

    public static List<Integer> boundaryTraversal(List<TreeNode> nodes) {
        List<Integer> result = new ArrayList<>();
        result.add(nodes.get(0).left);
        result.add(nodes.get(0).right);

        for (int i = 1; i < nodes.size(); i++) {
            if (nodes.get(i).left != 0) {
                result.add(nodes.get(i).left);
            }
            if (nodes.get(i).right != 0) {
                result.add(nodes.get(i).right);
            }
        }

        return result;
    }

    public static class TreeNode {
        int left;
        int right;

        TreeNode(int left, int right) {
            this.left = left;
            this.right = right;
        }
    }
}
