package LF01_Stuff_DeStuff;

public class ByteStuffDeStuff2 {

    private static final String FLAG = "FLAG";
    private static final String ESCAPE = "ESCAPE";


    private static String byteStuffed(String actualData){

        StringBuilder str = new StringBuilder();
        for(int i=0; i<actualData.length(); i++){
            if(actualData.startsWith(ESCAPE, i)){
                str.append(ESCAPE).append(ESCAPE);
                i += ESCAPE.length()-1;

            }else if (actualData.startsWith(FLAG, i)) {
                str.append(ESCAPE).append(FLAG);
                i += FLAG.length()-1;

            }else{
                str.append(actualData.charAt(i));
            }

        }

        return FLAG + str.toString() + FLAG;
    }


    private static String byteDeStuffed(String stuffedData){

        StringBuilder str = new StringBuilder();
        String unframed = stuffedData.substring(FLAG.length(), stuffedData.length()-FLAG.length());

        for(int i=0; i<unframed.length(); i++){

            if (unframed.startsWith(ESCAPE, i)) {

                if (unframed.startsWith(FLAG, ESCAPE.length()+i)) {
                    str.append(FLAG);
                    i += ESCAPE.length()+FLAG.length() - 1;

                }else if(unframed.startsWith(ESCAPE, ESCAPE.length()+i)){
                    str.append(ESCAPE);
                    i += ESCAPE.length() + ESCAPE.length() - 1;

                }else{
                    str.append(unframed.charAt(i));
                }
                
            }else{
                str.append(unframed.charAt(i));
            }
        }

        // return unframed;    
        return str.toString();    
    }


    public static void main(String[] args) {
                String actualData = "FLAG with ESCAPE what do you FLAG? ESXAPE";

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