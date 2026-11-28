import java.util.Scanner;
public class Solution {
    public void printPattern(int n) {
        for(int i=1;i<=n;i++){
            StringBuilder sb=new StringBuilder();
            for(int j=0;j<i;j++) sb.append("* ");
            System.out.println(sb.toString().trim());
        }
    }
    public static void main(String[] args) {
        new Solution().printPattern(new Scanner(System.in).nextInt());
    }
}
