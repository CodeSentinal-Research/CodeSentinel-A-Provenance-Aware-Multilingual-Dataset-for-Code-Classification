import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char c = Character.toLowerCase(sc.next().charAt(0));
        boolean isVowel = "aeiou".indexOf(c) != -1;
        System.out.println(isVowel ? "Vowel" : "Consonant");
    }
}
