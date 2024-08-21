abstract class Shape
{
	abstract void numberOfSides();
}

class Rectangle extends Shape
{
	void numberOfSides()
	{
		System.out.print("Number of Sides = 4\n");
	}
}

class Triangle extends Shape
{
	void numberOfSides()
	{
		System.out.print("Number of Sides = 3\n");
	}
}

class Hexagon extends Shape
{
	void numberOfSides()
	{
		System.out.print("Number of Sides = 6\n");
	}
}

public class shape
{
	public static void main(String args[])
	{
		Rectangle rec=new Rectangle();
		Triangle tri=new Triangle();
		Hexagon hex=new Hexagon();
		Shape shaperef;
		
		System.out.print("-->RECTANGLE\n");
		shaperef=rec;
		shaperef.numberOfSides();
		
		System.out.print("-->TRIANGLE\n");
		shaperef=tri;
		shaperef.numberOfSides();
		
		System.out.print("-->HEXAGON\n");
		shaperef=hex;
		shaperef.numberOfSides();
	}
}

		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
