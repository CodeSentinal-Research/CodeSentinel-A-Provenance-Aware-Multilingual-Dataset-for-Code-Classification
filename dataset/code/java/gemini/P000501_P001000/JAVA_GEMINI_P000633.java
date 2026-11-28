import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<String> tokens = new ArrayList<>();
        while (scanner.hasNext()) tokens.add(scanner.next());
        if (tokens.isEmpty()) return;
        int start = 0;
        try {
            if (tokens.size() > 1 && Integer.parseInt(tokens.get(0)) == tokens.size() - 1) start = 1;
        } catch (Exception e) {}
        StringBuilder sb = new StringBuilder();
        for (int i = start; i < tokens.size(); i++) {
            sb.append(tokens.get(i)).append(i + 1 == tokens.size() ? "" : " ");
        }
        System.out.println(sb.toString());
    }
}