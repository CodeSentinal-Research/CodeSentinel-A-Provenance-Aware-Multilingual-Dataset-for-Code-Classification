import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        
        int[] count = new int[k];
        for (int num : nums) {
            count[num % k]++;
        }
        
        int maxRepeating = -1;
        int maxCount = -1;
        
        // Find the number with max frequency. If tie, larger number usually preferred in some contexts, 
        // but problem says "maximum repeating number". 
        // Standard interpretation: value that appears most often.
        
        for (int i = 0; i < k; i++) {
             // This logic assumes values are 0 to K-1 as per constraints often seen in this specific problem variant
             // If values are arbitrary, we need a map.
             // Given constraint "elements from 0 to K-1", array is fine.
        }
        
        // Re-evaluating based on standard "Maximum Repeating Number" problem which often uses O(1) space trick
        // But here we just find the mode.
        
        int mode = -1;
        int maxFreq = 0;
        
        // Using map for general case if constraints aren't strictly 0..K-1 for values, 
        // but prompt says "elements from 0 to K-1".
        
        for(int i=0; i<k; i++) {
            if(count[i] > maxFreq) {
                maxFreq = count[i];
                mode = i;
            } else if (count[i] == maxFreq && i > mode) {
                 // Tie breaking? Usually just return any or smallest/largest. 
                 // Let's assume standard mode finding.
                 mode = i; 
            }
        }
        
        System.out.println(mode);
    }
}
