import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.next();
        System.out.println(getLastNonRepeatingCharacter(input));
    }

    private static String getLastNonRepeatingCharacter(String str) {
        Map<Character, Integer> charCountMap = new LinkedHashMap<>();
        for (int i = 0; i < str.length(); i++) {
            charCountMap.put(str.charAt(i), charCountMap.getOrDefault(str.charAt(i), 0) + 1);
        }

        for (int i = str.length() - 1; i >= 0; i--) {
            if (charCountMap.get(str.charAt(i)) == 1) {
                return String.valueOf(str.charAt(i));
            }
        }

        return "-1";
    }
}