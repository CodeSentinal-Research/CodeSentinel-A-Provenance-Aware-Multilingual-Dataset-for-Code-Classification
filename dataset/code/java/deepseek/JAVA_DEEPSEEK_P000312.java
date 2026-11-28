import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String version1 = scanner.next();
        String version2 = scanner.next();
        System.out.println(compareVersion(version1, version2));
    }

    public static int compareVersion(String version1, String version2) {
        String[] levels1 = version1.split("\\.");
        String[] levels2 = version2.split("\\.");

        int length1 = levels1.length;
        int length2 = levels2.length;
        int length = Math.max(length1, length2);

        for (int i = 0; i < length; i++) {
            Integer v1 = i < length1 ? Integer.parseInt(levels1[i]) : 0;
            Integer v2 = i < length2 ? Integer.parseInt(levels2[i]) : 0;
            int compare = v1.compareTo(v2);
            if (compare != 0) {
                return compare;
           }
        }

        return 0;
    }
}
