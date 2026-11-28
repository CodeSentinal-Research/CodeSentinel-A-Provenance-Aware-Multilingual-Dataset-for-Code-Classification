import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int passes = 0;
        boolean[] removed = new boolean[n];
        int remaining = n;
        while(remaining > 0) {
            passes++;
            List<Integer> toRemove = new ArrayList<>();
            int last = -1;
            for(int i=0; i<n; i++) {
                if(!removed[i]) {
                    if(nums[i] > last) {
                        toRemove.add(i);
                        last = nums[i];
                    }
                }
            }
            for(int idx : toRemove) {
                removed[idx] = true;
                remaining--;
            }
        }
        System.out.println(passes);
    }
}
