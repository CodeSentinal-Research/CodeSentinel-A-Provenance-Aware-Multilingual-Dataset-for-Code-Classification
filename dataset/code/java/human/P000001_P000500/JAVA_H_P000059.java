/*
15. WAJP to find product of digits
*/
package Capgemini.training.DaySix;
import java.util.Scanner;
class loopTask15 {
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);

        System.out.print("Enter the number :");
        int num=input.nextInt();
        int result=productOfDigits(num);
        System.out.print("The product of the number is :"+result);

    }

    public static int productOfDigits(int num){
        int pro=1,digit=0;

        while (num>0){
            digit=num%10;
            pro=digit*pro;
            num=num/10;
        }
        return pro;
    }
}
