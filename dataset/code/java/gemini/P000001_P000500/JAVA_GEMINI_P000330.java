import java.util.*;

public class Solution {
    public static String addBoldTag(String s, List<String> words) {
        int n = s.length();
        boolean[] bold = new boolean[n];
        for (String w : words) {
            int pos = s.indexOf(w);
            while (pos != -1) {
                for (int i = pos; i < pos + w.length(); i++) bold[i] = true;
                pos = s.indexOf(w, pos + 1);
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; ) {
            if (bold[i]) {
                sb.append("<b>");
                while (i < n && bold[i]) {
                    sb.append(s.charAt(i++));
                }
                sb.append("</b>");
            } else {
                sb.append(s.charAt(i++));
            }
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            List<String> words = new ArrayList<>();
            while (scanner.hasNext()) {
                words.add(scanner.next());
            }
            System.out.println(addBoldTag(s, words));
        }
    }
}