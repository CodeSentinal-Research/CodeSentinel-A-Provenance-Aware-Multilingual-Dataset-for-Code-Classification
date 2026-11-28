import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        Arrays.sort(nums);
        
        int[] dp = new int[n];
        int[] prev = new int[n];
        Arrays.fill(dp, 1);
        Arrays.fill(prev, -1);
        
        int maxIdx = 0;
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if(dp[i] > dp[maxIdx]) maxIdx = i;
        }
        
        List<Integer> res = new ArrayList<>();
        int idx = maxIdx;
        while(idx != -1) {
            res.add(nums[idx]);
            idx = prev[idx];
        }
        Collections.reverse(res);
        for(int x : res) System.out.print(x + " ");
    }
}
