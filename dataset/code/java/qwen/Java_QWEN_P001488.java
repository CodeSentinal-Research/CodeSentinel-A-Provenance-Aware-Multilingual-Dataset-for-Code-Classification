import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        
        int left = 0, right = s.length() - 1;
        while(left < right && s.charAt(left) == s.charAt(right)) {
            char c = s.charAt(left);
            while(left <= right && s.charAt(left) == c) left++;
            while(left <= right && s.charAt(right) == c) right--;
        }
        System.out.println(right - left + 1);
    }
}
