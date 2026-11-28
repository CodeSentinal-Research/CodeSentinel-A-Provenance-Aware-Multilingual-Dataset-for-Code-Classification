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
        int count = tokens.size() - start;
        // Calculate midpoint to prevent potential overflow
        int mid = (count + 1) / 2;
        StringBuilder sb1 = new StringBuilder(), sb2 = new StringBuilder();
        for (int i = 0; i < mid; i++) sb1.append(tokens.get(start + i)).append(i == mid - 1 ? "" : " ");
        for (int i = mid; i < count; i++) sb2.append(tokens.get(start + i)).append(i == count - 1 ? "" : " ");
        System.out.println(sb1.toString());
        System.out.println(sb2.toString());
    }
}