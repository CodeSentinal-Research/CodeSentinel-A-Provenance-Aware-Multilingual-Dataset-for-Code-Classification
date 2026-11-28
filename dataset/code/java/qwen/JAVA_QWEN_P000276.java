import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        String current = "1";
        for (int i = 1; i < n; i++) {
            current = countAndSay(current);
        }
        System.out.println(current);
    }
    
    private static String countAndSay(String s) {
        StringBuilder sb = new StringBuilder();
        char currentChar = s.charAt(0);
        int count = 1;
        
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == currentChar) {
                count++;
            } else {
                sb.append(count).append(currentChar);
                currentChar = s.charAt(i);
                count = 1;
            }
        }
        sb.append(count).append(currentChar);
        return sb.toString();
    }
}
