package LF01_Stuff_DeStuff;

public class BitStuffD {

    private static String bitStuff(String actualBit){

        StringBuilder str = new StringBuilder();;
        int counter=0;

        for(char c : actualBit.toCharArray()){
            if (c == '1') {
                ++counter;
                str.append(c);

                if(counter == 5){
                    str.append('0');
                    counter = 0;
                }

            }else{
                str.append('0');
                counter = 0;
            }
        }




        return str.toString();
    }


    private static String deStuff(String stuffString){

        StringBuilder str = new StringBuilder();;
        int counter=0;

        for (int i = 0; i < stuffString.length(); i++) {

            char c = stuffString.charAt(i);
            
            if (c == '1') {
                ++counter;
                str.append('1');

            }else{

                if(counter == 5){
                    counter = 0;
                    continue;
                }

                str.append('0');
                counter = 0;
            }
        }


        return str.toString();
    }


    public static void main(String[] args) {
        String actualbit = "111101111111110000000000000111111111111111111011111";

        String stuffedBit = bitStuff(actualbit);
        String deStuffedBit = deStuff(stuffedBit);

        System.out.println("Original Data: " + actualbit);
        System.out.println("After Stuff Data: " + stuffedBit);
        System.out.println("After DeStuff Data: " + deStuffedBit);


        if (actualbit.equals(deStuffedBit)) {
            System.out.println("Actual Databit == Destuff Bit");
        }
    }
    
}
