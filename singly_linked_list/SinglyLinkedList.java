public class SinglyLinkedList<T> {
    public SingleNode<T> head;

    public SinglyLinkedList() {}
    public void add(T key) {
        SingleNode<T> new_node = new SingleNode<T>();

        new_node.next = this.head;
        new_node.key = key;

        this.head = new_node;
    }
}
