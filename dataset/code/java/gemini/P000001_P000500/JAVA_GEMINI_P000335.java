import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<String> tokens = new ArrayList<>();
        while (scanner.hasNext()) {
            tokens.add(scanner.next());
        }
        if (!tokens.isEmpty()) {
            String pattern = tokens.get(tokens.size() - 1);
            for (int k = 0; k < tokens.size() - 1; k++) {
                String q = tokens.get(k);
                int i = 0;
                boolean ok = true;
                for (char c : q.toCharArray()) {
                    if (i < pattern.length() && c == pattern.charAt(i)) {
                        i++;
                    } else if (Character.isUpperCase(c)) {
                        ok = false;
                        break;
                    }
                }
                System.out.println((ok && i == pattern.length()) ? "true" : "false");
            }
        }
    }
}