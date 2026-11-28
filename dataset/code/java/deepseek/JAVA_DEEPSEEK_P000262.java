import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        System.out.println(firstNonRepeatingCharacter(input));
    }

    public static char firstNonRepeatingCharacter(String str) {
        Map<Character, Integer> charCountMap = new LinkedHashMap<>();
        for (int i = 0; i < str.length(); i++) {
            charCountMap.put(str.charAt(i), charCountMap.getOrDefault(str.charAt(i), 0) + 1);
        }

        for (Map.Entry<Character, Integer> entry : charCountMap.entrySet()) {
            if (entry.getValue() == 1) {
                return entry.getKey();
            }
        }

        return (char)-1;
    }
}