import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<String, String> map = new HashMap<>();
        for(int i=0; i<n; i++) {
            String flightNo = sc.next();
            String dest = sc.next();
            map.put(flightNo, dest);
        }
        String searchFlight = sc.next();
        if(map.containsKey(searchFlight)) System.out.println(map.get(searchFlight));
        else System.out.println("Flight Not Found");
    }
}
