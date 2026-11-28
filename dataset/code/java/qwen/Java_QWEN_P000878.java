import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Set<Integer> res = new HashSet<>();
        res.add(0);
        for(int num : nums) {
            Set<Integer> temp = new HashSet<>();
            for(int x : res) {
                temp.add(x | num);
            }
            res.addAll(temp);
        }
        System.out.println(res.size());
    }
}
