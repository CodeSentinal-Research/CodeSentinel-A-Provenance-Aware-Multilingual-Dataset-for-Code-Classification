import java.util.*;

public class StackPermutation {
    public static boolean isStackPermutation(int[] original, int[] target) {
        Stack<Integer> stack = new Stack<>();
        int i = 0;
        for (int element : original) {
            stack.push(element);
            while (!stack.isEmpty() && stack.peek() == target[i]) {
                stack.pop();
                i++;
            }
        }
        return stack.isEmpty();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] original = new int[n];
        int[] target = new int[n];
        for (int i = 0; i < n; i++) {
            original[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            target[i] = sc.nextInt();
        }
        System.out.println(isStackPermutation(original, target) ? "Yes" : "No");
        sc.close();
    }
}