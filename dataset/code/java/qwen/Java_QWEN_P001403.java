import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        for(int i=0; i<q; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            int[] sub = Arrays.copyOfRange(nums, l, r+1);
            Arrays.sort(sub);
            boolean isArith = true;
            if(sub.length > 2) {
                int diff = sub[1] - sub[0];
                for(int j=2; j<sub.length; j++) {
                    if(sub[j] - sub[j-1] != diff) {
                        isArith = false;
                        break;
                    }
                }
            }
            System.out.println(isArith ? "YES" : "NO");
        }
    }
}
