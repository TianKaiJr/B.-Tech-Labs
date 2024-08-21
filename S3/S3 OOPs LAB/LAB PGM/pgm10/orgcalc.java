import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class orgcalc implements ActionListener
{
	JFrame f=new JFrame();
	JTextField text=new JTextField();
	
	JButton b1=new JButton("1");
	JButton b2=new JButton("2");
	JButton b3=new JButton("3");
	JButton b4=new JButton("4");
	JButton b5=new JButton("5");
	JButton b6=new JButton("6");
	JButton b7=new JButton("7");
	JButton b8=new JButton("8");
	JButton b9=new JButton("9");
	JButton b0=new JButton("0");
	
	JButton ba=new JButton("+");
	JButton bs=new JButton("-");
	JButton bp=new JButton("*");
	JButton bd=new JButton("/");
	JButton bdo=new JButton(".");
	JButton be=new JButton("=");
	
	orgcalc()
	{
		text.setBounds(2,1,320,80);

		b1.setBounds(2,80,80,80);
		b2.setBounds(82,80,80,80);	
		b3.setBounds(162,80,80,80);
		b4.setBounds(2,160,80,80);
		b5.setBounds(82,160,80,80);
		b6.setBounds(162,160,80,80);
		b7.setBounds(2,240,80,80);
		b8.setBounds(82,240,80,80);
		b9.setBounds(162,240,80,80);
		b0.setBounds(2,320,80,80);
		
		ba.setBounds(242,80,80,80);
		bs.setBounds(242,160,80,80);
		bp.setBounds(242,240,80,80);
		bd.setBounds(162,320,80,80);
		bdo.setBounds(82,320,80,80);
		be.setBounds(242,320,80,80);
		
		f.add(text);

		f.add(b1);
		f.add(b2);
		f.add(b3);
		f.add(b4);
		f.add(b5);
		f.add(b6);
		f.add(b7);
		f.add(b8);
		f.add(b9);
		f.add(b0);
		
		f.add(ba);
		f.add(bs);
		f.add(bp);
		f.add(bd);
		f.add(bdo);
		f.add(be);
		
		b1.addActionListener(this);
		b2.addActionListener(this);
		b3.addActionListener(this);
		b4.addActionListener(this);
		b5.addActionListener(this);
		b6.addActionListener(this);
		b7.addActionListener(this);
		b8.addActionListener(this);
		b9.addActionListener(this);
		b0.addActionListener(this);
		ba.addActionListener(this);
		bs.addActionListener(this);
		bp.addActionListener(this);
		bd.addActionListener(this);
		bdo.addActionListener(this);
		be.addActionListener(this);

		f.setLayout(null);
		f.setVisible(true);
		f.setSize(338,438);
		f.setResizable(false);
		
	}

	String num="",n="",op="";
	float r=0;

	void cal(String s)
	{
		if(s=="+")
		{
			r=r+Float.parseFloat(n);
		}
		else if(s=="-")
		{
			r=r-Float.parseFloat(n);
		}
		else if(s=="*")
		{
			r=r*Float.parseFloat(n);
		}
		else if(s=="/")
		{
			r=r/Float.parseFloat(n);
		}
		else 
		{
			r=Float.parseFloat(n);
		}
	}
	public void actionPerformed(ActionEvent e)
	{
		if(e.getSource()==b1)
		{
			num+="1";
			n+="1";
			text.setText(num);
		}
		else if(e.getSource()==b2)
		{
			num+="2";
			n+="2";
			text.setText(String.valueOf((num)));
		}
		else if(e.getSource()==b3)
		{
			num+="3";
			n+="3";
			text.setText(String.valueOf((num)));
		}
		else if(e.getSource()==b4)
		{
			num+="4";
			n+="4";
			text.setText(String.valueOf((num)));
		}
		else if(e.getSource()==b5)
		{
			num+="5";
			n+="5";
			text.setText(String.valueOf((num)));
		}
		else if(e.getSource()==b6)
		{
			num+="6";
			n+="6";
			text.setText(String.valueOf((num)));
		}
		else if(e.getSource()==b7)
		{
			num+="7";
			n+="7";
			text.setText(String.valueOf((num)));
		}
		else if(e.getSource()==b8)
		{
			num+="8";
			n+="8";
			text.setText(String.valueOf((num)));
		}
		else if(e.getSource()==b9)
		{
			num+="9";
			n+="9";
			text.setText(String.valueOf((num)));
		}
		else if(e.getSource()==b0)
		{
			num+="0";
			n+="0";
			text.setText(String.valueOf((num)));
		}
		else if(e.getSource()==bdo)
		{
			num+=".";
			n+=".";
			text.setText(num);
		}
		else if(e.getSource()==ba)
		{
			num+="+";
			cal(op);
			n="";
			op="+";
			text.setText(num);
		}
		else if(e.getSource()==bs)
		{
			num+="-";
			text.setText(num);
			cal(op);
			n="";
			op="-";
		}
		else if(e.getSource()==bp)
		{
			num+="*";
			text.setText(num);
			cal(op);
			n="";
			op="*";
		}
		else if(e.getSource()==bd)
		{
			num+="/";
			text.setText(num);
			cal(op);
			n="";
			op="/";
		}
		else if(e.getSource()==be)
		{
			cal(op);
			num=String.valueOf(r);
			text.setText(num);
			num="";
			n="";
			op="";
			r=0;
		}
	}
	
	public static void main(String args[])
	{
		new orgcalc(); 
	}
}












