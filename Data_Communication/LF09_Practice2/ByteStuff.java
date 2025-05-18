public class ByteStuff {

    static String f = "FLAG";
    static String e = "ESCAPE";


    static String byteStuffed(String data){

        StringBuilder str = new StringBuilder();

        for(int i=0; i<data.length(); i++){

            if (data.startsWith(e, i)) {
                str.append(e).append(e);
                i += e.length()-1;

            }else if (data.startsWith(f, i)) {
                str.append(e).append(f);
                i += f.length()-1;
                
            }else{
                str.append(data.charAt(i));
            }
        }

        return f+str.toString()+f;
    }


    static String deStuff(String data){

        StringBuilder str = new StringBuilder();
        String unframed = data.substring(f.length(), data.length()-f.length());

        for(int i=0; i<unframed.length(); i++){

            if (unframed.startsWith(e, i)) {
                
                if(unframed.startsWith(f, e.length()+i)){
                    str.append(f);
                    i += e.length() + f.length();

                }else if (unframed.startsWith(e, e.length()+i)) {
                    str.append(e);
                    i += e.length() + e.length();

                }else{
                    str.append(unframed.charAt(i));
                }

            }else{
                str.append(unframed.charAt(i));
            }
        }

        return str.toString();
    }
    




    public static void main(String[] args) {

        String data = "Hi FLAG my name is ESCAPE";
        String stuffed = byteStuffed(data);
        System.out.println("Stuffed Data: " + stuffed);

        String deStuff = deStuff(stuffed);
        System.out.println("Destuffed: " + deStuff);
        
    }
}
