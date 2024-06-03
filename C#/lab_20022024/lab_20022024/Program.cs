using System;
using System.Collections.Generic;
using System.Diagnostics.Tracing;
using System.Linq;
using System.Reflection;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace lab_20022024
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string s = "dan koby luichsd dan";
            string s1 = "";
            string s2 = "";
            int i, j;
            bool b = false;
            for (i = 0, j = s.Length-1; s[i] != ' '; i++)
            {
                s1 += s[i];
                s2 += s[j];
            }
            for (i=0, j = s2.Length; i < s1.Length; i++)
            {
                b = false;
                if (s1[i] == s2[j])
                    b = true;
            }
            if (b) Console.WriteLine("OK");
            else Console.WriteLine("NO");
        }
    }
}
