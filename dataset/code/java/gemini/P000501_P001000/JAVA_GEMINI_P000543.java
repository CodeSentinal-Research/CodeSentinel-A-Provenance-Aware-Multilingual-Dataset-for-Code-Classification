import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int q = scanner.nextInt();
            TreeSet<Integer> nums = new TreeSet<>();
            while (q-- > 0) {
                String cmd = scanner.next();
                if (cmd.equals("addNum")) {
                    nums.add(scanner.nextInt());
                } else if (cmd.equals("getIntervals")) {
                    List<int[]> intervals = new ArrayList<>();
                    for (int x : nums) {
                        if (!intervals.isEmpty() && intervals.get(intervals.size() - 1)[1] + 1 == x) {
                            intervals.get(intervals.size() - 1)[1] = x;
                        } else {
                            intervals.add(new int[]{x, x});
                        }
                    }
                    StringBuilder sb = new StringBuilder();
                    for (int i = 0; i < intervals.size(); i++) {
                        sb.append("[").append(intervals.get(i)[0]).append(",").append(intervals.get(i)[1]).append("]").append(i + 1 == intervals.size() ? "" : " ");
                    }
                    System.out.println(sb.toString());
                }
            }
        }
    }
}