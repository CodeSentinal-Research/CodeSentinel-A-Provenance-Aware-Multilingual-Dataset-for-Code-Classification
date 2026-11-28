import java.util.Scanner;
public class Solution {
    public long climbStairs(int n){
        if(n<=2)return n; long a=1,b=2;
        for(int i=3;i<=n;i++){long c=a+b;a=b;b=c;} return b;
    }
    public static void main(String[] args){
        System.out.println(new Solution().climbStairs(new Scanner(System.in).nextInt()));
    }
}
