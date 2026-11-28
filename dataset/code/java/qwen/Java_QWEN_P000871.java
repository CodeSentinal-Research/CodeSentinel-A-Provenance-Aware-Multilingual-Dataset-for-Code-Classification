import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long left = sc.nextLong();
        long right = sc.nextLong();
        
        while(left < right) {
            right = right & (right - 1);
        }
        System.out.println(right);
    }
}
