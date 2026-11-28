import java.util.Stack;

public class Solution {
    // Sorts the input array into ordered sequence.
    public int maxChunksToSorted(int[] arr) {
        Stack<Integer> stack = new Stack<>();
        for (int x : arr) {
            int curMax = x;
            // Maintain monotonic stack property by popping smaller elements
            while (!stack.isEmpty() && stack.peek() > x) {
                curMax = Math.max(curMax, stack.pop());
            }
            stack.push(curMax);
        }
        return stack.size();
    }
}