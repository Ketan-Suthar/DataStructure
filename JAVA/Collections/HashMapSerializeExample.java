import java.util.*;
import java.io.*;

public class HashMapSerializeExample {
    public static void main(String args[]) {
        
    // Creating a HashMap of Integer keys and String values
    HashMap<Integer, String> hashmap = new HashMap<Integer, String>();
    hashmap.put(1, "Value1");
    hashmap.put(2, "Value2");
    hashmap.put(3, "Value3");
    hashmap.put(4, "Value4");
    hashmap.put(5, "Value5");
    try
           {
                  FileOutputStream fos =
                     new FileOutputStream("hashmap.ser");
                  ObjectOutputStream oos = new ObjectOutputStream(fos);
                  oos.writeObject(hmap);
                  oos.close();
                  fos.close();
                  System.out.printf("Serialized HashMap data is saved in hashmap.ser");
           }catch(IOException ioe)
            {
                  ioe.printStackTrace();
            }
  }
}