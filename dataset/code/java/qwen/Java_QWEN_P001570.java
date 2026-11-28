import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int maxLen = 0;
        int negCount = 0;
        int firstNeg = -1;
        int lastNeg = -1;
        
        for(int i=0; i<n; i++) {
            if(nums[i] < 0) {
                negCount++;
                lastNeg = i;
                if(firstNeg == -1) firstNeg = i;
            }
            
            if(negCount % 2 == 0) {
                maxLen = Math.max(maxLen, i - (firstNeg == -1 ? -1 : firstNeg));
            } else {
                maxLen = Math.max(maxLen, i - firstNeg);
            }
            
            if(nums[i] == 0) {
                negCount = 0;
                firstNeg = -1;
                lastNeg = -1;
            }
        }
        System.out.println(maxLen);
    }
}
