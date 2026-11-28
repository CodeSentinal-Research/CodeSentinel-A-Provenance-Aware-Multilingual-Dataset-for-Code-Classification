import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] h = new int[n];
            for (int i = 0; i < n; i++) h[i] = scanner.nextInt();
            int l = 0, r = n - 1;
            int lMax = 0, rMax = 0;
            long water = 0;
            while (l < r) {
                if (h[l] < h[r]) {
                    if (h[l] >= lMax) lMax = h[l];
                    else water += lMax - h[l];
                    l++;
                } else {
                    if (h[r] >= rMax) rMax = h[r];
                    else water += rMax - h[r];
                    r--;
                }
            }
            System.out.println(water);
        }
    }
}