package POST;

import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.URL;

public class POST {

    public void __main__(){

        try {

            String str = "https://jsonplaceholder.typicode.com/posts/";
            URL url = new URL(str);
            HttpURLConnection connection = (HttpURLConnection) url.openConnection();

//            post request
            connection.setRequestMethod("POST");
            connection.setRequestProperty("User-Agent", "Mozilla");

//            System.out.println("-->POST");

//            post working
            connection.setDoOutput(true);
            String message = "Hello Nazmul";
            OutputStream out = connection.getOutputStream();
            out.write(message.getBytes());
            out.flush();
            System.out.println("-->Flush");

//            check post
            int responseCode = connection.getResponseCode();
            String responseMessage = connection.getResponseMessage();

            System.out.println("Response Code: " + responseCode);
            System.out.println("Response Message: " + responseMessage);

        }catch (Exception e){
            System.out.println("ERROR--DD");
        }

    }
}
