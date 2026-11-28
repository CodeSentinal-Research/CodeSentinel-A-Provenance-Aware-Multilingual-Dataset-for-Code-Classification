import java.util.*;

public class Solution {
    public List<Integer> findCommonElements(int[][] mat) {
        if (mat == null || mat.length == 0) return new ArrayList<>();
        Set<Integer> common = new HashSet<>();
        for (int x : mat[0]) common.add(x);

        for (int i = 1; i < mat.length; i++) {
            Set<Integer> rowSet = new HashSet<>();
            for (int x : mat[i]) rowSet.add(x);
            common.retainAll(rowSet);
        }

        List<Integer> res = new ArrayList<>(common);
        Collections.sort(res);
        return res;
    }
}