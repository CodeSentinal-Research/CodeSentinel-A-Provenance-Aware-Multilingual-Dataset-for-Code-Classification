import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) nums[i] = sc.nextInt();
        
        int[] tails = new int[n];
        int len = 0;
        for (int num : nums) {
            int idx = Arrays.binarySearch(tails, 0, len, num);
            if (idx < 0) idx = -(idx + 1);
            tails[idx] = num;
            if (idx == len) len++;
        }
        System.out.println(len);
    }
}
