import java.util.*;

public class Solution {
    public static boolean isValidNumber(String s) {
        String regex = "^[+-]?(\\d+(\\.\\d*)?|\\.\\d+)([eE][+-]?\\d+)?$";
        return s.trim().matches(regex);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            System.out.println(isValidNumber(scanner.next()) ? "Valid" : "Invalid");
        }
    }
}