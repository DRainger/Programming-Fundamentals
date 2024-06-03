using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Remoting.Services;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //int[] a = { 1, 2, 9, 2, 4, 5, 4 };
            //int i, j =0, c = 0;
            //for (i = 1; i < a.Length - 1; i++)
            //    if (a[i - 1] == a[i + 1])
            //        c++;
            //int[] b = new int[c];
            //for (i = 1; i < a.Length - 1; i++)
            //    if (a[i - 1] == a[i + 1])
            //    {
            //        b[j] = a[i];
            //        j++;
            //    }
            //for (i = 0; i < b.Length; Console.Write(b[i]+" "), i++);
            //Console.WriteLine();

            //int[] a = { 2,2,2,2,2,2,2,2 };
            //int i, j = 0, c = 0;
            //for (i = 0; i < a.Length - 1; i++)
            //    if (a[i] == a[i + 1])
            //        c++;
            //int[] b = new int[c*2];
            //for (i = 0; i < a.Length - 1; i++)
            //    if (a[i] == a[i + 1])
            //    {
            //        b[j] = b[j+1] = a[i];
            //        j+=2;
            //    }
            //Console.Write("{ ");
            //for (i = 0; i < b.Length; Console.Write(b[i] + ", " ), i++) ;
            //Console.WriteLine("} |"+c*2);

            int[] a = new int[8];
            int i, j, max_fail;
            for (j = 0; j < 6; j++)
            {
                Console.WriteLine("Enter grade");
                max_fail = 0;
                for (i = 0; i < a.Length; i++)
                {
                    if (a[i] < 60)
                        if (a[i] > max_fail)
                            max_fail = a[i];
                }
                Console.WriteLine($"maximum failed grade in class {j}: " + max_fail);
            }
        }
    }
}
