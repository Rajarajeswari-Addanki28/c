class process0 extends Thread
{
    public void run()
    {
      peterson.flag[0]="TRUE";
      peterson.turn=1;
     while(peterson.flag[1]=="TRUE" && peterson.turn==1)
    {
     System.out.println("P0 in blocked state.");
    }
    System.out.println("process0 is executing critical section");
    peterson.flag[0]="FALSE";
    }
}


class process1 extends Thread
{
   public void run()
  {
    peterson.flag[1]="TRUE";
    peterson.turn=0;
    while(peterson.flag[0]=="TRUE" && peterson.turn==0)
    {
    System.out.println("P1 in blocked state.");
    }
    System.out.println("process1 is executing critical section");
    peterson.flag[1]="FALSE";
    }
}


class peterson 
{
   static String flag[]={"FALSE","FALSE"};
   public static int turn;
   public static void main(String ar[])
  {
  process0 ob=new process0();
  process1 ob1=new process1();
  ob.start();
  ob1.start();
  }
}