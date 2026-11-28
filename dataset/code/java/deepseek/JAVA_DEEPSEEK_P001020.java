import java.util.*;

public class Main {
    static class Pair implements Comparable<Pair> {
        int val;
        int listIndex;
        int elementIndex;

        public Pair(int val, int listIndex, int elementIndex) {
            this.val = val;
            this.listIndex = listIndex;
            this.elementIndex = elementIndex;
        }

        @Override
        public int compareTo(Pair o) {
            return this.val - o.val;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int k = scanner.nextInt();
        List<List<Integer>> lists = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            int n = scanner.nextInt();
            List<Integer> list = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                list.add(scanner.nextInt());
            }
            lists.add(list);
        }
        System.out.println(Arrays.toString(findSmallestRange(lists)));
    }

    private static int[] findSmallestRange(List<List<Integer>> lists) {
        PriorityQueue<Pair> queue = new PriorityQueue<>();
        for (int i = 0; i < lists.size(); i++) {
            if (!lists.get(i).isEmpty()) {
                queue.offer(new Pair(lists.get(i).get(0), i, 0));
            }
        }

        int start = Integer.MAX_VALUE;
        int end = Integer.MAX_VALUE;
        int minLen = Integer.MAX_VALUE;
        while (!queue.isEmpty()) {
            Pair smallest = queue.poll();
            if (smallest.val >= start && smallest.val <= end) {
                if (smallest.val < start) {
                    start = smallest.val;
                    end = smallest.val;
                }
                if (smallest.elementIndex + 1 == lists.get(smallest.listIndex).size()) {
                    if (smallest.val < start) {
                        start = smallest.val;
                    }
                    if (smallest.val > end) {
                        end = smallest.val;
                    }
                } else {
                    int nextVal = smallest.val + lists.get(smallest.listIndex).get(smallest.elementIndex + 1) - lists.get(smallest.listIndex).get(smallest.elementIndex);
                    queue.offer(new Pair(nextVal, smallest.listIndex, smallest.elementIndex + 1));
                    if (nextVal < start) {
                        start = nextVal;
                    }
                    if (nextVal > end) {
                        end = nextVal;
                    }
                }
            }
        }
        return new int[]{start, end};
    }
}
