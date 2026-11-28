import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String version1 = scanner.nextLine();
        String version2 = scanner.nextLine();

        int result = compareVersion(version1, version2);

        System.out.println(result);
    }

    public static int compareVersion(String version1, String version2) {
        String[] v1 = version1.split("\\.");
        String[] v2 = version2.split("\\.");

        int i = 0;
        while (i < v1.length || i < v2.length) {
            int v1Part = i < v1.length ? Integer.parseInt(v1[i]) : 0;
            int v2Part = i < v2.length ? Integer.parseInt(v2[i]) : 0;

            if (v1Part > v2Part) {
                return 1;
            } else if (v1Part < v2Part) {
                return -1;
            }

            i++;
        }

        return 0;
    }
}
