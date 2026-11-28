import java.util.*;

public class Solution {
    public List<List<Integer>> printFloydTriangle(int n) {
        List<List<Integer>> res = new ArrayList<>();
        int num = 1;
        for (int i = 1; i <= n; i++) {
            List<Integer> row = new ArrayList<>();
            for (int j = 0; j < i; j++) {
                row.add(num++);
            }
            res.add(row);
        }
        return res;
    }
}
