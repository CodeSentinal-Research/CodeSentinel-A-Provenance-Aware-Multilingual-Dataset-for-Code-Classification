package programs.intervals;

import java.util.Arrays;
import java.util.Comparator;

/**
 * LeetCode 435: Non-overlapping Intervals
 * Given an array of intervals intervals where intervals[i] = [starti, endi],
 * return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
 */
public class NonOverlappingIntervals {

    public int eraseOverlapIntervals(int[][] intervals) {
        if (intervals == null || intervals.length == 0) {
            return 0;
        }
        
        // Sort by end time
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[1]));
        
        int count = 0;
        int end = intervals[0][1];
        
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] < end) {
                // Overlapping, need to remove
                count++;
            } else {
                // Non-overlapping, update end
                end = intervals[i][1];
            }
        }
        
        return count;
    }

    public static void main(String[] args) {
        NonOverlappingIntervals solution = new NonOverlappingIntervals();
        
        // Test cases
        System.out.println("Min removals for [[1,2],[2,3],[3,4],[1,3]]: " + 
            solution.eraseOverlapIntervals(new int[][]{{1, 2}, {2, 3}, {3, 4}, {1, 3}})); // 1
        System.out.println("Min removals for [[1,2],[1,2],[1,2]]: " + 
            solution.eraseOverlapIntervals(new int[][]{{1, 2}, {1, 2}, {1, 2}})); // 2
    }
}
