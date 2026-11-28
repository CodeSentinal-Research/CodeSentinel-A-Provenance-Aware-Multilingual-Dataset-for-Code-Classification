import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] pre = new int[n];
        for (int i = 0; i < n; i++) {
            pre[i] = scanner.nextInt();
        }
        System.out.println(canRepresentBST(pre) ? "YES" : "NO");
    }

    private static boolean canRepresentBST(int[] pre) {
        Stack<Integer> stack = new Stack<>();
        int root = Integer.MIN_VALUE;
        for (int value : pre) {
            if (value < root) {
                return false;
            }
            while (!stack.isEmpty() && stack.peek() < value) {
                root = stack.pop();
            }
            stack.push(value);
        }
        return true;
    }
}
