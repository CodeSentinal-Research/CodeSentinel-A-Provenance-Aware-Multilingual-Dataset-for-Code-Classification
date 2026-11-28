import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        
        ArrayList<Integer> leaders = new ArrayList<>();
        int maxFromRight = Integer.MIN_VALUE;
        
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] >= maxFromRight) {
                leaders.add(nums[i]);
                maxFromRight = nums[i];
            }
        }
        
        Collections.reverse(leaders);
        for (int i = 0; i < leaders.size(); i++) {
            if (i > 0) System.out.print(" ");
            System.out.print(leaders.get(i));
        }
        System.out.println();
    }
}
