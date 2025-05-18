public class CRC {

    private static String xor(String a, String b){

        StringBuilder str = new StringBuilder();
        for(int i=1; i<b.length(); i++){
            str.append(a.charAt(i) == b.charAt(i) ? '0' : '1');
        }
        return str.toString();
    }

    private static String mod2division(String divident, String divisor){

        int keyLen = divisor.length();
        String temp = divident.substring(0, keyLen);

        while (keyLen < divident.length()) {
            
            if (temp.charAt(0) == '1') {
                temp = xor(divisor, temp) + divident.charAt(keyLen);

            }else{
                temp = xor("0".repeat(keyLen), temp) + divident.charAt(keyLen);
            }
            keyLen++;
        }

        if (temp.charAt(0) == '1'){
            temp = xor(divisor, temp);
        }else{
            temp = xor("0".repeat(keyLen), temp);
        }
        return temp;
    }
    

    private static boolean verify(String data, String key){
        String reminder = mod2division(data, key);
        return reminder.replace("0", "").isEmpty();
    }

    public static void main(String[] args) {
        String bits = "100100";
        String key = "1101";

        String appendData = bits + "0".repeat(key.length()-1);
        String reminder = mod2division(appendData, key);
        String encode = bits+reminder;
        System.out.println("Encode: " + bits+reminder);
        System.out.println("Check Error: " + verify(encode, key));
    }
}
