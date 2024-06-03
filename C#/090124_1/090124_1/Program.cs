using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _090124_1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            ////(1)
            //int a, b;
            //Console.WriteLine("Enter 2 numbers:");
            //a = int.Parse(Console.ReadLine());
            //b = int.Parse(Console.ReadLine());
            //if (a % b == 0)
            //{
            //    Console.WriteLine($"Division:{a / b}");
            //}
            //else
            //{
            //    Console.WriteLine($"Remainder:{a % b}");
            //}


            ////(2)
            //int num;
            //Console.WriteLine("Enter a 4 digit number:");
            //num = int.Parse(Console.ReadLine());
            //if (num / 1000 == num % 10 && num / 100 % 10 == num / 10 % 10)
            //{
            //    Console.WriteLine($"sum all digits:{num / 1000 + num / 100 % 10 + num / 10 % 10 + num % 10}");
            //}
            //else
            //{
            //    Console.WriteLine($"sum middle digits:{num / 100 % 10 + num / 10 %10}");
            //}


            ////(3)
            //int number;
            //Console.WriteLine("Enter number:");
            //number = int.Parse(Console.ReadLine());
            //if (number % 2 == 0)
            //{
            //    Console.WriteLine("YES!");
            //}
            //else
            //{
            //    Console.WriteLine("NO!");
            //}

            ////(4)
            //int g1, g2, g3, g4;
            //Console.WriteLine("Enter grades:");
            //g1 = int.Parse(Console.ReadLine());
            //g2 = int.Parse(Console.ReadLine());
            //g3 = int.Parse(Console.ReadLine());
            //g4 = int.Parse(Console.ReadLine());
            //if (g1 < 55 || g2 < 55 || g3 < 55 || g4 < 55)
            //{
            //    Console.WriteLine("Failing grade.");
            //}
            //if ((g1 + g2 + g3 + g4) / 4.0 >= 56 && (g1 + g2 + g3 + g4) / 4.0 <= 65)
            //{
            //    Console.WriteLine("Okey.");
            //}
            //if ((g1 + g2 + g3 + g4) / 4.0 >= 66 && (g1 + g2 + g3 + g4) / 4.0 <= 79)
            //{
            //    Console.WriteLine("Good.");
            //}
            //if ((g1 + g2 + g3 + g4) / 4.0 >= 80)
            //{
            //    Console.WriteLine("Very Good!");
            //}

            ////(5)
            //int salery;
            //Console.WriteLine("Enter salery:");
            //salery = int.Parse(Console.ReadLine());
            //if (salery / 10.0 + salery > 6000)
            //{
            //    Console.WriteLine($"A 5% Raise:{salery + salery / 5.0}");
            //}
            //else
            //{
            //    Console.WriteLine($"A 10% Raise:{salery + salery / 10.0}");
            //}

            //(6)
            int sal;
            Console.WriteLine("Enter salery:");
            sal = int.Parse(Console.ReadLine());
            if (sal <= 1999)
            {
                Console.WriteLine("No tax.");
            }
            if (sal <= 3500 && sal >= 2000)
            {
                Console.WriteLine($"20% tax: {(sal - 1999) * 0.2:f}");
            }
            else if (sal > 3500)
            {
                Console.WriteLine($"for 2000 to 3500 tax is 20% any NIS over 3500 tax is 30%:{300 + (sal - 3500) * 0.3:f}");
            }


        }
    }
}

