import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        
        int left = 0, right = s.length() - 1;
        while(left < right) {
            if(s.charAt(left) != s.charAt(right)) {
                String s1 = s.substring(left + 1, right + 1);
                String s2 = s.substring(left, right);
                if(isPalin(s1) || isPalin(s2)) {
                    System.out.println("YES");
                } else {
                    System.out.println("NO");
                }
                return;
            }
            left++;
            right--;
        }
        System.out.println("YES");
    }
    static boolean isPalin(String s) {
        int l = 0, r = s.length() - 1;
        while(l < r) {
            if(s.charAt(l++) != s.charAt(r--)) return false;
        }
        return true;
    }
}
