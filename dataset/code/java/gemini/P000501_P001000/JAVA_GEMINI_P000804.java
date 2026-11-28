import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Solution {
    public static long countSubarraysXorK(int[] arr, int k) {
        int prefixXor = 0;
        long count = 0;
        Map<Integer, Integer> freq = new HashMap<>();
        freq.put(0, 1);
        for (int num : arr) {
            prefixXor ^= num;
            count += freq.getOrDefault(prefixXor ^ k, 0);
            freq.put(prefixXor, freq.getOrDefault(prefixXor, 0) + 1);
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
            System.out.println(countSubarraysXorK(arr, k));
        }
        sc.close();
    }
}