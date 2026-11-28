import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine().replaceAll("[^a-zA-Z0-9]", "").toLowerCase();
        
        int left = 0, right = s.length() - 1;
        boolean isPalin = true;
        while(left < right) {
            if(s.charAt(left) != s.charAt(right)) {
                isPalin = false;
                break;
            }
            left++;
            right--;
        }
        System.out.println(isPalin ? "YES" : "NO");
    }
}
