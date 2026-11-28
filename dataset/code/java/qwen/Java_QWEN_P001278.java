import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int[] sorted = nums.clone();
        Arrays.sort(sorted);
        
        int chunks = 0;
        long sum1 = 0, sum2 = 0;
        for(int i=0; i<n; i++) {
            sum1 += nums[i];
            sum2 += sorted[i];
            if(sum1 == sum2) chunks++;
        }
        System.out.println(chunks);
    }
}
