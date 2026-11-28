import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int[] res = new int[n];
        int posIdx = 0, negIdx = 1;
        for(int num : nums) {
            if(num > 0) {
                res[posIdx] = num;
                posIdx += 2;
            } else {
                res[negIdx] = num;
                negIdx += 2;
            }
        }
        
        for(int x : res) System.out.print(x + " ");
    }
}
