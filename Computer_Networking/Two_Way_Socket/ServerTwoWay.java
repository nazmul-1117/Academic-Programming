package Two_Way_Socket;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerTwoWay {
    public static void main(String[] args) {
        try {
            // set socket port
            ServerSocket ss = new ServerSocket(2001);
            System.err.println("Wait for client...!");
            
            // accept user/client
            Socket s = ss.accept();

            // make a data input/output class
            DataOutputStream out = new DataOutputStream(s.getOutputStream());
            DataInputStream in = new DataInputStream(s.getInputStream());

            // Prepare string for take input
            String inputMsg = "";
            String outputMsg = "";

            while (!outputMsg.equals("bye")) {
                outputMsg = in.readUTF();
                System.err.println("Your Message: "+ outputMsg);

                InputStreamReader input = new InputStreamReader(System.in);
                BufferedReader buffer = new BufferedReader(input);

                outputMsg = buffer.readLine();
                out.writeUTF(outputMsg);
                
            }

        } catch (Exception e) {
            System.err.println("Error for connection build");
        }
    }
    
}
