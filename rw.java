class reader extends Thread
{
public void run()
{
while(rw.mutex<=0)
{
System.out.println("reader has to be wait until writer come out");
}
rw.mutex=0;
rw.count++;
if(rw.count==1)
{
System.out.println("Iam the first reader");
while(rw.rw_mutex<=0)
{
System.out.println("reader1 has to be wait until writer come out");
}
}
rw.mutex++;
System.out.println("reader is reading the data.");
rw.mutex=0;
rw.count--;
if(rw.count==0)
{
rw.rw_mutex=1;
}
rw.mutex=1;
} 
}
class writer extends Thread
{
public void run()
{
while(rw.rw_mutex<=0)
{
System.out.println("Writer has to be wait.");
}
rw.rw_mutex=0;
System.out.println("Writer is writing the data");
rw.rw_mutex=1;
}
}
class rw
{
static int rw_mutex=1;
static int mutex=1;
static int count=0;
public static void main(String ar[])
{
reader ob=new reader();
reader ob2=new reader();
writer ob1=new writer();
ob.start();
ob1.start();
}
}