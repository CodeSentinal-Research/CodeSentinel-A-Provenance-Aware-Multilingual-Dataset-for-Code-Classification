import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int x = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int idx = Arrays.binarySearch(nums, x);
        if(idx < 0) idx = -idx - 1;
        
        int left = idx - 1, right = idx;
        List<Integer> res = new ArrayList<>();
        while(res.size() < k) {
            if(left < 0) res.add(nums[right++]);
            else if(right >= n) res.add(nums[left--]);
            else if(x - nums[left] <= nums[right] - x) res.add(nums[left--]);
            else res.add(nums[right++]);
        }
        Collections.sort(res);
        for(int val : res) System.out.print(val + " ");
    }
}
