using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task_9
{
    internal class Program
    {
        static void Main(string[] args)
        {
            /*---------------------------- (1) ----------------------------*/
            Console.WriteLine("Enter string:");
            string str = Console.ReadLine();
            int i = 0, c = 0, n;
            Console.WriteLine("Enter number of a word to print");
            n = int.Parse(Console.ReadLine());
            while (i < str.Length)
            {
                c++;
                while (i < str.Length && str[i] != ' ')
                {
                    if (c == n)
                        break;
                    i++;
                }
                while (i < str.Length && str[i] != ' ')
                {
                    Console.Write(str[i]);
                    i++;
                }
                if (i == str.Length && c == n)
                    break;
                i++;
            }
            Console.WriteLine();
            /*---------------------------- (1) ----------------------------*/

            /*---------------------------- (2) ----------------------------*/
            Console.WriteLine("Enter a string to find:");
            string str1 = Console.ReadLine();
            Console.WriteLine("Enter a string to serch in:");
            string str2 = Console.ReadLine();
            string tmp;
            int j = 0, k, count = 0;
            while (j < str2.Length)
            {
                tmp = "";
                k = 0;
                while (k < str1.Length)
                {
                    if (j == str2.Length)
                        break;
                    tmp += str2[j];
                    j++;
                    k++;
                }
                if (tmp == str1)
                    count++;
                if (j == str2.Length)
                    break;
                j -= k - 1;
            }
            Console.WriteLine(count);
            /*---------------------------- (2) ----------------------------*/

            /*---------------------------- (3) ----------------------------*/
            string str0 = "mom dad sons daughter";
            int m = 0, l, c0 = 0;
            while (m < str0.Length)
            {
                for (l = m + 1; l < str0.Length && str0[l] != ' '; l++) ;
                if (str0[l - 1] == str0[m])
                    c0++;
                if (l == str0.Length)
                    break;
                m = l + 1;
            }
            Console.WriteLine(c0);
            //(l = m + 1, m = l + 1) is for jumping over spases to the begning of the word.
            /*---------------------------- (3) ----------------------------*/
        }
    }
}
