import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        if(n == 0) { System.out.println(32); return; }
        int count = 0;
        while((n & 1) == 0) {
            count++;
            n >>= 1;
        }
        System.out.println(count);
    }
}
