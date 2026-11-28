import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        long count = 0;
        int len = 1;
        for(int i=1; i<n; i++) {
            if(nums[i] != nums[i-1]) {
                len++;
            } else {
                len = 1;
            }
            count += len;
        }
        System.out.println(count);
    }
}
