public class Main {
    public static void main(String[] args) {
        SingleNode<Point> pointer = null;
        SinglyLinkedList<Point> list = new SinglyLinkedList<Point>();

        list.add(new Point(17, 19));
        list.add(new Point(19, 21));

        pointer = list.head;
        while(pointer != null) {
            pointer.key.show();
            pointer = pointer.next;
        }
        for(;;) {}
    }
}
