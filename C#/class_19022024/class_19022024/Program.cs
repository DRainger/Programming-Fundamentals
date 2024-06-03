using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace class_19022024
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //int[] a = { 101, 563, 870, 234, 632 };
            //int i, help, m = -1, max = -1;

            //for (i = 0; i < a.Length; i++)
            //{
            //    help = a[i];
            //    while (help != 0)
            //    {
            //        if (help % 10 > max)
            //        {
            //            max = help % 10;
            //            m = i;
            //        }
            //        help /= 10;
            //    }
            //}
            //Console.WriteLine("num = " + a[m] + " index = " + m);


            //0.129 sec<--
            int i, k = 6, max_num, min_num;
            int[] b = { 10, 56, -9, 6, 7, 88, -25, 18, 16, 23 };
            max_num = b[0];
            for (i = 1; b[i] != k; i++)
                if (max_num < b[i])
                    max_num = b[i];
            min_num = b[i + 1];
            for (; i < b.Length; i++)
                if (min_num > b[i])
                    min_num = b[i];
            Console.WriteLine("max " + max_num + " min " + min_num);

            //0.177 sec<--
            //int j, i, k = 6, max_num, min_num;
            //int[] b = { 10, 56, -9, 6, 7, 88, -25, 18, 16, 23 };
            //max_num = b[0];
            //min_num = b[b.Length - 1];
            //for (i = 0; b[i] != k; i++)
            //    if (max_num < b[i])
            //        max_num = b[i];
            //for (j = b.Length - 1; b[j] != k; j--)
            //    if (min_num > b[j])
            //        min_num = b[j];
            //Console.WriteLine("max " + max_num + " min " + min_num);
        }
    }
}
