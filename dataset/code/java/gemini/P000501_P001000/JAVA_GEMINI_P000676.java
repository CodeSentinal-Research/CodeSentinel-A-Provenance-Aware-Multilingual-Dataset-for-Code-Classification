import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Integer> vals = new ArrayList<>();
        while (scanner.hasNext()) {
            String s = scanner.next();
            if (!s.equals("null") && !s.equals("#") && !s.equals("N")) vals.add(Integer.parseInt(s));
        }
        Collections.sort(vals);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < vals.size(); i++) {
            sb.append(vals.get(i)).append(i + 1 == vals.size() ? "" : " ");
        }
        System.out.println(sb.toString());
    }
}