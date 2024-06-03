using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace class_22022024
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //----------------------  1  --------------------------
            //string str = "fghaRTNhtfvaomvR";
            //string str1 = "";
            //int i;

            //for ( i = 0; str[i] != 'a'; i++) ;
            //i += 1;
            //while (str[i] != 'a')
            //{
            //    str1 += str[i];
            //    i++;
            //}
            //Console.WriteLine(str1);
            //----------------------  1  --------------------------

            //----------------------  2  --------------------------
            //string str = "AVi Michael LIRon TESTQWErty bamba";
            //int i, c, count = 0;

            //for (i = 0; i < str.Length; i++)
            //{
            //    c = 0;

            //    while (i < str.Length && str[i] != ' ') 
            //    {
            //        if (str[i] >= 'A' && str[i] <= 'Z')
            //            c++;
            //        else
            //            c--;
            //        i++; 
            //    }
            //    if (c > 0) 
            //        count++;
            //    if (i == str.Length)
            //        break;
            //}
            //Console.WriteLine(count);

            //----------------------  2  --------------------------

            //----------------------  3  --------------------------
            string str = "AVi Michael LIRon TESTQWErty bamba";
            string str1 = "";
            string temp = "";
            int i = 0, c = 0;

            while (str[i] != ' ')
            {
                str1 += str[i];
                i++;
            }
            while (i < str.Length) 
            {
                temp = "";
                while (i < str.Length && str[i] != ' ')
                {
                    temp += str[i];
                    i++;
                }
                if (str1.Length < temp.Length)
                {
                    str1 = temp;
                    c = str1.Length;
                }
                i++;
                if (i == str.Length)
                    break;
            }
            Console.WriteLine(str1 + " cher = " + c);

            //----------------------  3  --------------------------

        }
    }
}
