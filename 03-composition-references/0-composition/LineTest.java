

class LineTest {
    public static void main(String[] args) {
        Line l1;
        ///System.out.println(l1.toString());  // compiler error - l1 not initialized!
        l1 = new Line();
        System.out.println(l1.toString());    
        l1.set(1,2,3,4);                      // null pointer exception - p1 and p2 are not initialized!
        System.out.println(l1.toString());

        // Line l2 = new Line(1,2,3,4);
    }
}
