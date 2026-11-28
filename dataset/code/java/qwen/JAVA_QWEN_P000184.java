import java.util.Scanner;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        
        HashMap<Long, Integer> prefixMap = new HashMap<>();
        prefixMap.put(0L, -1);
        long currentSum = 0;
        int maxLen = 0;
        
        for (int i = 0; i < n; i++) {
            currentSum += nums[i];
            if (prefixMap.containsKey(currentSum - k)) {
                maxLen = Math.max(maxLen, i - prefixMap.get(currentSum - k));
            }
            if (!prefixMap.containsKey(currentSum)) {
                prefixMap.put(currentSum, i);
            }
        }
        System.out.println(maxLen);
    }
}
