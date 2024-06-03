using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace home_22022024
{
    internal class Program
    {
        static void Main(string[] args)
        {
            char ch = 'a';



            bool IsUpper(char c)
            {
                if (c >= 'A' && c <= 'Z') 
                    return true;
                return false;
            }

            bool IsLower(char c)
            {
                if ((c >= 'a' && c <= 'z'))
                    return true;
                return false;
            }

            bool IsDigit (char c)
            {
                if ( c >= '0' && c <= '9')
                    return true;
                return false;
            }

            char ToUpper(char c)
            { return (char)(c - 32); }

            char ToLower(char c)
            { return (char)(c + 32); }

            int CharToNum(char c)
            { return (int)c; }

            char NextChar(char c)
            { return (char)(c+1); }

            char PrevChar(char c)
            { return (char)(c - 1); }

            char NextLetter(char c)
            {
                for (int i = 1;i <= 25; i++)
                {
                    if (IsUpper(c) && (char)(c + 1) > 'Z')
                        c = 'A';
                    else if (IsLower(c) && (char)(c + 1) > 'z')
                        c = 'a';
                    c++;
                }
                return c;
            }
             
            char PrevLetter(char c)
            {
                for (int i = 1; i <= 25; i++)
                {
                    if (IsUpper(c) && (char)(c - 1) < 'A')
                        c = 'Z';
                    else if (IsLower(c) && (char)(c - 1) < 'a')
                        c = 'z';
                    c--;
                }
                return c;
            }

            Console.WriteLine(ch + " --> "+ NextLetter(ch));

        }
    }
}
