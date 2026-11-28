import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Solution {
    static class Element implements Comparable<Element> {
        int val, r, c;
        Element(int val, int r, int c) { this.val = val; this.r = r; this.c = c; }
        public int compareTo(Element o) { return Integer.compare(this.val, o.val); }
    }

    public static List<Integer> mergeKSortedArrays(int[][] arrays) {
        PriorityQueue<Element> pq = new PriorityQueue<>();
        for (int i = 0; i < arrays.length; i++) {
            if (arrays[i].length > 0) pq.offer(new Element(arrays[i][0], i, 0));
        }
        List<Integer> res = new ArrayList<>();
        while (!pq.isEmpty()) {
            Element cur = pq.poll();
            res.add(cur.val);
            if (cur.c + 1 < arrays[cur.r].length) {
                pq.offer(new Element(arrays[cur.r][cur.c + 1], cur.r, cur.c + 1));
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int k = sc.nextInt();
            int n = sc.nextInt();
            int[][] arrays = new int[k][n];
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < n; j++) arrays[i][j] = sc.nextInt();
            }
            List<Integer> res = mergeKSortedArrays(arrays);
            for (int i = 0; i < res.size(); i++) {
                System.out.print(res.get(i) + (i == res.size() - 1 ? "" : " "));
            }
            System.out.println();
        }
        sc.close();
    }
}