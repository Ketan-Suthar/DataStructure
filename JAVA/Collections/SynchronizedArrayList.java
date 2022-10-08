import java.util.*;

 public class SynchronizedArrayList {
    public static void main(String args[]) {
       
       // Converting ArrayList to Synchronized ArrayList
       List<String> synchronizedarraylist = Collections.synchronizedList(new ArrayList<String>());

       //Adding elements to synchronized ArrayList
       synchronizedarraylist.add("Basketball");
       synchronizedarraylist.add("Baseball");
       synchronizedarraylist.add("Football");

       System.out.println("Synchronized ArrayList Iteration:");
       synchronized(synchronizedarraylist) {
       Iterator<String> iterator = synchronizedarraylist.iterator(); 
       while (iterator.hasNext())
          System.out.println(iterator.next());
       }
  }
} 