public class Point {
    public int x;
    public int y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void show() {
        System.out.println("-----");
        System.out.printf("X: %d\n", this.x);
        System.out.printf("Y: %d\n", this.y);
        System.out.println("-----");
    }
}
