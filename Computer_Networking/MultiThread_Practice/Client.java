package MultiThread_Practice;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.Socket;
import java.util.Scanner;

public class Client {

    public static void main(String[] args) {
        try {
            Socket socket = new Socket("localhost", 5000);

            DataOutputStream dos = new DataOutputStream(socket.getOutputStream());
            DataInputStream dis = new DataInputStream(socket.getInputStream());

            Scanner scanner = new Scanner(System.in);

            while (true) {
                System.out.print("Enter Message: ");
                String out = scanner.nextLine();
                
                if (out.toLowerCase().equals("bye")) {
                    dos.close();
                    dis.close();
                    socket.close();
                    System.out.println("Client Closed");
                    break;
                }

                dos.writeUTF(out);

                String in = dis.readUTF();
                System.err.println("Server: "+ in);
            }

        } catch (Exception e) {
            // TODO: handle exception
        }
    }
    
}
