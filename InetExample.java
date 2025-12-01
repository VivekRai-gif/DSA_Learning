import java.net.*;

public class InetExample {
    public static void main(String[] args) {

        try {
            InetAddress local = InetAddress.getLocalHost();
            System.out.println("Local Host : " + local);
            System.out.println("Host Name : " + local.getHostName());
            System.out.println("Host Address : " + local.getHostAddress());

            InetAddress google = InetAddress.getByName("google.com");
            System.out.println("\nGoogle Host Name : " + google.getHostName());
            System.out.println("Google IP : " + google.getHostAddress());

            System.out.println("\nAll Google IPs:");
            InetAddress[] all = InetAddress.getAllByName("google.com");
            for (InetAddress ip : all) {
                System.out.println(ip);
            }

        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
