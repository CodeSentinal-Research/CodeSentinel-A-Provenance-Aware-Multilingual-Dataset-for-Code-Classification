import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<String> res = new ArrayList<>();
        while (scanner.hasNext()) {
            String s = scanner.next();
            if (!s.equals("null") && !s.equals("#") && !s.equals("N")) res.add(s);
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < res.size(); i++) {
            sb.append(res.get(i)).append(i + 1 == res.size() ? "" : " ");
        }
        System.out.println(sb.toString());
    }
}