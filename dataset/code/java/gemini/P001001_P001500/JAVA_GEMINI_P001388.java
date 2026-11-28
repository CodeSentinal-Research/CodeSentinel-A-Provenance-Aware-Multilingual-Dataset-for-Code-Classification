import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), k = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

            Map<Integer, Integer> map = new HashMap<>();
            List<Integer> res = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                map.put(arr[i], map.getOrDefault(arr[i], 0) + 1);

                if (i >= k) {
                    int out = arr[i - k];
                    if (map.get(out) == 1) map.remove(out);
                    else map.put(out, map.get(out) - 1);
                }

                if (i >= k - 1) {
                    res.add(map.size());
                }
            }

            for (int i = 0; i < res.size(); i++) {
                System.out.print(res.get(i) + (i + 1 == res.size() ? "" : " "));
            }
            System.out.println();
        }
        sc.close();
    }
}