import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        
        char[] chars = s.toCharArray();
        int left = 0, right = chars.length - 1;
        
        while (left < right) {
            while (left < right && !Character.isLetter(chars[left])) left++;
            while (left < right && !Character.isLetter(chars[right])) right--;
            
            if (Character.isLetter(chars[left]) && Character.isLetter(chars[right])) {
                char temp = chars[left];
                chars[left] = chars[right];
                chars[right] = temp;
                left++;
                right--;
            }
        }
        
        System.out.println(new String(chars));
    }
}
