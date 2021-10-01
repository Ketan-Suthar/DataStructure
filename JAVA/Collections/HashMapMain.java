import java.util.HashMap;
public class HashMapMain {
 
    public static void main(String[] args) {
        HashMap<Integer, String> map = new HashMap<Integer, String>();
        // Putting key-values pairs in HashMap
        map.put(1, "One");
        map.put(2, "Two");
        map.put(3, "Three");
        map.put(4, "Four");
 
        System.out.println(map);
    }
}