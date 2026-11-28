import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<String> tokens = new ArrayList<>();
        while (scanner.hasNext()) tokens.add(scanner.next());
        if (!tokens.isEmpty()) {
            String s = tokens.get(tokens.size() - 1);
            int count = 0;
            for (int i = 0; i < tokens.size() - 1; i++) {
                if (s.startsWith(tokens.get(i))) count++;
            }
            System.out.println(count);
        }
    }
}