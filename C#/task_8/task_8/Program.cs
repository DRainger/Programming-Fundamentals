using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task_8
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] c = new int[100];
            int[] a = new int[20];//{ 1, 2, 2, 3, 4, 6, 2, 7, 8, 9, 9, 9, 9, 9, 2, 3, 4, 6, 2, 9 };
            int[] b = new int[20];//{ 2, 2, 2, 3, 4, 5, 7, 8, 9, 7, 12, 23, 4, 5, 5, 5, 5, 4, 4, 7 };
            int i , j ;
            bool flag;
            Random rand = new Random();

            for (i = 0; i < b.Length; i++)
            {
                a[i] = rand.Next(1, 100);
                b[i] = rand.Next(1, 100);
            }
            for (i=0; i < a.Length; i++)
            {
                Console.Write(a[i] + ", ");
            }
            Console.WriteLine();
            for (i = 0; i < b.Length; i++)
            {
                Console.Write(b[i] + ", ");
            }
            Console.WriteLine("\n");

            for(i = 0; i < a.Length;i++)
            {
                flag = false;
                for(j = 0; j < b.Length; j++)
                {
                    if (a[i] == b[j])
                    { flag = true; break; }
                }
                if (!flag)
                    c[a[i]-1]++;
            }
            for (i = 0; i < b.Length; i++)
            {
                flag = false;
                for (j = 0; j < a.Length; j++)
                {
                    if (b[i] == a[j])
                    { flag = true; break; }
                }
                if (!flag)
                    c[b[i]-1]++;
            }
            for (i = 0; i < c.Length; i++)
            {
                if (c[i] != 0)
                    Console.Write((i + 1) + ", ");
            }
            Console.WriteLine();

            c = new int[100];
            int max = 0, k=-1;
            for(i=0; i < a.Length; i++) 
                c[a[i] - 1]++;
            for (i = 0; i < c.Length; i++)
                if (c[i] > k)
                {
                    max = i + 1;
                    k = c[i];
                }
            Console.WriteLine($"the number that appears the most times in the first array: {max}, appears {k} times");

            c = new int[100];
            max = 0; k = -1;
            for (i=0; i < a.Length;i++)
                c[a[i]-1]++;
            for (i = 0; i < b.Length; i++)
                if (c[b[i] - 1] != 0 )
                    c[b[i] - 1]++;
                else
                    c[b[i] - 1] = 0;
            for (i = 0; i < c.Length; i++)
                if (c[i] > k)
                {
                    max = i + 1;
                    k = c[i];
                }
            Console.WriteLine($"the number that appears the most times in both arrays: {max}, appears {k} times");
        }
    }
}
