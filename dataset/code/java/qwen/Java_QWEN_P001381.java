import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Set<Integer> set = new HashSet<>();
        for(int num : nums) set.add(num);
        
        int maxLen = 0;
        for(int num : set) {
            if(!set.contains(num - 1)) {
                int currNum = num;
                int currLen = 1;
                while(set.contains(currNum + 1)) {
                    currNum++;
                    currLen++;
                }
                maxLen = Math.max(maxLen, currLen);
            }
        }
        System.out.println(maxLen);
    }
}
