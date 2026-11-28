import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.println(minPasses(nums));
    }

    private static int minPasses(int[] nums) {
        Stack<Integer> stack = new Stack<>();
        int passes = 0;
        for (int num : nums) {
            while (!stack.isEmpty() && stack.peek() >= num) {
                stack.pop();
            }
            stack.push(num);
            passes = Math.max(passes, stack.size());
       }
        return passes;
    }
}
