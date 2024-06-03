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
            //(1)
            int[] a = new int[20];
            int[] b = new int[10];
            int i, j, max = 1, li = 2, lj = 3;

            for (i = 0; i < a.Length; i++)
            {
                Console.WriteLine("Enter number:");
                a[i] = int.Parse(Console.ReadLine());
            }
            for (i = 0, j = a.Length - 1; i < j; i++, j--)
            {
                b[i] = a[j] + a[i];
                if (i == 0)
                {
                    max = b[i];
                    li = i; lj = j;
                }
                else if (b[i] > max)
                {
                    max = b[i];
                    li = i; lj = j;
                }
            }
            for (i = 0; i < b.Length; i++)
            {
                Console.Write(b[i] + " ");
            }
            Console.WriteLine($"\nmaximum sum is: {max}, location: ({li + 1}, {lj + 1})");


            //(2)
            int[] arr = new int[20];
            int k, help, tmp_sum, max_sum = 0, l = 10000;
            for (k = 0; k < arr.Length; k++)
            {
                Console.WriteLine("Enter number:");
                arr[k] = int.Parse(Console.ReadLine());
            }
            for (k = 0; k < arr.Length; k++)
            {
                tmp_sum = 0;
                help = arr[k];
                while (help > 0)
                {
                    tmp_sum += help % 10;
                    help /= 10;
                }
                if (tmp_sum > max_sum || k == 0)
                {
                    max_sum = tmp_sum;
                    l = k;
                }
            }
            Console.WriteLine("number with maximum digit sum is:" + arr[l]);


            //(3)
            int[] ar = { 524, 2689, 486, 9123, 26789, 3671 };
            int y, g = 0, temp;
            bool flag = false;

            for (y = 0; y < ar.Length; y++)
            {
                temp = ar[y];
                while (temp != 0)
                {
                    if (temp % 10 < (temp / 10) % 10)
                    {
                        flag = false;
                        break;
                    }
                    else
                        flag = true;
                    temp /= 10;
                }
                if (flag)
                    g++;
            }
            int[] ar2 = new int[g];
            g = 0;
            for (y = 0; y < ar.Length; y++)
            {

                temp = ar[y];
                while (temp != 0)
                {
                    if (temp % 10 < (temp / 10) % 10)
                    {
                        flag = false;
                        break;
                    }
                    else
                        flag = true;
                    temp /= 10;
                }
                if (flag)
                {
                    ar2[g] = ar[y];
                    g++;
                }
            }
            for (y = 0; y < ar2.Length; y++)
            {
                Console.Write(ar2[y] + " ");
            }

        }
    }
}
