import java.io.*;
import java.net.*;
class server
{
	public static void main(String[] args)
	{
		try
		{
			ServerSocket S=new ServerSocket(6666);
			Socket s=S.accept();
			DataInputStream din=new DataInputStream(s.getInputStream());
			String str=(String)din.readUTF();
			System.out.println("message="+str);
			DataOutputStream dout=new DataOutputStream(s.getOutputStream());
			dout.writeUTF("Hello Client");
			S.close();
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
}
/*unix@unix-HP-280-G1-MT:~$ javac server.java
unix@unix-HP-280-G1-MT:~$ java server
message=Hello Server
*/
