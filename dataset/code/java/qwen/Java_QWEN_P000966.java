import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long x = sc.nextLong();
        int n = sc.nextInt();
        boolean valid = true;
        for(int i=0; i<n; i++) {
            long r = sc.nextLong();
            long m = sc.nextLong();
            if(x % m != r) valid = false;
        }
        System.out.println(valid ? "true" : "false");
    }
}
