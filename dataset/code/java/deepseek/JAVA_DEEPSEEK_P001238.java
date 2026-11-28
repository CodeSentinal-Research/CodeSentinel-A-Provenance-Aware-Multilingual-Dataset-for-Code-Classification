import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Interval> intervals = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int start = scanner.nextInt();
            int end = scanner.nextInt();
            intervals.add(new Interval(start, end));
        }
        List<Interval> merged = merge(intervals);
        for (Interval interval : merged) {
            System.out.println(interval.start + " " + interval.end);
        }
    }

    public static List<Interval> merge(List<Interval> intervals) {
        Collections.sort(intervals, Comparator.comparing(interval -> interval.start));
        LinkedList<Interval> merged = new LinkedList<>();
        for (Interval interval : intervals) {
            if (merged.isEmpty() || merged.getLast().end < interval.start) {
                merged.add(interval);
            } else {
                merged.getLast().end = Math.max(merged.getLast().end, interval.end);
            }
        }
        return merged;
    }

    public static class Interval {
        int start;
        int end;

        public Interval(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }
}
