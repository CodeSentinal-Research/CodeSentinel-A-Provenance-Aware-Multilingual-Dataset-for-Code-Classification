import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String word = scanner.next();
        List<String> result = generateAbbreviations(word);
        for (String s : result) {
            System.out.println(s);
        }
    }

    public static List<String> generateAbbreviations(String word) {
        List<String> result = new ArrayList<>();
        int n = word.length();
        for (int mask = 0; mask < (1 << n); ++mask) {
            StringBuilder abbreviation = new StringBuilder();
            int count = 0;
            for (int i = 0; i < n; ++i) {
                if ((mask & (1 << i)) != 0) {
                    ++count;
                } else {
                    if (count != 0) {
                        abbreviation.append(count);
                        count = 0;
                   }
                    abbreviation.append(word.charAt(i));
                }
            }

            if (count != 0) {
                abbreviation.append(count);
            }

            result.add(abbreviation.toString());
        }

        Collections.sort(result);
        return result;
    }
}
