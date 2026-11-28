import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] vals = new int[n];
            for (int i = 0; i < n; i++) vals[i] = scanner.nextInt();
            int cur = 0, groupLen = 1;
            while (cur < n) {
                int actualLen = Math.min(groupLen, n - cur);
                if (actualLen % 2 == 0) {
                    int l = cur, r = cur + actualLen - 1;
                    while (l < r) {
                        int tmp = vals[l]; vals[l] = vals[r]; vals[r] = tmp;
                        l++; r--;
                    }
                }
                cur += actualLen;
                groupLen++;
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) sb.append(vals[i]).append(i == n - 1 ? "" : " ");
            System.out.println(sb.toString());
        }
    }
}