import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        long n = sc.nextLong();
        int[] nums = new int[m];
        for(int i=0; i<m; i++) nums[i] = sc.nextInt();
        
        int patches = 0;
        long reach = 0;
        int i = 0;
        while(reach < n) {
            if(i < m && nums[i] <= reach + 1) {
                reach += nums[i++];
            } else {
                reach += reach + 1;
                patches++;
            }
        }
        System.out.println(patches);
    }
}
