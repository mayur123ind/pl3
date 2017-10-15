import java.io.*;
import java.net.*;
class client
{
	public static void main(String[] args)
	{
		try
		{
			Socket s=new Socket("localhost",6666);
			DataOutputStream dout=new DataOutputStream(s.getOutputStream());
			dout.writeUTF("Hello Server");
			DataInputStream din=new DataInputStream(s.getInputStream());
			String str=(String)din.readUTF();
			System.out.println("message="+str);
			dout.close();
			s.close();
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
}

/*unix@unix-HP-280-G1-MT:~$ javac client.java
unix@unix-HP-280-G1-MT:~$ java client
message=Hello Client
*/
