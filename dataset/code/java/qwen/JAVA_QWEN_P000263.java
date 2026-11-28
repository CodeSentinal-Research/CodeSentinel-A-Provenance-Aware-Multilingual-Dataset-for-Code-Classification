import java.util.Scanner;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        
        HashMap<Character, Integer> map = new HashMap<>();
        for (char c : s.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }
        
        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s.charAt(i);
            if (map.get(c) == 1) {
                System.out.println(c);
                return;
            }
        }
        System.out.println(-1);
    }
}
