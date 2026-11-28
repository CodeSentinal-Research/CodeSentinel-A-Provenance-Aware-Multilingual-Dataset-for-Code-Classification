import java.util.Scanner;
public class Solution {
    public int sumOfDigits(long n) {
        if(n<0) n=-n; int s=0;
        while(n>0){s+=n%10;n/=10;} return s;
    }
    public static void main(String[] args) {
        System.out.println(new Solution().sumOfDigits(new Scanner(System.in).nextLong()));
    }
}
