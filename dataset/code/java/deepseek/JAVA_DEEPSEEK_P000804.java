import java.util.HashMap;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        int K = scanner.nextInt();
        System.out.println(subarraysXOR(nums, K));
    }

    private static int subarraysXOR(int[] nums, int K) {
        HashMap<Integer, Integer> prefixXOR = new HashMap<>();
        int xor = 0;
        int count = 0;
        for (int num : nums) {
            xor = xor ^ num;
            if (prefixXOR.containsKey(xor ^ K)) {
                count += prefixXOR.get(xor ^ K);
            }
            if (xor == K) {
                count++;
            }
            prefixXOR.put(xor, prefixXOR.getOrDefault(xor, 0) + 1);
        }
        return count;
    }
}
