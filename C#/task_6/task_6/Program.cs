using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task_6
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //(1)
            int[] a = new int[4];
            int i, sum = 0;
            for (i = 0; i < a.Length; i++)
            {
                Console.WriteLine("Enter number: ");
                a[i] = int.Parse(Console.ReadLine());
                while (a[i] != 0)
                {
                    sum += a[i] % 10;
                    a[i] /= 10;
                }
            }
            Console.WriteLine("sum is: " + sum);

            //(2)
            int[] b = new int[8];
            bool flag = false;
            for (int j = 0; j < b.Length; j++)
            {
                Console.WriteLine("Enter number: ");
                b[j] = int.Parse(Console.ReadLine());
            }
            for (int j = 0; j < b.Length; j += 2)
                if (b[j] == b[j + 1])
                    flag = true;

                else
                    flag = false;

            if (flag)
                Console.WriteLine("Good");
            else
                Console.WriteLine("Bad");

            //(3)
            int[] c = { 1, 2, 3, 3, 2, 1 };
            bool f = true;
            for (int k = 0; k < c.Length / 2; k++)
                if (c[k] != c[c.Length - 1 - k])
                    f = false;
            if (f)
                Console.WriteLine("YES");
            else
                Console.WriteLine("NO");

            //(4)
            //for (int i = 1; i <= 7; i++)
            //{
            //    Console.Write(i);
            //    if (i == 1 || i == 4 || i == 7)
            //        for (int j = 1; j <= 3; j++)
            //            Console.Write(i);
            //    Console.WriteLine();
            //}

        }
    }
}
