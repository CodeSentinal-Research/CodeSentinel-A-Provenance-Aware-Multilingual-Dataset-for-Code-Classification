import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        int p = scanner.nextInt();
        System.out.println(minSubarray(nums, p));
    }

    public static int minSubarray(int[] nums, int p) {
        int n = nums.length;
        int[] prefixMod = new int[n + 1];
        Map<Integer, Integer> modCount = new HashMap<>();
        for (int i = 0; i < n; i++) {
            prefixMod[i + 1] = (prefixMod[i] + nums[i]) % p;
            modCount.merge(prefixMod[i + 1], 1, Integer::sum);
        }
        int minLen = n + 1;
        for (int count : modCount.values()) {
            if (count > 1) {
                minLen = Math.min(minLen, n - count + 1);
           }
        }
        return minLen > n ? -1 : minLen;
    }
}
