package Two_Way_Socket;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.Socket;

public class ClientTwoWay {
    public static void main(String[] args) {
        try {
            Socket soc = new Socket("localhost", 2001);

            DataInputStream in = new DataInputStream(soc.getInputStream());
            DataOutputStream out = new DataOutputStream(soc.getOutputStream());

            String inputMsg = "";
            String outputMsg = "";

            while (!outputMsg.equals("bye")) {
                System.out.print("Enter Your Message: ");
                InputStreamReader input = new InputStreamReader(System.in);
                BufferedReader buffer = new BufferedReader(input);

                outputMsg = buffer.readLine();
                out.writeUTF(outputMsg);
            }
            
        } catch (Exception e) {
            System.err.println("Error");
        }
    }
    
}
