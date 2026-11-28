public class Solution {
    public boolean areIdentical(int[][] mat1, int[][] mat2) {
        if (mat1.length != mat2.length || mat1[0].length != mat2[0].length) return false;
        for (int i = 0; i < mat1.length; i++) {
            for (int j = 0; j < mat1[0].length; j++) {
                if (mat1[i][j] != mat2[i][j]) return false;
            }
        }
        return true;
    }
}