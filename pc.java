import java.util.*;
class producer extends Thread
{
public void run()
{
Scanner ob2=new Scanner(System.in);
int n;
while(pc.empty<=0)
{
System.out.println("Buffer is full");
}
pc.empty--;
while(pc.mutex<=0)
{
System.out.println("producer has to be wait while consumer consuming the item.");
}
pc.mutex=0;
System.out.println("enter the data");
int n1=ob2.nextInt();
pc.buffer[pc.in]=n1;
pc.in=(pc.in+1)%5;
pc.mutex=1;
pc.full++;
}
}


class consumer extends Thread
{
public void run()
{
while(pc.full<=0)
{
/*try
{
sleep(3000);
}
catch(InterruptedException e)
{
System.out.println("exception");
}
*/
System.out.println("consumer has to be wait until producer produces the item");
}
pc.full--;
while(pc.mutex<=0)
{
System.out.println("consuming has to be wait while producer producing the item.");
}
pc.mutex=0;
System.out.println("consumer consuming the item.");
int nextconsumed=pc.buffer[pc.out];
System.out.println("consumed item is: "+nextconsumed);
pc.out=(pc.out+1)%5;
pc.mutex=1;
pc.empty++;
}
}
class pc
{
static int in=0;
static int out=0;
static int mutex=1;
static int full=0;
static int empty=5;
static int buffer[]=new int[5];
public static void main(String ar[])
{
producer ob=new producer();
consumer ob1=new consumer();
ob.start();
ob1.start();
}
}