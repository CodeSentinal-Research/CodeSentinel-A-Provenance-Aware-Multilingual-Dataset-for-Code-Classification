import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long x = sc.nextLong();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        long sum = 0;
        int len = -1;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            if(sum >= x) {
                len = i + 1;
                break;
            }
        }
        System.out.println(len);
    }
}
