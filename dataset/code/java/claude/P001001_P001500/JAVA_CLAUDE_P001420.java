import java.util.Scanner;
public class Solution {
    public double calculate(double a, char op, double b) {
        switch(op){case '+':return a+b;case '-':return a-b;case '*':return a*b;
        case '/':return b!=0?a/b:Double.NaN;default:return 0;}
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double a=sc.nextDouble(); char op=sc.next().charAt(0); double b=sc.nextDouble();
        if(op=='/'&&b==0){System.out.println("Division by zero");return;}
        System.out.printf("%.2f%n", new Solution().calculate(a,op,b));
    }
}
