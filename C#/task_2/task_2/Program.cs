using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task_2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //task_1
            int h , m , s , t ;
            Console.WriteLine("Enter time (hour -> minutes -> seconds):");
            h = int.Parse(Console.ReadLine());
            m = int.Parse(Console.ReadLine());
            s = int.Parse(Console.ReadLine());
            Console.WriteLine("Enter missile Air-time in seconds:");
            t = int.Parse(Console.ReadLine());
            Console.WriteLine("{0}:{1}:{2}",(h + (m + (s + t) / 60) / 60) % 60, (m + (s + t) / 60) % 60, (s + t) % 60);

            //---------------------------------------------------------------------------------------------------------

            //task_2
            int n1 , n2 , n3 ;
            Console.WriteLine("Enter three numbers:");
            n1 = int.Parse(Console.ReadLine());
            n2 = int.Parse(Console.ReadLine());
            n3 = int.Parse(Console.ReadLine());
            if (n1 < n2 && n2 < n3)
            {
                Console.WriteLine("Ascending!");
            }
            else if (n1 > n2 && n2>n3)
            {
                Console.WriteLine("Descending!");
            }
            else
            {
                Console.WriteLine("Not sorted");
            }
        }
    }
}
