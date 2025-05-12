import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;

public class ClientHandler extends Thread {
    private DataInputStream dis;
    private DataOutputStream dos;
    private Socket socket;

    public ClientHandler(Socket socket, DataInputStream dis, DataOutputStream dos){
        this.dis = dis;
        this.dos = dos;
        this.socket = socket;
    }

    public ClientHandler(DataOutputStream dos2, DataInputStream dis2, Socket socket2, int totalClients) {
        //TODO Auto-generated constructor stub
    }

    @Override
    public void run(){
        // dos.writeUTF("Hello Nazmul: ");
        int i=1;
        while (true) {
            try {
                dos.writeUTF("Enter " + i + " Number: ");
                String getMessage = dis.readUTF();

                if(getMessage.equals("bye")){
                    System.err.println("We are exiting from Server...");
                    this.socket.close();
                    break;
                }
                i++;

            } catch (IOException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }
    }
    
}
