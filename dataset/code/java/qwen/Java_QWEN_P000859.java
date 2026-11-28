import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int res = 0;
        for(int i=0; i<32; i++) {
            res <<= 1;
            res |= (n & 1);
            n >>= 1;
        }
        System.out.println(res);
    }
}
