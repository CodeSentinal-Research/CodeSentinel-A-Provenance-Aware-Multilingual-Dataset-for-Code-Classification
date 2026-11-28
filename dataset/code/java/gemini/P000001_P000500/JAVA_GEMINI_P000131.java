import java.util.*;

public class Solution {
    public List<Integer> leaders(int[] arr) {
        List<Integer> res = new ArrayList<>();
        int maxFromRight = Integer.MIN_VALUE;
        for (int i = arr.length - 1; i >= 0; i--) {
            if (arr[i] >= maxFromRight) {
                res.add(arr[i]);
                maxFromRight = arr[i];
            }
        }
        Collections.reverse(res);
        return res;
    }
}

class MainExecution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }
            Solution sol = new Solution();
            List<Integer> leaders = sol.leaders(arr);
            for (int i = 0; i < leaders.size(); i++) {
                System.out.print(leaders.get(i) + (i == leaders.size() - 1 ? "" : " "));
            }
            System.out.println();
        }
    }
}
