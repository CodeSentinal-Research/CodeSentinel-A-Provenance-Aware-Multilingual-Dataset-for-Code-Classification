import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < n; i++) {
            String[] input = scanner.nextLine().split(" ");
            int[] nodes = new int[input.length];
            for (int j = 0; j < input.length; j++) {
                nodes[j] = Integer.parseInt(input[j]);
            }
            if (isSymmetric(nodes, 0, nodes.length - 1)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }

    private static boolean isSymmetric(int[] nodes, int start, int end) {
        if (start >= end) {
            return true;
        }
        if (nodes[start] != nodes[end]) {
            return false;
        }
        return isSymmetric(nodes, start + 1, end - 1);
    }
}
