import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int maxLen = 0;
        for(int i=0; i<n; ) {
            int j = i + 1;
            while(j < n && nums[j] > nums[j-1]) j++;
            int incEnd = j - 1;
            while(j < n && nums[j] < nums[j-1]) j++;
            if(j > incEnd + 1) {
                maxLen = Math.max(maxLen, j - i);
            }
            i = j;
        }
        System.out.println(maxLen);
    }
}
