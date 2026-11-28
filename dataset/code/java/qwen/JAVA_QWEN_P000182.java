import java.util.Scanner;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        
        HashMap<Integer, Integer> freqMap = new HashMap<>();
        int maxFreq = 0;
        int mostFrequent = Integer.MAX_VALUE;
        
        for (int num : nums) {
            int freq = freqMap.getOrDefault(num, 0) + 1;
            freqMap.put(num, freq);
            
            if (freq > maxFreq || (freq == maxFreq && num < mostFrequent)) {
                maxFreq = freq;
                mostFrequent = num;
            }
        }
        System.out.println(mostFrequent);
    }
}
