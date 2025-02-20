package GET;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

public class GET {

    public void __main__(){
        try {
            //Connection Set with Server
            URL url = new URL("https://www.webcode.me/");
            HttpURLConnection connection = (HttpURLConnection) url.openConnection();

//            "GET" Request Set
            connection.setRequestMethod("GET");
            connection.setRequestProperty("User-Agent", "Mozilla");

//            get Response Code and Message
            int responseCode = connection.getResponseCode();
            String responseMessage = connection.getResponseMessage();

            System.out.println("Response Code: " + responseCode);
            System.out.println("Response Message: " + responseMessage);

//            read data from server
            if(responseCode == 200){
                InputStreamReader input = new InputStreamReader(connection.getInputStream());
                BufferedReader read = new BufferedReader(input);

//                Read Line by Line
                String str;
                while ((str = read.readLine()) != null){
                    System.out.println(str);
                }
            }
            else {
                System.out.println("GET method not Working");
            }



        } catch (Exception e) {
            throw new RuntimeException(e);
        }

    }
}
