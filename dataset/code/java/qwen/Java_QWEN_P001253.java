import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Arrays.sort(nums);
        int minDiff = Integer.MAX_VALUE;
        for(int i=1; i<n; i++) {
            minDiff = Math.min(minDiff, nums[i] - nums[i-1]);
        }
        
        List<int[]> res = new ArrayList<>();
        for(int i=1; i<n; i++) {
            if(nums[i] - nums[i-1] == minDiff) {
                res.add(new int[]{nums[i-1], nums[i]});
            }
        }
        
        for(int[] p : res) {
            System.out.print(p[0] + " " + p[1] + "
");
        }
    }
}
