import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerOneWay {

    public static void main(String[] args) {
        try{
            ServerSocket ss = new ServerSocket(5555);
            System.err.println("Waiting for Client...");
            Socket s = ss.accept();

            System.err.println("Local Post " + s.getLocalPort());
            System.err.println("Connected with: " + s.getPort());

            // read data from client
            DataInputStream in = new DataInputStream(s.getInputStream());

            String msg1 = "";
            while(!msg1.equals("TaTa")){
                msg1 = in.readUTF();
                System.err.println("Message: " + msg1);
            }

        } catch (IOException e) {
            System.err.println("Server exception: " + e.getMessage());
        }
    }
}