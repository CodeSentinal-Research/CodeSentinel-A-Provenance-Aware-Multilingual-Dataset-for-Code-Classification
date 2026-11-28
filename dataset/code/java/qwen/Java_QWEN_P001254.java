import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] nums = new String[n];
        for(int i=0; i<n; i++) nums[i] = sc.next();
        
        Arrays.sort(nums, (a, b) -> (b + a).compareTo(a + b));
        
        StringBuilder sb = new StringBuilder();
        for(String s : nums) sb.append(s);
        
        String res = sb.toString();
        if(res.startsWith("0")) System.out.println("0");
        else System.out.println(res);
    }
}
