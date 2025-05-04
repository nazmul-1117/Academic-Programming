import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

public class GET{

    public static void main(String[] args) {
        try{
            URL url = new URL("https://webcode.me/");
            HttpURLConnection connection = (HttpURLConnection) url.openConnection();

            connection.setRequestMethod("GET");
            connection.setRequestProperty("User-Agent", "Mozilla");


            if (connection.getResponseCode() == 200){
                InputStreamReader input = new InputStreamReader(connection.getInputStream());
                BufferedReader reader = new BufferedReader(input);

                String str;
                while ((str = reader.readLine()) != null) {
                    System.err.println(str);
                }
            }

        }catch(Exception e){
            System.out.println("Exception Got: " + e.getMessage());
        }

    }
}