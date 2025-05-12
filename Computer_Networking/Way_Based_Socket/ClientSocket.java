import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.Socket;

public class ClientSocket {

    public static void main(String[] args) {
        try {
            Socket socket = new Socket("localhost", 5000);

            DataInputStream dis = new DataInputStream(socket.getInputStream());
            DataOutputStream dos = new DataOutputStream(socket.getOutputStream());

            System.out.println("Socket Connected");

            String in = "";
            String out = "";

            while (!out.equals("bye")) {
                               
                System.out.print("Enter Message: ");
                InputStreamReader input = new InputStreamReader(System.in);
                BufferedReader reader = new BufferedReader(input);
                              
                out = reader.readLine();
                dos.writeUTF(out);

                in = dis.readUTF();
                System.out.println("Server: " + in);
            }

            System.out.println("Exiting From Client...");
            dis.close();
            dos.close();
            socket.close();

        } catch (Exception e) {
            System.out.println("Server not found");
        }
    }
    
}
