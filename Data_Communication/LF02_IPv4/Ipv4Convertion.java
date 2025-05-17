package LF02_IPv4;

public class Ipv4Convertion {

    private static String decToBinary(String decIP){
        StringBuilder str = new StringBuilder();
        String[] octates = decIP.split("\\.");


        for(int i=0; i<octates.length; i++){

            int decimal = Integer.parseInt(octates[i]);
            String binaryOctet = Integer.toBinaryString(decimal);

            while (binaryOctet.length() < 8) {
                binaryOctet = "0" + binaryOctet;
            }

            str.append(binaryOctet);
            if( i < octates.length-1){
                str.append(".");
            }
        }

        return str.toString();
    }


    private static String binaryToDec(String decIP){
        StringBuilder str = new StringBuilder();
        String[] octates = decIP.split("\\.");


        for(int i=0; i<octates.length; i++){

            String binaryOctet = octates[i];
            int decimalValue = Integer.parseInt(binaryOctet, 2);

            str.append(decimalValue);
            if( i < octates.length-1){
                str.append(".");
            }
        }

        return str.toString();
    }



    public static void main(String[] args) {
        System.out.println("Program started"); // Added line
        String ipv4 = "192.168.1.27";
        String binaryIPv4 = decToBinary(ipv4);
        String decimalIPv4 = binaryToDec(binaryIPv4);

        System.out.println("Decimal IP: " + ipv4);
        System.out.println("Binary IP: " + binaryIPv4);
        System.out.println("Decimal IP: " + decimalIPv4);

        System.out.println("Program finished"); // Added line
    }
}