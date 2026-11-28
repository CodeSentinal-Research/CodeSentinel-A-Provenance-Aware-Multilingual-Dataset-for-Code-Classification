import java.util.ArrayList;
import java.util.List;

public class Main {
    public static List<String> restoreIpAddresses(String s) {
        List<String> result = new ArrayList<>();
        int len = s.length();
        for(int i = 1; i < len && i < 4; i++){
            for(int j = i + 1; j < len && j - i < 4; j++){
                for(int k = j + 1; k < len && k - j < 4; k++){
                    String s1 = s.substring(0, i);
                    String s2 = s.substring(i, j);
                    String s3 = s.substring(j, k);
                    String s4 = s.substring(k);
                    if(isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4)){
                        result.add(s1 + "." + s2 + "." + s3 + "." + s4);
                    }
                }
            }
        }
        return result;
    }

    public static boolean isValid(String s) {
        if(s.length() > 3 || s.length() == 0 || (s.charAt(0) == '0' && s.length() > 1) || Integer.parseInt(s) > 255){
            return false;
        }
        return true;
    }

    public static void main(String[] args) {
        List<String> ips = restoreIpAddresses("25525511135");
        for(String ip : ips) {
            System.out.println(ip);
        }
    }
}