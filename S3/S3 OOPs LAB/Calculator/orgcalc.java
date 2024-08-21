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
		text.setBounds(50,50,200,50);
		b1.setBounds(50,100,50,50);
		b2.setBounds(100,100,50,50);	
		b3.setBounds(150,100,50,50);
		b4.setBounds(50,150,50,50);
		b5.setBounds(100,150,50,50);
		b6.setBounds(150,150,50,50);
		b7.setBounds(50,200,50,50);
		b8.setBounds(100,200,50,50);
		b9.setBounds(150,200,50,50);
		b0.setBounds(50,250,50,50);
		
		ba.setBounds(200,100,50,50);
		bs.setBounds(200,150,50,50);
		bp.setBounds(200,200,50,50);
		bd.setBounds(150,250,50,50);
		bdo.setBounds(100,250,50,50);
		be.setBounds(200,250,50,50);
		
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
		
		f.setLayout(null);
		f.setVisible(true);
		f.setSize(500,500);
		
	}
	
	public void actionPerformed(ActionEvent e)
	{
		String num="";
		if(e.getSource()==b1)
		{
			num+="1";
			text.setText(num);
		}
		else if(e.getSource()==b2)
		{
			num+="2";
			text.setText(String.valueOf((n1-n2)));
		}
		else if(e.getSource()==b3)
		{
			num+="3";
			text.setText(String.valueOf((n1-n2)));
		}
		else if(e.getSource()==b4)
		{
			num+="4";
			text.setText(String.valueOf((n1-n2)));
		}
		else if(e.getSource()==b5)
		{
			num+="5";
			text.setText(String.valueOf((n1-n2)));
		}
		else if(e.getSource()==b6)
		{
			num+="6";
			text.setText(String.valueOf((n1-n2)));
		}
		else if(e.getSource()==b7)
		{
			num+="7";
			text.setText(String.valueOf((n1-n2)));
		}
		else if(e.getSource()==b8)
		{
			num+="8";
			text.setText(String.valueOf((n1-n2)));
		}
		else if(e.getSource()==b9)
		{
			num+="9";
			text.setText(String.valueOf((n1-n2)));
		}
		else if(e.getSource()==b0)
		{
			num+="1";
			text.setText(String.valueOf((n1-n2)));
		}
		else if(e.getSource()==ba)
		{
			num+="0";
			text.setText(String.valueOf((n1-n2)));
		}
		else if(texte.getSource()==bs)
		{
			num+="1";
			text.setText(String.valueOf((n1-n2)));
		}
		else if(e.getSource()==bp)
		{
			num+="1";
			text.setText(String.valueOf((n1-n2)));
		}
		else if(e.getSource()==bd)
		{
			num+="1";
			text.setText(String.valueOf((n1-n2)));
		}
		else if(e.getSource()==bdo)
		{
			num+="1";
			text.setText(String.valueOf((n1-n2)));
		}
		else if(e.getSource()==be)
		{
			num+="1";
			text.setText(String.valueOf((n1-n2)));
		}
	}
	
	
	
	public static void main(String args[])
	{
		new orgcalc(); 
	}
}












