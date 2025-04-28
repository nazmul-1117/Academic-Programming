import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {

    public static void main(String[] args) {
        try{
            ServerSocket serverSocket = new ServerSocket(5555);
            System.err.println("New Client Connectiong...");

            while (true) {
                Socket socket = serverSocket.accept();

                DataInputStream dis = new DataInputStream(socket.getInputStream());
                DataOutputStream dos = new DataOutputStream(socket.getOutputStream());

                Thread newClient = new ClientHandler(socket, dis, dos);
                newClient.start();
            }
        }
        catch(Exception e){
            System.err.println("Error in Server Class: " + e.getMessage());

        }
    }
}