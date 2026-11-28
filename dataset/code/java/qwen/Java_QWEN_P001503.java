import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        List<Integer> ones = new ArrayList<>();
        for(int i=0; i<n; i++) {
            if(nums[i] == 1) ones.add(i);
        }
        
        if(ones.size() < k) {
            System.out.println(-1);
            return;
        }
        
        long minSwaps = Long.MAX_VALUE;
        for(int i=0; i<=ones.size()-k; i++) {
            int mid = i + k/2;
            int medianVal = ones.get(mid);
            long cost = 0;
            for(int j=i; j<i+k; j++) {
                cost += Math.abs(ones.get(j) - medianVal) - Math.abs(j - mid);
            }
            minSwaps = Math.min(minSwaps, cost);
        }
        System.out.println(minSwaps);
    }
}
