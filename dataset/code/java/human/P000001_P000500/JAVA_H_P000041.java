// import java.util.*;

// class extra{
//     public static void printName(String name) {
//         System.out.println(name);
//         return  ;
        
//     }

//     public static void main(String[] args) {
//         Scanner sc=new Scanner(System.in);
//         String name=sc.next();
//         printName(name);
//         sc.close();
//     }
    
// }
// +-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

// import java.util.Scanner;

// class AverageCalculator {
    
//     // Function to calculate average of three numbers
//     public static double findAverage(int a, int b, int c) {
//         return (a + b + c) / 3.0; // use 3.0 to get decimal result
//     }

//     public static void main(String[] args) {
//         Scanner sc = new Scanner(System.in);

//         // Taking 3 numbers from user
//         System.out.print("Enter first number: ");
//         int num1 = sc.nextInt();

//         System.out.print("Enter second number: ");
//         int num2 = sc.nextInt();

//         System.out.print("Enter third number: ");
//         int num3 = sc.nextInt();

//         // Call function and display result
//         double avg = findAverage(num1, num2, num3);
//         System.out.println("Average = " + avg);

//         sc.close();
//     }
// }

import java.util.Scanner;

class avgcal {
    public static int findAvg(int a,int b,int c) {
        return(a+b+c)/3;

        }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        // taking 3 num
        System.out.println("input the frist num=");
        int num1=sc.nextInt();
        System.out.println("input the second num=");
        int num2=sc.nextInt();
        System.out.println("input the third num=");
        int num3=sc.nextInt();

        // now calling the function

        int call=findAvg(num1, num2, num3);
        System.out.println("the avg is="+call);

        sc.close();



        
    }


}