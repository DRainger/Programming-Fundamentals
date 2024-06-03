using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //task (1)
            int num;
            Console.WriteLine("Enter A number:");
            num = int.Parse(Console.ReadLine());
            Console.WriteLine("number tims 4: {0}, number smmaler by 2:{1}", num*4 , num - 2);

            //task (2)
            int height, width;
            Console.WriteLine("Enter height:");
            height = int.Parse(Console.ReadLine());
            Console.WriteLine("Enter width");
            width = int.Parse(Console.ReadLine());
            Console.WriteLine("area:{0} , circumference:{1}", height*width , height*2 + width*2);

            //task (3)
            Console.WriteLine("    1\n   222\n  33333\n 4444444\n555555555");

            //task(4)
            Console.WriteLine("   *\n  * *\n *   *\n*     *\n *   *\n  * *\n    *");

            //task(5)
            float n1, n2, n3;
            Console.WriteLine("Enter three numbers:");
            n1 = float.Parse(Console.ReadLine());
            n2 = float.Parse(Console.ReadLine());
            n3 = float.Parse(Console.ReadLine());
            Console.WriteLine("You'r numbers:{0}, {1}, {2}\nTotal={3}",n1, n2, n3, n1+n2+n3);

            //task (6)
            float num1, num2, num3;
            Console.WriteLine("Enter three numbers:");
            num1 = float.Parse(Console.ReadLine());
            num2 = float.Parse(Console.ReadLine());
            num3 = float.Parse(Console.ReadLine());
            Console.WriteLine("Multeplied: {0}", num1*num2*num3);

            //task(7)
            float a, b, c, d;
            Console.WriteLine("Enter four numbers:");
            a = float.Parse(Console.ReadLine());
            b = float.Parse(Console.ReadLine());
            c = float.Parse(Console.ReadLine());
            d = float.Parse(Console.ReadLine());

            //(A)
            Console.WriteLine("(A)Result: {0}", a+b);
            //(B)
            Console.WriteLine("(B)Result: {0}", d-b);
            //(C)
            Console.WriteLine("(C)Result: {0}", c/8);
            //(D)
            Console.WriteLine("(D)Result: {0}", d*a);

        }
    }
}
