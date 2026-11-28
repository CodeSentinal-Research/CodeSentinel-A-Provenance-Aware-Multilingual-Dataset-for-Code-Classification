import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * 40. Combination Sum II (https://leetcode.com/problems/combination-sum-ii/description/)
 */
public class CombinationSumII {

    /**
     * List of similar questions
     * 78. Subsets
     * 90. Subsets II
     * 46. Permutations
     * 47. Permutations II
     * 77. Combinations
     * 39. Combination Sum
     * 40. Combination Sum II
     * 216. Combination Sum III
     * 377. Combination Sum IV
     * 131. Palindrome Partition
     * 301. Remove Invalid Parentheses (https://leetcode.com/problems/remove-invalid-parentheses/description/)
     */

    /****************** Solution 1: Sort + Backtracking *******************/
    /**
     * 39. Combination Sum    => distinct candidates + reusable
     * 40. Combination Sum II => not distinct candidates + not reusable
     * but both require distinct combinations as result.
     *
     * Problem	           Reuse allowed?	Max depth	Time complexity
     * Combination Sum I	  ✅ yes	      T / m	       O(n^(T/m))
     * Combination Sum II	  ❌ no	          n	           O(2^n)
     *
     * Time Complexity: O(2^N)   Space Complexity: O(N)
     */
    List<List<Integer>> res;
    int[] candidates;

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        res = new ArrayList<>();
        // ⚠️注意⚠️跟 39. Combination Sum 不同的是，这个 sort 必备！！！
        Arrays.sort(candidates);
        this.candidates = candidates;
        recur(new ArrayList<>(), 0, target);
        return res;
    }

    private void recur(List<Integer> path, int start, int remain) {
        if (remain == 0) {
            res.add(new ArrayList<>(path));
            return;
        }
        for (int i = start; i < candidates.length && candidates[i] <= remain; i++) {
            // ⚠️注意⚠️不然对于 candidates=[10,1,2,7,6,1,5], target=8，会返回两个[1,7]
            if (i != start && candidates[i] == candidates[i - 1]) continue;
            path.add(candidates[i]);
            recur(path, i + 1, remain - candidates[i]);
            path.remove(path.size() - 1);
        }
    }
}
