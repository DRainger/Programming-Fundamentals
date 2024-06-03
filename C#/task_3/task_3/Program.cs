using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task_3
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //task_1
            int i, number, sum = 0;
            Console.WriteLine("Enter I.D. number WITHOUT check digit.");
            for (i = 1; i <= 8; i++) 
            {
                Console.WriteLine($"Enter digit number [{i}]:");
                number = int.Parse( Console.ReadLine() );
                if (i % 2 == 0)
                {
                    number = number * 2;
                    if (number > 9)
                        number = number / 10 + number % 10;
                }
                sum += number;
            }
            if (sum / 10 == 0)
                Console.WriteLine("check digit is 0");
            else
                Console.WriteLine($"check digit is {(80 - sum) % 10}");

            //task_2 (a)
            int j;
            for (j = 1;j <= 200; j++)
            {
                Console.Write($"{j}");
                if (j % 8 == 0)
                    Console.Write(" Good!");
                Console.WriteLine();
            }

            //task_2 (b)

            int k, num, count = 0;
            Console.WriteLine("Enter 8 two digit numbers");
            for (k = 1; k <= 8; k++)
            {
                Console.WriteLine($"[{k}] Enter a two digit number:");
                num = int.Parse(Console.ReadLine());
                if (num / 10 + num % 10 > 12)
                    count++;
            }
            Console.WriteLine($"there are {count} numbers who's sum of digits is grater then 12.");
        }
    }
}
