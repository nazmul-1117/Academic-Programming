package LF07_CRC;

class CRC {

    private static String xor(String a, String b){
        StringBuilder result = new StringBuilder();
        for(int i=1; i<b.length(); i++){
            result.append(a.charAt(i) == b.charAt(i) ? '0' : '1');
        }
        return result.toString();
    }

    private static String crcEncode(String divident, String divisor){

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

        // For the last bit
        if (temp.charAt(0) == '1'){
            temp = xor(divisor, temp);
        }else{
            temp = xor("0".repeat(keyLen), temp);
        }
        return temp;
    }

    public static void main(String[] args) {
        String data = "100100";
        String key  = "1101";

        String appendData = data + "0".repeat(key.length()-1);
        String reminder = crcEncode(appendData, key);
        System.out.println("Encode Data: " + data+reminder);

    }
    
}