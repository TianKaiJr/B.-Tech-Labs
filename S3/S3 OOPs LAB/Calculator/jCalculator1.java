import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class jCalculator1 implements ActionListener
{
	JFrame f=new JFrame();
	JLabel l1=new JLabel("First Number");
	JLabel l2=new JLabel("Second Number");
	JLabel l3=new JLabel("Result");
	JTextField t1=new JTextField();
	JTextField t2=new JTextField();
	JTextField t3=new JTextField();	
	JButton b1=new JButton("ADDITION");
	JButton b2=new JButton("SUBSTRACTION");
	JButton b3=new JButton("PRODUCT");
	JButton b4=new JButton("DIVISION");

	jCalculator1()
	{
		l1.setBounds(50,100,100,20);
		l2.setBounds(50,140,100,20);
		l3.setBounds(50,180,100,20);
		
		t1.setBounds(200,100,100,20);
		t2.setBounds(200,140,100,20);
		t3.setBounds(200,180,100,20);
		
		b1.setBounds(50,250,100,20);
		b2.setBounds(50,270,100,20);
		b3.setBounds(50,290,100,20);
		b4.setBounds(50,310,100,20);
		
		f.add(l1);
		f.add(l2);
		f.add(l3);
		
		f.add(t1);
		f.add(t2);
		f.add(t3);
		
		f.add(b1);
		f.add(b2);
		f.add(b3);
		f.add(b4);
		
		b1.addActionListener(this);
		b2.addActionListener(this);
		b3.addActionListener(this);
		b4.addActionListener(this);
		
		f.setLayout(null);
		f.setVisible(true);
		f.setSize(500,500);
	}
		
	public void actionPerformed(ActionEvent e)
	{
		float n1=Float.parseFloat(t1.getText());
		float n2=Float.parseFloat(t2.getText());
		if(e.getSource()==b1)
			t3.setText(String.valueOf((n1+n2)));
		if(e.getSource()==b2)
			t3.setText(String.valueOf((n1-n2)));
		if(e.getSource()==b3)
			t3.setText(String.valueOf((n1*n2)));
		if(e.getSource()==b4)
			t3.setText(String.valueOf((n1/n2)));
	}
	
	public static void main(String args[])
	{
		new jCalculator1(); 
	}	
}












