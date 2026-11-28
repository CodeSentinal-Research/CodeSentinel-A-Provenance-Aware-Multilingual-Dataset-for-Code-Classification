import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    private static List<String> validTimes = new ArrayList<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numLeds = scanner.nextInt();
        scanner.close();

        backtrack(numLeds, 0, 0, "");

        validTimes.forEach(System.out::println);
    }

    private static void backtrack(int numLeds, int pos, int oneCount, String time) {
        if (oneCount == numLeds && time.length() < 6) {
            validTimes.add(time);
            return;
        }

        if (pos == 10) {
            return;
        }

        if (oneCount < numLeds) {
            backtrack(numLeds, pos + 1, oneCount + 1, time + "1");
        }

        if (oneCount < numLeds) {
            backtrack(numLeds, pos + 1, oneCount, time + "0");
        }
    }
}
