import java.io.*;
import java.util.*;

public class Main {
    public static class Device {
        String name;
        String status;

        public Device(String name, String status) {
            this.name = name;
            this.status = status;
        }

        public String getName() {
            return name;
        }

        public String getStatus() {
            return status;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Device> devices = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            devices.add(new Device(input[0], input[1]));
        }

        for (Device device : devices) {
            if (device.getStatus().equals("online")) {
                System.out.println(device.getName());
            }
        }
    }
}
