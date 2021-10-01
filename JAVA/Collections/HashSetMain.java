import java.util.HashSet;
import java.util.Iterator;
 
public class HashSetMain {
    /*
     * @author : Arpit Mandliya
     */
    public static void main(String[] args) {
        HashSet<String> set = new HashSet<>();
        set.add("One");
        set.add("Two");
        set.add("One");
        set.add("Three");
        set.add("Two");
 
        System.out.println("HashSet:");
 
        Iterator<String> it=set.iterator();
        while(it.hasNext()){
            System.out.println(it.next());
        }
    }
}