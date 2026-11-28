import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] candidates = new int[n];
        for(int i=0; i<n; i++) candidates[i] = sc.nextInt();
        int target = sc.nextInt();
        Arrays.sort(candidates);
        combSum2(candidates, target, 0, new ArrayList<>(), 0);
    }
    static void combSum2(int[] cand, int target, int idx, List<Integer> curr, int sum) {
        if(sum == target) {
            System.out.println(curr);
            return;
        }
        if(sum > target) return;
        for(int i=idx; i<cand.length; i++) {
            if(i > idx && cand[i] == cand[i-1]) continue;
            curr.add(cand[i]);
            combSum2(cand, target, i + 1, curr, sum + cand[i]);
            curr.remove(curr.size() - 1);
        }
    }
}
