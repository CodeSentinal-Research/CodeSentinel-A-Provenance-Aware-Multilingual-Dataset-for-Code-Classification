import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }

        int[] diffs = new int[n];
        int leftSum = 0;
        int rightSum = 0;
        for (int i = 0; i < n; i++) {
            rightSum += nums[i];
        }

        for (int i = 0; i < n; i++) {
            rightSum -= nums[i];
            diffs[i] = Math.abs(leftSum - rightSum);
            leftSum += nums[i];
       }

        for (int diff : diffs) {
            System.out.print(diff + " ");
        }
    }
}
