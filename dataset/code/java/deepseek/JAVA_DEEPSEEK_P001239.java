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
        int newStart = scanner.nextInt();
        int newEnd = scanner.nextInt();
        intervals.add(new Interval(newStart, newEnd));
        Collections.sort(intervals, Comparator.comparing((Interval i) -> i.start).thenComparing(i -> i.end));
        List<Interval> merged = new ArrayList<>();
        merged.add(intervals.get(0));
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals.get(i).start <= merged.get(merged.size() - 1).end) {
                merged.get(merged.size() - 1).end = Math.max(merged.get(merged.size() - 1).end, intervals.get(i).end);
            } else {
                merged.add(intervals.get(i));
            }
        }
        for (Interval interval : merged) {
            System.out.println(interval.start + " " + interval.end);
        }
    }
}

class Interval {
    int start;
    int end;

    public Interval(int start, int end) {
        this.start = start;
        this.end = end;
    }
}
