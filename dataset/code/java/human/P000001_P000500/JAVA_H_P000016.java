package exercicios.java;
import java.util.Scanner;

class ConvertCelsiusFahrenheit {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        
        System.out.println("------------------------------------------------------");
        System.out.println("         CONVERTING CELSIUS TO FAHRENHEINT"      );
        System.out.println("------------------------------------------------------");

        System.out.print("Enter the temperature in Celsius: ");
        double celsius = input.nextDouble();
        
        // Converting Celsius to Fahrenheit
        double convert = (celsius * 9/5) + 32;

        System.out.println("The temperature of " + celsius + "°C is equal to " + convert + "°F.");
        input.close();
    }

}