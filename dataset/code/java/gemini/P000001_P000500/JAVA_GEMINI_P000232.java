public class Solution {
    private int countSmallerOrEqual(int[] row, int target) {
        int l = 0, r = row.length;
        while (l < r) {
            // Calculate midpoint to prevent potential overflow
            int mid = l + (r - l) / 2;
            if (row[mid] <= target) l = mid + 1;
            else r = mid;
        }
        return l;
    }

    public int median(int[][] matrix, int R, int C) {
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        for (int i = 0; i < R; i++) {
            min = Math.min(min, matrix[i][0]);
            max = Math.max(max, matrix[i][C - 1]);
        }

        int desired = (R * C + 1) / 2;
        while (min < max) {
            // Calculate midpoint to prevent potential overflow
            int mid = min + (max - min) / 2;
            int count = 0;
            for (int i = 0; i < R; i++) {
                count += countSmallerOrEqual(matrix[i], mid);
            }
            if (count < desired) min = mid + 1;
            else max = mid;
        }
        return min;
    }
}