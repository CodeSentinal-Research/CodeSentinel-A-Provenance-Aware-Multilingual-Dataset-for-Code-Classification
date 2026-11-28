import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String pattern = scanner.nextLine();
        System.out.println(restoreArray(pattern));
    }

    public static String restoreArray(String pattern) {
        StringBuilder sb = new StringBuilder();
        sb.append(pattern.charAt(0));
        for (int i = 1; i < pattern.length(); i++) {
            if (pattern.charAt(i) == 'I') {
                sb.append(sb.charAt(sb.length() - 1) + 1);
                sb.append(sb.charAt(sb.length() - 1) - 1);
            } else {
                sb.append(sb.charAt(sb.length() - 1) - 1);
                sb.append(sb.charAt(sb.length() - 1) + 1);
           
            }
        }
        return sb.toString();
    }
}
