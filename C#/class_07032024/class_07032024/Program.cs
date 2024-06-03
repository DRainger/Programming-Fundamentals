using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace class_07032024
{
    internal class Program
    {
        static void Main(string[] args)
        {
            /*------------------------- (1) -------------------------*/
            //string str = "michaelh tcb,ac,il";
            //char ch1 = ' ', ch2 = '@', ch3 = ',', ch4 = '.';
            //int k = 0;
            //Console.WriteLine(str);
            //while (k < str.Length)
            //{

            //    if (str[k] == ch1)
            //    {
            //        str = str.Remove(k,1);
            //        str = str.Insert(k, ch2.ToString());
            //    }

            //    else if (str[k] == ch3)
            //    {
            //        str = str.Remove(k, 1);
            //        str = str.Insert(k, ch4.ToString());
            //    }
            //    k++;
            //}
            //Console.WriteLine(str);
            /*------------------------- (1) -------------------------*/

            /*------------------------- (2) -------------------------*/

            StringBuilder str1 = new StringBuilder("abcd 1234 test 246");
            int i =0, j;
            char help = ' ';
            Console.WriteLine(str1);
            while (i < str1.Length)
            {
                if (str1[i] >= '0' && str1[i] <= '9')
                {
                    for (j = i; j < str1.Length && str1[j] != ' '; j++);
                    j--;
                    while (j > i)
                    {
                        help = str1[i];
                        str1[i] = str1[j];
                        str1[j] = help;
                        i++;
                        j--;
                    }
                    while (i < str1.Length && str1[i] != ' ');
                        i++;
                }
                else
                    while (i < str1.Length && str1[i] != ' ') ;
                        i++;
                if (i == str1.Length)
                    break;
            }
            Console.WriteLine(str1);

            /*------------------------- (2) -------------------------*/
        }
    }
}
