/**
 * @author J. Santos <jamillo@gmail.com>
 */
public class Rotation
{
	private int face;

	private int amount;

	public Rotation(int face)
	{
		this.face = face;
		this.amount = 1;
	}

	public Rotation(int face, int amount)
	{
		this.face = face;
		this.amount = amount;
	}

	public int getFace()
	{
		return face;
	}

	public int getAmount()
	{
		return amount;
	}

	public String getFaceAsString()
	{
		switch (this.face)
		{
			case 3:
				return "front";
			case 5:
				return "back";
			case 4:
				return "right";
			case 6:
				return "left";
			case 2:
				return "up";
			case 1:
				return "down";
		}
		return "";
	}
}
