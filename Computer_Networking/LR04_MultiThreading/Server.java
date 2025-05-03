import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    private static int totalClients;
    public static void main(String[] args) {
        totalClients = 1;
        
        try{
            ServerSocket serverSocket = new ServerSocket(5555);
            System.out.println("Server Connecting...!");

            while (totalClients <= 5){
                Socket socket = serverSocket.accept();
                System.out.println("Congratulation... Server Connected with User: " + totalClients);

                DataInputStream dis = new DataInputStream(socket.getInputStream());
                DataOutputStream dos = new DataOutputStream(socket.getOutputStream());

                Thread newClients = new ClientHandler(dos, dis, socket, totalClients);
                newClients.start();

                // socket.close();
                ++totalClients;
            }

            // socket.close();
            serverSocket.close();
            System.out.println("Server is down...\nPlease Try Latter");

        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}