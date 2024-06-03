using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab_130224_0
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //(1)
            //int[] a = { 5, 12, 5, 2, 3, 7, 12, 7, 8, 8, 2, 3 };
            //int[] b = new int[12];
            //int i, j, s=0, e=b.Length-1;
            //bool flag;


            //for (i = 0; i < a.Length; i++)
            //{
            //    flag = false;
            //    for (j = i + 1; j < a.Length; j++)
            //        if (a[j] == a[i])
            //        {
            //            flag = true;
            //            break;
            //        }
            //    if (flag)
            //    {
            //        b[s] = b[e] = a[j];
            //        s++;
            //        e--;
            //    }

            //}
            //for(i = 0; i < b.Length; i++)
            //    Console.Write(b[i]+" ");
            //Console.WriteLine();

            //(2)
            int[] arr = { 5, 8, 9, 10, 15, 18, 30 };
            int i, j, s;
            bool f = false;

            Console.WriteLine("Enter number: ");
            s = int.Parse(Console.ReadLine());
            for (i = 0; i < arr.Length && f == false; i++)// תנאי של דגל בתוך הלולאה במקום במרחב שלה
                for (j = i + 1; j < arr.Length; j++)
                {
                    if (arr[j] + arr[i] == s)
                    {
                        f = true;
                        break;
                    }
                    if (arr[j] + arr[i] > s)// תנאי לבדוק עם הערך במערך גדול מהסכום כי בשליו זה אין תעם לבדוק
                        break;
                }

            if (!f)
                Console.WriteLine("no");
            else Console.WriteLine("yes");
        }
    }
}
