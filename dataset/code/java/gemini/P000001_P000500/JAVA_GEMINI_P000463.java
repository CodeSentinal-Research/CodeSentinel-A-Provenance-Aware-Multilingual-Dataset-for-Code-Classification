import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n1 = scanner.nextInt(), n2 = scanner.nextInt(), n3 = scanner.nextInt();
            int[] a = new int[n1], b = new int[n2], c = new int[n3];
            for (int i = 0; i < n1; i++) a[i] = scanner.nextInt();
            for (int i = 0; i < n2; i++) b[i] = scanner.nextInt();
            for (int i = 0; i < n3; i++) c[i] = scanner.nextInt();
            int i = 0, j = 0, k = 0;
            Set<Integer> res = new TreeSet<>();
            while (i < n1 && j < n2 && k < n3) {
                if (a[i] == b[j] && b[j] == c[k]) {
                    res.add(a[i]);
                    i++; j++; k++;
                } else if (a[i] < b[j]) i++;
                else if (b[j] < c[k]) j++;
                else k++;
            }
            if (res.isEmpty()) {
                System.out.println(-1);
            } else {
                StringBuilder sb = new StringBuilder();
                for (int v : res) sb.append(v).append(" ");
                System.out.println(sb.toString().trim());
            }
        }
    }
}