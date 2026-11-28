import java.util.ArrayList;
import java.util.List;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String s = reader.readLine();
        List<String> result = restoreIpAddresses(s);
        for (String ip : result) {
            System.out.println(ip);
        }
    }

    public static List<String> restoreIpAddresses(String s) {
        List<String> result = new ArrayList<>();
        int len = s.length();
        for (int i = 1; i < len && i < 4; i++) {
            for (int j = i + 1; j < len && j < i + 4; j++) {
                for (int k = j + 1; k < len && k < j + 4; k++) {
                    String s1 = s.substring(0, i);
                    String s2 = s.substring(i, j);
                    String s3 = s.substring(j, k);
                    String s4 = s.substring(k);
                    if (isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4)) {
                        result.add(s1 + "." + s2 + "." + s3 + "." + s4);
                    }
                }
            }
        }
        return result;
    }

    private static boolean isValid(String s) {
        if (s.length() > 3) {
            return false;
        }
        if (s.startsWith("0") && s.length() > 1) {
            return false;
        }
        int num = Integer.parseInt(s);
        return num <= 255 && num >= 0;
    }
}
