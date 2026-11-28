import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String name = scanner.nextLine();
        String typed = scanner.nextLine();
        System.out.println(canBeTyped(name, typed));
    }

    private static String canBeTyped(String name, String typed) {
        int i = 0, j = 0;
        while (i < name.length() && j < typed.length()) {
            if (name.charAt(i) == typed.charAt(j)) {
                i++;
                j++;
            } else if (j > 0 && typed.charAt(j-1) == typed.charAt(j)) {
                j++;
            } else {
                return "NO";
            }
        }
        if (i < name.length()) {
            return "NO";
        }
        return "YES";
    }
}
