import java.util.Scanner;
public class Solution {
    public String classify(int n) { return n>0?"Positive":n<0?"Negative":"Zero"; }
    public static void main(String[] args) {
        System.out.println(new Solution().classify(new Scanner(System.in).nextInt()));
    }
}
