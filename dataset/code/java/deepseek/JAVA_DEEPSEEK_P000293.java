import java.util.*;

public class Main {
    public static void main(String[] args) {
        List<String> strs = Arrays.asList("Hello", "World", "Java", "Programming");
        String encoded = encode(strs);
        System.out.println("Encoded string: " + encoded);
        List<String> decoded = decode(encoded);
        System.out.println("Decoded list: " + decoded);
    }

    public static String encode(List<String> strs) {
        StringBuilder sb = new StringBuilder();
        for (String s : strs) {
            sb.append(s.length()).append("#").append(s);
        }
        return sb.toString();
    }

    public static List<String> decode(String s) {
        List<String> result = new ArrayList<>();
        int i = 0;
        while (i < s.length()) {
            int j = i;
            while (s.charAt(j) != '#') {
                j++;
            }
            int length = Integer.parseInt(s.substring(i, j));
            String str = s.substring(j + 1, j + 1 + length);
            result.add(str);
            i = j + 1 + length;
        }
        return result;
    }
}
