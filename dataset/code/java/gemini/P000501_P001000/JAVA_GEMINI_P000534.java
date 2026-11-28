import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            int n = s.length();
            Queue<Integer> rQ = new LinkedList<>(), dQ = new LinkedList<>();
            for (int i = 0; i < n; i++) {
                if (s.charAt(i) == 'R') rQ.add(i);
                else dQ.add(i);
            }
            while (!rQ.isEmpty() && !dQ.isEmpty()) {
                int rIdx = rQ.poll(), dIdx = dQ.poll();
                if (rIdx < dIdx) rQ.add(rIdx + n);
                else dQ.add(dIdx + n);
            }
            System.out.println(rQ.isEmpty() ? "Dire" : "Radiant");
        }
    }
}