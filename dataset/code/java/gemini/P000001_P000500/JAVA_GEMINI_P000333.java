import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            List<Integer>[] pos = new ArrayList[26];
            for (int i = 0; i < 26; i++) pos[i] = new ArrayList<>();
            for (int i = 0; i < s.length(); i++) {
                pos[s.charAt(i) - 'a'].add(i);
            }
            int count = 0;
            while (scanner.hasNext()) {
                String w = scanner.next();
                int curr = -1;
                boolean ok = true;
                for (char c : w.toCharArray()) {
                    List<Integer> list = pos[c - 'a'];
                    int idx = Collections.binarySearch(list, curr + 1);
                    if (idx < 0) idx = -idx - 1;
                    if (idx >= list.size()) {
                        ok = false;
                        break;
                    }
                    curr = list.get(idx);
                }
                if (ok) count++;
            }
            System.out.println(count);
        }
    }
}