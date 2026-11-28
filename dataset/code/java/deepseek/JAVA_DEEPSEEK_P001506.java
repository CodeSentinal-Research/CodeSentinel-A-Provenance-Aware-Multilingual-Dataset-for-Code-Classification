import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String S = scanner.nextLine();
        String T = scanner.nextLine();

        System.out.println(minSubstring(S, T));
    }

    public static String minSubstring(String S, String T) {
        if (S == null || T == null || S.length() == 0 || T.length() == 0) {
            return "";
        }

        int[] position = new int[S.length()];
        for (int i = 0; i < S.length(); i++) {
            if (S.charAt(i) == T.charAt(0)) {
                position[i] = 0;
            } else {
                position[i] = -1;
            }
        }

        for (int i = 1; i < T.length(); i++) {
            int minPos = Integer.MAX_VALUE;
            for (int j = 0; j < S.length(); j++) {
                if (position[j] >= 0 && position[j] < minPos) {
                    minPos = position[j];
                }
            }

            if (minPos == Integer.MAX_VALUE) {
                break;
            }

            for (int j = 0; j < S.length(); j++) {
                if (position[j] == minPos) {
                    position[j] = minPos + 1;
                    break;
                }
            }
        }

        int minLength = Integer.MAX_VALUE;
        int minStart = 0;
        for (int i = 0; i < S.length(); i++) {
            if (position[i] >= 0 && position[i] <= minLength) {
                minLength = position[i];
                minStart = i;
            }
        }

        if (minLength == Integer.MAX_VALUE) {
            return "";
        }

        return S.substring(minStart, minStart + minLength);
    }
}
