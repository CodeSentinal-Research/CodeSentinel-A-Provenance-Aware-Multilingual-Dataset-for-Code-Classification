import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Map<Long, Integer> prodFreq = new HashMap<>();
        long count = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                long prod = (long)nums[i] * nums[j];
                count += prodFreq.getOrDefault(prod, 0);
                prodFreq.put(prod, prodFreq.getOrDefault(prod, 0) + 1);
            }
        }
        System.out.println(count * 8);
    }
}
