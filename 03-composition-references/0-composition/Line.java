public class Line
{
	private Point p1, p2;

	public void set(int x1,int y1,int x2,int y2) {
		p1.setX(x1);
		p1.setY(y1);
		p2.setX(x2);
		p2.setY(y2);
	}

	public void set(Point p1, Point p2) {
		this.p1 = p1;
		this.p2 = p2;
	}

	public String toString() { 	return "Line from " + p1  + " to " + p2; }
};
