package LF01_Stuff_DeStuff;

public class ByteStuffDeStuff {

    private static final String FLAG = "F";
    private static final String ESCAPE = "E";

    private static String byteStuffed(String actualData){

        StringBuilder str = new StringBuilder();

        for(char c : actualData.toCharArray()){
         
            if(String.valueOf(c).equals(FLAG) || String.valueOf(c).equals(ESCAPE)){
                str.append(ESCAPE);
            }
            // str.append(c);
            str.append(c);
        }

        return FLAG + str.toString() + FLAG;
    }



    private static String byteDeStuffed(String stuffedData){

        StringBuilder str = new StringBuilder();
        String unframed = stuffedData.substring(FLAG.length(), stuffedData.length()-FLAG.length());

        boolean esc = false;

        for(char c : unframed.toCharArray()){
            if(esc){
                str.append(c);
                esc = false;

            }else if(String.valueOf(c).equals(ESCAPE)){
                esc = true;
            }else{
                str.append(c);
            }
        }


        // return unframed;    
        return str.toString();    
    }


    public static void main(String[] args) {
        
        String actualData = "afleafafeadfeadfegea".toUpperCase();

        String stuffed = byteStuffed(actualData);
        String deStuffed = byteDeStuffed(stuffed);

        System.out.println("Actual Data: " + actualData);
        System.out.println("Stuffed Data: " + stuffed);
        System.out.println("De-Stuffed Data: " + deStuffed);


        if(actualData.equals(deStuffed)){
            System.out.println(actualData + " = " + deStuffed);
        }
    }






    
}
