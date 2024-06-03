using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace home_22022024_1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //flip string
            string str = "abcdef";
            string str1 = "";

            for (int i = str.Length - 1; i >= 0; i-- )
            {
                str1 += str[i];
            }
            Console.WriteLine(str1);

        }
    }
}
