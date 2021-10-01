import java.util.ArrayList;
 
public class ArrayListExample {
   
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<>();
        list.add("One");
        list.add("Two");
        list.add("Three");
        list.add("Four");
 
        System.out.println("ArrayList:");
 
        for (String str : list) {
            System.out.println(str);
        }
    }
}