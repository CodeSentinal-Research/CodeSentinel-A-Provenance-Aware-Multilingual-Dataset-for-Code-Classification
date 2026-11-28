import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        
        StringBuilder compressed = new StringBuilder();
        int count = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == s.charAt(i - 1)) {
                count++;
            } else {
                compressed.append(s.charAt(i - 1));
                if (count > 1) {
                    compressed.append(count);
                }
                count = 1;
            }
        }
        // Append last character
        compressed.append(s.charAt(s.length() - 1));
        if (count > 1) {
            compressed.append(count);
        }
        
        String result = compressed.toString();
        // If compression doesn't help, return original? Problem says "perform basic string compression"
        // Usually implies returning the compressed string regardless.
        System.out.println(result.length() < s.length() ? result : s);
    }
}
