import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int q = scanner.nextInt();
            Map<String, Integer> counts = new HashMap<>();
            while (q-- > 0) {
                String cmd = scanner.next();
                if (cmd.equals("inc")) {
                    String k = scanner.next();
                    counts.put(k, counts.getOrDefault(k, 0) + 1);
                } else if (cmd.equals("dec")) {
                    String k = scanner.next();
                    int c = counts.getOrDefault(k, 0) - 1;
                    if (c <= 0) counts.remove(k);
                    else counts.put(k, c);
                } else if (cmd.equals("getMaxKey")) {
                    if (counts.isEmpty()) { System.out.println(""); }
                    else {
                        int maxV = -1; String maxK = "";
                        for (Map.Entry<String, Integer> e : counts.entrySet()) {
                            if (e.getValue() > maxV) { maxV = e.getValue(); maxK = e.getKey(); }
                        }
                        System.out.println(maxK);
                    }
                } else if (cmd.equals("getMinKey")) {
                    if (counts.isEmpty()) { System.out.println(""); }
                    else {
                        int minV = Integer.MAX_VALUE; String minK = "";
                        for (Map.Entry<String, Integer> e : counts.entrySet()) {
                            if (e.getValue() < minV) { minV = e.getValue(); minK = e.getKey(); }
                        }
                        System.out.println(minK);
                    }
                }
            }
        }
    }
}