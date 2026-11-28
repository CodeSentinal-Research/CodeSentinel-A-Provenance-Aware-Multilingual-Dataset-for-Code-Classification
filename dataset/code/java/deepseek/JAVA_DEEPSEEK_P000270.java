import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a sentence:");
        String sentence = scanner.nextLine();
        System.out.println(capitalizeFirstLetterOfEachWord(sentence));
    }

    public static String capitalizeFirstLetterOfEachWord(String sentence) {
        if (sentence == null || sentence.length() == 0) {
            return sentence;
        }

        String[] words = sentence.split(" ");
        StringBuilder result = new StringBuilder();

        for (String word : words) {
            result.append(Character.toUpperCase(word.charAt(0)));
            result.append(word.substring(1).toLowerCase());
            result.append(" ");
       
        }

        return result.toString().trim();
    }
}