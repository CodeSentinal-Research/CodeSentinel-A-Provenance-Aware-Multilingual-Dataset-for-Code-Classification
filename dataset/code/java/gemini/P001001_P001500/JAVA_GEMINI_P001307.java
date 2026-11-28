import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), k = sc.nextInt();
            List<Integer> police = new ArrayList<>();
            List<Integer> thieves = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                String s = sc.next();
                if (s.equals("P")) police.add(i);
                else thieves.add(i);
            }

            int pIdx = 0, tIdx = 0, caught = 0;
            while (pIdx < police.size() && tIdx < thieves.size()) {
                int p = police.get(pIdx), t = thieves.get(tIdx);
                if (Math.abs(p - t) <= k) {
                    caught++;
                    pIdx++;
                    tIdx++;
                } else if (p < t) {
                    pIdx++;
                } else {
                    tIdx++;
                }
            }
            System.out.println(caught);
        }
        sc.close();
    }
}