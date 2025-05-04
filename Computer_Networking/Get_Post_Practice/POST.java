import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.URL;

public class POST {
    public static void main(String[] args) {
        try{
            String str = "https://jsonplaceholder.typicode.com/posts/";
            URL url = new URL(str);

            HttpURLConnection connection = (HttpURLConnection) url.openConnection();

            connection.setRequestMethod("POST");
            connection.setRequestProperty("User-Agent", "Mozilla");

            connection.setDoOutput(true);
            String msg = "Hello NAT";
            OutputStream output = connection.getOutputStream(); 

            output.write(msg.getBytes());
            output.flush();

            int code = connection.getResponseCode();
            String message = connection.getResponseMessage();

            System.err.println(code);
            System.err.println(message);

        }catch(Exception e){
            System.err.println("Error got " + e.getMessage());
        }
    }
}
