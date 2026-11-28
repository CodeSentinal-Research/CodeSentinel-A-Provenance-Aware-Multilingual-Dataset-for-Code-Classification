import java.util.List;
import java.util.PriorityQueue;

public class Solution {
    static class Element {
        int val, r, c;
        Element(int val, int r, int c) { this.val = val; this.r = r; this.c = c; }
    }

    public int[] smallestRange(List<List<Integer>> nums) {
        PriorityQueue<Element> pq = new PriorityQueue<>((a, b) -> a.val - b.val);
        int curMax = Integer.MIN_VALUE;
        for (int i = 0; i < nums.size(); i++) {
            int val = nums.get(i).get(0);
            pq.offer(new Element(val, i, 0));
            curMax = Math.max(curMax, val);
        }

        int start = pq.peek().val, end = curMax;
        while (true) {
            Element cur = pq.poll();
            if (cur.c + 1 == nums.get(cur.r).size()) break;
            int nextVal = nums.get(cur.r).get(cur.c + 1);
            curMax = Math.max(curMax, nextVal);
            pq.offer(new Element(nextVal, cur.r, cur.c + 1));
            if (curMax - pq.peek().val < end - start) {
                start = pq.peek().val;
                end = curMax;
            }
        }
        return new int[]{start, end};
    }
}