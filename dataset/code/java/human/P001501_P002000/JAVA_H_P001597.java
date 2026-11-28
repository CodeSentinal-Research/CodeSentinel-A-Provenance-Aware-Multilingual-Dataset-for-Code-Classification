import java.util.ArrayList;
import java.util.Scanner;
import java.util.Arrays;
import java.util.Random;

public class Main {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        /*
        1.Write a program to find all of the longest word in a given dictionary.
            Example:
            { "cat", "dog", "red", "is", "am" } Expected
            Output:
            "cat", "dog", "red"

        Solution:

                int length;


        System.out.println("Enter, how many names you want to enter: ");
        length = input.nextInt();

        String [] names = new String [length];

        ArrayList<String> largestNames = new ArrayList<>();

        for(int i = 0; i < length; i++){
            System.out.println("Enter a name: ");
            names[i] = input.next();
        }

        System.out.println(Arrays.toString(names));

        int maxlength = 0;
        for(String n: names){
            if(n.length() > maxlength){
                maxlength = n.length();
            }
        }

        for(String n: names){
            if(n != null && n.length() == maxlength){
                largestNames.add(n);
            }
        }

        for(String n: largestNames){
            System.out.println(n);
        }


        2. Write a program that displays the number of occurrences of an element in the array.
            Original Array:
            [1,1,1,3,3,5]
            Sample Output:
            3 occurs 2 times
            1 occurs 3 times
            9 occurs 0 time

       Solution:

         System.out.print("Enter, how many numbers you want to add: ");
        int length = input.nextInt();

        int[] numbers = new int[length];

        for (int i = 0; i < length; i++) {
            System.out.println("Enter a numbers:");
            numbers[i] = input.nextInt();
        }

        boolean[] visited = new boolean[length];


        for (int i = 0; i < length; i++) {

            if (visited[i]) {
                continue;
            }

            int count = 1;

            for (int j = i + 1; j < length; j++) {
                if (numbers[i] == numbers[j]) {
                    count++;
                    visited[j] = true;
                }
            }
            System.out.println(numbers[i] + " occurs " + count + " time(s)");
        }


        3.Write a program to find the k largest elements in a given array. Elements in the array can be in
            any order.


        Solution:

                 int length ;
        System.out.println("Enter how many numbers you want to enter: ");
        length = input.nextInt();
        int [] numbers = new int[length];
        int first = Integer.MIN_VALUE;
        int second = Integer.MIN_VALUE;
        int third = Integer.MIN_VALUE;

        for (int i = 0; i < length; i++) {
            System.out.println("Enter a number: ");
            numbers[i] = input.nextInt();
        }


        for(int num: numbers) {
            if(num > first) {
                third = second;
                second = first;
                first = num;
            }else if(num > second) {
                second = num;
                third = second;

            } else if (num > third) {
                third = num;
            }
        }

        System.out.println(Arrays.toString(numbers));
        System.out.println("3 largest elements of the said array are: " +first+ " "+ second+ " "+ third);


        4. Create a method to reverse an array of integers. Implement the method without creating a new
            array.
            Original Array:
            [5,4,3,2,1] Expected Output:
            Reversed Array:
            1 2 3 4 5

            Solution:

             int length;

        System.out.println("Enter, how many numbers you want to enter: ");
        length = input.nextInt();

        int [] numbers = new int[length];

        for (int i = 0; i < numbers.length; i++) {
            System.out.println("Enter a number: ");
            numbers[i] = input.nextInt();
        }

        System.out.println(Arrays.toString(numbers));

        ArrayList <String> reversedArray = new ArrayList<>();
        for(int i = numbers.length-1; i >= 0; i--) {
            reversedArray.add(numbers[i] + "");
        }
        System.out.println(reversedArray);


        5. Write a menu driven Java program with following option:
            1. Accept elements of an array
            2. Display elements of an array
            3. Search the element within array
            4. Sort the array  5. To Stop the size of the array should be
            entered by the user.


         Solution:

             int choice;
        int length;
        int[] numbers = new int[0];

        do {
            System.out.println(
                    "1. Accept elements of an array\n" +
                            "2. Display elements of an array\n" +
                            "3. Search the element within array\n" +
                            "4. Sort the array\n" +
                            "5. To Stop");
            choice = input.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("How many numbers do you want to enter?");
                    length = input.nextInt();
                    numbers = new int[length];
                    for (int i = 0; i < length; i++) {
                        System.out.print("Enter number " + (i + 1) + ": ");
                        numbers[i] = input.nextInt();
                    }
                    break;

                case 2:
                    System.out.println("Array elements: " + Arrays.toString(numbers));
                    break;

                case 3:
                    System.out.print("Enter the element to search: ");
                    int search = input.nextInt();
                    boolean found = false;
                    for (int num : numbers) {
                        if (num == search) {
                            found = true;
                            break;
                        }
                    }
                    System.out.println(found ? "Element found!" : "Element not found.");
                    break;

                case 4: if (numbers.length == 0) {
                    System.out.println("Array is empty. Enter values first.");
                } else {

                    for (int i = 0; i < numbers.length - 1; i++) {
                        for (int j = 0; j < numbers.length - i - 1; j++) {
                            if (numbers[j] > numbers[j + 1]) {

                                int temp = numbers[j];
                                numbers[j] = numbers[j + 1];
                                numbers[j + 1] = temp;
                            }
                        }
                    }
                    System.out.print("Array sorted: ");
                    for (int num : numbers) {
                        System.out.print(num + " ");
                    }
                    System.out.println();
                }
                    break;

                case 5:
                    System.out.println("Exiting...");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }

        } while (choice != 5);

        6. Create a method that generates a random number within a given range. Allow the user to
            specify the range and call the method to display random numbers.
            Hint: use Random class
            Sample Output:
                2
                Enter the minimum value of the range: 10
                Enter the maximum value of the range: 100
                Enter the number of random numbers to generate: 5 Random
                numbers within the specified range:
                71 - 98 - 96 - 71 - 71



        Solution:

             Random rand = new Random();

        System.out.print("Enter the minimum value of the range: ");
        int min = input.nextInt();

        System.out.print("Enter the maximum value of the range: ");
        int max = input.nextInt();

        System.out.print("Enter the number of random numbers to generate: ");
        int count = input.nextInt();


        if (min > max) {
            System.out.println("Invalid range. Minimum must be less than or equal to maximum.");
        } else {
            System.out.println("Random numbers within the specified range:");
            for (int i = 0; i < count; i++) {
                int randomNum = rand.nextInt(max - min + 1) + min;
                System.out.println(randomNum);
            }
      }

    7. Write a program that checks the strength of a password. Create a method that evaluates a
        password based on criteria like length, inclusion of special characters, and
        uppercase/lowercase letters.  - - -
        We have three methods: checkLength, checkSpecialCharacters, and
        checkUpperCaseLowerCase, each of which assigns a score based on specific criteria.
        The totalScore is calculated by adding the scores from these methods.
        Classify the password as strong (8 or more), moderately strong (5 or more), or weak
        based on the totalScore. -
        The criteria for scoring:
        • Length: 0-5 characters (0 points), 6-7 characters (2 points), 8 or more characters
        (3 points).
        • Special characters: Absence (0 points), Presence (2 points).
        • Uppercase and lowercase letters: Absence of both (0 points), presence of both (3
        points).


     Solution:

         String password;
        System.out.println("Enter your password:");
        password = input.nextLine();

       String result = classification(password);
       System.out.println(result);
    }


        After main block:



         public static int checkLength(String password) {

        int length = password.length();
        if (length >= 8)
            return 3;
        else if (length >= 6 && length < 8)
            return 2;

        else
            return 0;
    }

    public static int checkSpecialCharacters(String password) {
        if(password.matches(".*[!@#$%^&*()_+=/|].*"))
        return 2;
        else
            return 0;

    }


    public static int checkUpperCaseLowerCase(String password) {
        boolean hasUpperCase = false;
        boolean hasLowerCase = false;

        for(char ch : password.toCharArray()) {
            if(Character.isUpperCase(ch))
                hasUpperCase = true;
            else if(Character.isLowerCase(ch))
                hasLowerCase = true;
        }
      if (hasUpperCase == true && hasLowerCase == true)
          return 3;
      else
          return 0;
    }

    public static String classification(String password) {
        int checkLengthScore = checkLength(password);
        int checkSpecialCharactersScore = checkSpecialCharacters(password);
        int checkUpperCaseLowerCaseScore =  checkUpperCaseLowerCase(password);

        int totalScore = checkLengthScore + checkSpecialCharactersScore + checkUpperCaseLowerCaseScore;
        System.out.println(checkLengthScore);
        System.out.println(checkSpecialCharactersScore);
        System.out.println(checkUpperCaseLowerCaseScore);

        if(totalScore >= 8) {
            return "Strong password!";
        }else if(totalScore > 5 && totalScore < 8) {
            return "moderately strong!";
        }else
            return "weak password!";

      8. Create a method that generates the Fibonacci sequence up to a specified number of terms.
        Hint: The Fibonacci sequence is a mathematical sequence of numbers that starts with 0 and 1,
        and each subsequent number in the sequence is the sum of the two preceding ones.

       Solution:

        int number;
        System.out.println("Enter the number of Fibonacci terms to generate:");
        number = input.nextInt();

        generateFibonacci(number);

      After main block

        public static void generateFibonacci ( int n){
        int first = 0, second = 1;

        for (int i = 0; i < n; i++) {
            System.out.print(first + " ");

            int next = first + second;
            first = second;
            second = next;
        }

        }

   */



    }

}