import java.util.*;

public class Solution {
    static class Item {
        int val, wt;
        Item(int val, int wt) { this.val = val; this.wt = wt; }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), w = sc.nextInt();
            Item[] items = new Item[n];
            for (int i = 0; i < n; i++) {
                int val = sc.nextInt();
                int wt = sc.nextInt();
                items[i] = new Item(val, wt);
            }

            Arrays.sort(items, (a, b) -> Double.compare((double)b.val / b.wt, (double)a.val / a.wt));
            double totalVal = 0.0;
            int cap = w;

            for (Item it : items) {
                if (cap >= it.wt) {
                    totalVal += it.val;
                    cap -= it.wt;
                } else {
                    totalVal += (double)it.val * ((double)cap / it.wt);
                    break;
                }
            }
            System.out.printf(Locale.US, "%.6f\n", totalVal);
        }
        sc.close();
    }
}