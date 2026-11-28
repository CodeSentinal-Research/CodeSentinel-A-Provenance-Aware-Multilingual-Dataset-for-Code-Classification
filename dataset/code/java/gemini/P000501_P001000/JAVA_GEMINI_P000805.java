import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Solution {
    public static long countEqualPosNegSubarrays(int[] arr) {
        int prefixSum = 0;
        long count = 0;
        Map<Integer, Integer> freq = new HashMap<>();
        freq.put(0, 1);
        for (int x : arr) {
            int val = x > 0 ? 1 : (x < 0 ? -1 : 0);
            prefixSum += val;
            count += freq.getOrDefault(prefixSum, 0);
            freq.put(prefixSum, freq.getOrDefault(prefixSum, 0) + 1);
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
            System.out.println(countEqualPosNegSubarrays(arr));
        }
        sc.close();
    }
}