using System.Threading;
namespace programming_year_2;
{
    public class Thread
    {
        public static void Main(string[] args)
        {
            Thread t = new ThreadStart(PrintSomething);
        }
    }

    public static void PrintSomething()
    {
        lock(this) // allows thread to run to completion before another thread can run
        for (int i = 0; i < 10; i++)
        {
            Console.WriteLine("Printing something");
            Thread.Sleep(1000); // break for 1 second
        }
    }
}