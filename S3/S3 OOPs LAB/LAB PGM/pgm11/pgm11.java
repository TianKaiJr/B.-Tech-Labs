import java.util.*;

class DoublyLinkedList
{    
	class Node
	{  
		int data;  
		Node prev;  
		Node next;  
		public Node(int data)
		{  
			this.data = data;
		}  
	}  
	
	Node head,tail = null;  
   
	public void insert(int data)
	{  
		Node temp = new Node(data);  
		if(head == null)
		{  
			head = tail = temp;  
			head.prev = null;  
			tail.next = null;  
		}  
		else
		{  
			tail.next = temp;  
			temp.prev = tail;  
			tail = temp;  
			tail.next = null;  
		}
		System.out.print(data+" >> INSERTED\n");  
	}
	
	public void delete()
	{
		if(head == null)
		{
			System.out.print("List is empty");
		}
		else
		{
			int data = head.data;
			head = head.next;
			head.prev = null;
			System.out.print(data+" >> DELETED\n");
		}
	}
	
	public void printlist()
	{  
		Node current = head;  
		if(head == null)
		{  
			System.out.println("List is empty");  
			return;  
		}
		else
		{
			System.out.print("List = [");  
			while(current != null)
			{  
				System.out.print(current.data + ",");  
				current = current.next;  
			} 
			System.out.println("\b]");
		}   
	} 
}
public class pgm11
{
	public static void main(String[] args)
	{  
		DoublyLinkedList dll = new DoublyLinkedList();
		int ch = 0;
		while(ch != 4)
		{
			System.out.print("\n### MENU ###\n");
			System.out.print("1.Insert at End\n");
			System.out.print("2.Delete from Front\n");
			System.out.print("3.Display Linked List\n");
			System.out.print("4.Exit\n");
			System.out.print("Enter your choice = ");
			Scanner s = new Scanner(System.in);
			ch = s.nextInt();
			switch(ch)
			{
				case 1:
				{
					System.out.print("Enter the element = ");
					int data = s.nextInt();
					dll.insert(data);
					break;
				}
				case 2:
				{
					dll.delete();
					break;
				}
				case 3:
				{
					dll.printlist();
					break;
				}
				case 4:
				{
					break;
				}
				default:System.out.println("Invalid choice");
			}
		} 
	}  
} 
