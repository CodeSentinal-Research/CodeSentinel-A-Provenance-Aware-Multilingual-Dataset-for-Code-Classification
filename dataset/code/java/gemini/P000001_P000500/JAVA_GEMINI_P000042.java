import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            char ch = Character.toLowerCase(scanner.next().charAt(0));
            boolean isVowel = "aeiou".indexOf(ch) != -1;
            System.out.println(isVowel ? "Vowel" : "Consonant");
        }
    }
}