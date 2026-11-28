import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int unique = 0;
        for(int i=1; i<n; i++) {
            if(nums[i] != nums[unique]) {
                unique++;
                nums[unique] = nums[i];
            }
        }
        
        System.out.println(unique + 1);
        for(int i=0; i<=unique; i++) System.out.print(nums[i] + " ");
    }
}
