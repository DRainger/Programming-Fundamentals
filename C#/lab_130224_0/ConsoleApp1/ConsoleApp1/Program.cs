using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //string str = Console.ReadLine();
            //char c = (char)Console.Read();
            //int count = 0;

            //for (int i = 0; i < str.Length; i++)
            //{
            //    if (c == str[i])
            //        count++;
            //}
            //Console.WriteLine(count);

            //string str1 = "Aba ima bamba";
            //string str2 = "";
            //int i = 0;

            //Console.WriteLine(str1);
            //while (i < str1.Length)
            //{
            //    if (str1[i] <= 'a' && str1[i] <= 'z')
            //        str2 += (char)( str1[i + 1] - 32);
            //    else
            //        str2 += str1[i];
            //    i++;
            //    while (i < str1.Length && str1[i] != ' ') 
            //    {
            //        str2 += str1[i];
            //        i++;
            //    }
            //    str2 += ' ';
            //    if (i < str1.Length)
            //        i++;
            //}
            //Console.WriteLine(str2);

            Console.WriteLine("Enter username:");
            string user = Console.ReadLine();
            Console.WriteLine("Enter pasword:");
            int pass = int.Parse(Console.ReadLine());
            int i = 0, sum = 0;

            while (i < user.Length)
            {
                sum += user[i] - 'A';
                i++;
            }
            if (pass == sum)
                Console.WriteLine("Access Approved");
            else
                Console.WriteLine("Access Denide");
        }
    }
}
