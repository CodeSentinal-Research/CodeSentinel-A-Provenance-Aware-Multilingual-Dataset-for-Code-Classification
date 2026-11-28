import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();
        
        int[] map = new int[128];
        for (char c : t.toCharArray()) {
            map[c]++;
        }
        
        int left = 0, right = 0;
        int counter = t.length();
        int minLen = Integer.MAX_VALUE;
        int head = 0;
        
        while (right < s.length()) {
            if (map[s.charAt(right)] > 0) {
                counter--;
            }
            map[s.charAt(right)]--;
            right++;
            
            while (counter == 0) {
                if (right - left < minLen) {
                    minLen = right - left;
                    head = left;
                }
                
                if (map[s.charAt(left)] == 0) {
                    counter++;
                }
                map[s.charAt(left)]++;
                left++;
            }
        }
        
        if (minLen == Integer.MAX_VALUE) {
            System.out.println("");
        } else {
            System.out.println(s.substring(head, head + minLen));
        }
    }
}
