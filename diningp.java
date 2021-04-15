class philosopher extends Thread
{
public void run()
{
System.out.println("Initially philosopher in thinking state.");
while(diningp.mutex<=0)
{
System.out.println("philosopher has to be wait while another philosopher is eating");
}
diningp.mutex=0;
System.out.println("Take the left fork");
System.out.println("Take the right fork");
System.out.println("Eating");
System.out.println("Put the left fork");
System.out.println("Put the right fork");
diningp.mutex=1;
}
}
class diningp
{
static int mutex=1;
public static void main(String ar[])
{
philosopher ob=new philosopher();
philosopher ob1=new philosopher();
ob.start();
ob1.start();
}
}