import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        String path = "/home//foo/";
        System.out.println(simplifyPath(path));
    }

    public static String simplifyPath(String path) {
        Stack<String> stack = new Stack<>();
        String[] components = path.split("/");

        for (String component : components) {
            if ("..".equals(component)) {
                if (!stack.isEmpty()) {
                    stack.pop();
                }
            } else if (!"".equals(component) && !".".equals(component)) {
                stack.push(component);
            }
       
       }

       StringBuilder sb = new StringBuilder();
       if (stack.isEmpty()) {
           sb.append("/");
       } else {
           while (!stack.isEmpty()) {
               sb.insert(0, stack.pop()).insert(0, "/");
           }
       }
       return sb.toString();
    }
}
