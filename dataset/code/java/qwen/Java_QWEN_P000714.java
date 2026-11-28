import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        List<Integer> sums = new ArrayList<>();
        subSum(nums, 0, 0, sums);
        Collections.sort(sums);
        for(int s : sums) System.out.print(s + " ");
    }
    static void subSum(int[] nums, int i, int sum, List<Integer> sums) {
        if(i == nums.length) {
            sums.add(sum);
            return;
        }
        subSum(nums, i + 1, sum, sums);
        subSum(nums, i + 1, sum + nums[i], sums);
    }
}
