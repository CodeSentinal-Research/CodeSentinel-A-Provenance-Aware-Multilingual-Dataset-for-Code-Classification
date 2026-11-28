import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String pattern = scanner.nextLine();
        System.out.println(constructMinimum(pattern));
    }

    private static String constructMinimum(String pattern) {
        StringBuilder sb = new StringBuilder();
        int n = pattern.length();
        int maxD = 0;
        int minI = 0;

        for (int i = 0; i < n; i++) {
            char c = pattern.charAt(i);
            if (c == 'I') {
                sb.append(minI++).append(',');
                maxD++;
            } else {
                sb.append(maxD++).append(',');
                minI++;
           
            }
        }
        sb.append(minI);
        return sb.toString();
    }
}
