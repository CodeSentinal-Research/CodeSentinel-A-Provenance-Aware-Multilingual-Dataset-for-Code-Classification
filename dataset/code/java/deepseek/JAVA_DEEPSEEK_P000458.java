import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        System.out.println(splitArray(nums, m));
    }

    public static int splitArray(int[] nums, int m) {
        int max = 0, sum = 0;
        for (int num : nums) {
            max = Math.max(max, num);
            sum += num;
        }
        if (m == 1) {
            return sum;
        }
        int l = max, r = sum;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (canSplit(nums, mid, m)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    public static boolean canSplit(int[] nums, int target, int m) {
        int count = 1, sum = 0;
        for (int num : nums) {
            if (sum + num > target) {
                sum = num;
                count++;
                if (count > m) {
                    return false;
                }
            } else {
                sum += num;
            }
        }
        return true;
    }
}
