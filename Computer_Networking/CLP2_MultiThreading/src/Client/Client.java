package Client;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) {
        try {
            Socket socket = new Socket("localhost", 5555);

            DataOutputStream dos = new DataOutputStream(socket.getOutputStream());
            DataInputStream dis = new DataInputStream(socket.getInputStream());
            Scanner scanner = new Scanner(System.in);

            while(true){
//                String getMessage = dis.readUTF();
                System.out.print("Enter Message: ");

                String outMessage = scanner.nextLine();
                dos.writeUTF(outMessage);

                if(outMessage.equals("exit")){
                    socket.close();
                    System.out.println("Exit from Client...!");
                    break;
                }

                String getMessage = dis.readUTF();

                System.out.println("Upper Case: " + getMessage);
            }
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}
