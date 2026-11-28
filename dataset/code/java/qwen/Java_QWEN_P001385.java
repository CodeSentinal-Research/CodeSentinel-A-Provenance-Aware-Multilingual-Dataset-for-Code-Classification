import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        List<Integer> res = new ArrayList<>();
        for(int num : nums) {
            int idx = Math.abs(num) - 1;
            if(nums[idx] > 0) nums[idx] = -nums[idx];
        }
        
        for(int i=0; i<n; i++) {
            if(nums[i] > 0) res.add(i+1);
        }
        
        for(int num : res) System.out.print(num + " ");
    }
}
