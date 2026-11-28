import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[] nums = new int[n];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
            sum += nums[i];
        }
        if (sum % k != 0) {
            System.out.println("NO");
        } else {
            sum /= k;
            boolean[] visited = new boolean[n];
            if (backtrack(nums, visited, sum, 0, 0, k)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }

    private static boolean backtrack(int[] nums, boolean[] visited, int target, int start, int sum, int k) {
        if (k == 0) {
            return true;
        }
        for (int i = start; i < nums.length; i++) {
            if (!visited[i] && sum + nums[i] <= target) {
                visited[i] = true;
                if (backtrack(nums, visited, target, i + 1, sum + nums[i], k - 1)) {
                    return true;
                }
                visited[i] = false;
            }
        }
        return false;
    }
}
