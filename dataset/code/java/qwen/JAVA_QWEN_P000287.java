import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        
        char[] chars = s.toCharArray();
        int left = 0, right = chars.length - 1;
        String vowels = "aeiouAEIOU";
        
        while (left < right) {
            while (left < right && vowels.indexOf(chars[left]) == -1) left++;
            while (left < right && vowels.indexOf(chars[right]) == -1) right--;
            
            if (left < right) {
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
