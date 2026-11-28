import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long result = n;
        long temp = n;
        for(long i=2; i*i<=temp; i++) {
            if(temp % i == 0) {
                while(temp % i == 0) temp /= i;
                result -= result / i;
            }
        }
        if(temp > 1) result -= result / temp;
        System.out.println(result);
    }
}
