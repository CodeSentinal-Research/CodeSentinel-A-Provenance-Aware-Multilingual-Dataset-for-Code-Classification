import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int[] nums = new int[N];
        for (int i = 0; i < N; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.println(countSubarrays(nums, K));
    }

    public static long countSubarrays(int[] nums, int K) {
        long count = 0;
        int left = 0, right = 0;
        Map<Integer, Integer> map = new HashMap<>();
        while (right < nums.length) {
            map.put(nums[right], map.getOrDefault(nums[right], 0) + 1);
            while (map.size() == K) {
                map.put(nums[left], map.get(nums[left]) - 1);
                if (map.get(nums[left]) == 0) {
                    map.remove(nums[left]);
                }
                left++;
            }
            count += (long) (right - left + 1);
            right++;
        }
        return count;
    }
}
