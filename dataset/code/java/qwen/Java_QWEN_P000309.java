import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String n1 = sc.next();
        String n2 = sc.next();
        int m = n1.length(), n = n2.length();
        int[] res = new int[m + n];
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (n1.charAt(i) - '0') * (n2.charAt(j) - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = mul + res[p2];
                res[p2] = sum % 10;
                res[p1] += sum / 10;
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int num : res) if (!(sb.length() == 0 && num == 0)) sb.append(num);
        System.out.println(sb.length() == 0 ? "0" : sb.toString());
    }
}
