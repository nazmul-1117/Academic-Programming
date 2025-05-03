package Handler;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.Scanner;

public class ClientHandler extends Thread{
    private DataOutputStream dos;
    private DataInputStream dis;
    private Socket socket;
    private Scanner scanner;
    private int clientNumber;

    public ClientHandler(DataOutputStream dos, DataInputStream dis, Socket socket, int clientNumber) {
        this.dos = dos;
        this.dis = dis;
        this.socket = socket;
        this.clientNumber = clientNumber;
    }

    @Override
    public void run(){
        System.out.println("Run ClinetHandler...");
        while (true){
            try {
                String getMessage = dis.readUTF();
                if(getMessage.equals("exit")){
                    socket.close();
                    System.out.println("Exit from Server...");
                    break;
                }
                String upperCase = clientNumber + " " + getMessage.toUpperCase();
                System.out.println("UpperCase: " + upperCase + " " + clientNumber);
                dos.writeUTF(upperCase);

            } catch (IOException e) {
                System.out.println(e.getMessage());
            }
        }
    }
}
