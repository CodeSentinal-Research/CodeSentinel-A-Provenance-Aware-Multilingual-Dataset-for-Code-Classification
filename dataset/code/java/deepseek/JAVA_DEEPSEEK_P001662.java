import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < N; i++) {
            String[] input = scanner.nextLine().split(" ");
            int[] nodes = new int[input.length];
            for (int j = 0; j < input.length; j++) {
                nodes[j] = Integer.parseInt(input[j]);
            }

            if (isBalanced(nodes, 0, nodes.length - 1)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }

        scanner.close();
    }

    private static boolean isBalanced(int[] nodes, int start, int end) {
        if (start > end) {
            return true;
        }

        int maxHeight = getMaxHeight(nodes, start, end);
        int leftHeight = getMaxHeight(nodes, start, end - maxHeight - 1);
        int rightHeight = getMaxHeight(nodes, end - maxHeight + 1, end);

        return Math.abs(leftHeight - rightHeight) <= 1 && isBalanced(nodes, start, end - maxHeight - 1) && isBalanced(nodes, end - maxHeight + 1, end);
    }

    private static int getMaxHeight(int[] nodes, int start, int end) {
        int max = nodes[start];
        for (int i = start + 1; i <= end; i++) {
            if (nodes[i] > max) {
                max = nodes[i];
            }
        }
        return max;
    }
}
