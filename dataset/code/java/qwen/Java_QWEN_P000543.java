import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        TreeSet<Integer> set = new TreeSet<>();
        for(int i=0; i<q; i++) {
            String op = sc.next();
            if(op.equals("addNum")) set.add(sc.nextInt());
            else if(op.equals("getIntervals")) {
                List<int[]> intervals = new ArrayList<>();
                if(set.isEmpty()) {
                    System.out.println("[]");
                    continue;
                }
                int start = set.first(), end = set.first();
                for(int x : set) {
                    if(x > end + 1) {
                        intervals.add(new int[]{start, end});
                        start = x;
                    }
                    end = x;
                }
                intervals.add(new int[]{start, end});
                for(int[] interval : intervals) {
                    System.out.print("[" + interval[0] + "," + interval[1] + "] ");
                }
                System.out.println();
            }
        }
    }
}
