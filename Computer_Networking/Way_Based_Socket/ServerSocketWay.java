import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerSocketWay{

    public static void main(String[] args) {
        try {
            ServerSocket serverSocket = new ServerSocket(5000);
            System.out.println("Server Connecting...");

            Socket socket = serverSocket.accept();
            System.out.println("Server is Connected");

            DataInputStream dis = new DataInputStream(socket.getInputStream());
            DataOutputStream dos = new DataOutputStream(socket.getOutputStream());

            String in = "";
            String out = "hi";

            while (!out.equals("bye")) {

                in = dis.readUTF();
                System.out.println("Client: " + in);

                System.out.print("Enter Message: ");
                InputStreamReader inputReader = new InputStreamReader(System.in);
                BufferedReader reader = new BufferedReader(inputReader);

                out = reader.readLine();
                dos.writeUTF(out);
            }

            System.out.println("Exiting from Server...");
            dis.close();
            dos.close();
            socket.close();
            serverSocket.close();

        } catch (Exception e) {
            System.out.println("Server Error");
        }
    }
}