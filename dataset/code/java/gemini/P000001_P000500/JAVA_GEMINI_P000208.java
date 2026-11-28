import java.util.*;

public class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        if (mat == null || mat.length == 0) return new int[0];
        int m = mat.length, n = mat[0].length;
        int[] res = new int[m * n];
        int idx = 0;

        for (int d = 0; d < m + n - 1; d++) {
            List<Integer> temp = new ArrayList<>();
            int r = (d < n ? 0 : d - n + 1);
            int c = (d < n ? d : n - 1);

            while (r < m && c >= 0) {
                temp.add(mat[r][c]);
                r++;
                c--;
            }

            if (d % 2 == 0) {
                for (int i = temp.size() - 1; i >= 0; i--) res[idx++] = temp.get(i);
            } else {
                for (int i = 0; i < temp.size(); i++) res[idx++] = temp.get(i);
            }
        }
        return res;
    }
}