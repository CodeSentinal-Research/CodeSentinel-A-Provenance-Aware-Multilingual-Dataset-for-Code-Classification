import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int target = sc.nextInt();
        int[] candidates = new int[n];
        for(int i=0; i<n; i++) candidates[i] = sc.nextInt();
        
        Arrays.sort(candidates);
        backtrack(candidates, target, 0, new ArrayList<>());
    }
    
    static void backtrack(int[] cand, int target, int start, List<Integer> curr) {
        if(target == 0) {
            System.out.println(curr);
            return;
        }
        for(int i=start; i<cand.length; i++) {
            if(cand[i] > target) break;
            curr.add(cand[i]);
            backtrack(cand, target - cand[i], i, curr);
            curr.remove(curr.size()-1);
        }
    }
}
