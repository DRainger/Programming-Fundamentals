using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task_10
{
    internal class Program
    {
        static void Main(string[] args)
        {
            /*----------------------------- (A) -----------------------------*/
            string str = "";
            bool flag = true;
            while (flag)
            {
                Console.WriteLine("Entre a string of characters and spaces ONLY.");
                str = Console.ReadLine();
                for (int j = 0; j < str.Length; j++)
                    if (str[j] == ' ' || str[j] >= 'a' && str[j] <= 'z' || str[j] >= 'A' && str[j] <= 'Z')
                    {
                        flag = false;
                    }

                    else
                    {
                        Console.WriteLine("invalid input!");
                        flag = true;
                        break;
                    }
                Console.WriteLine("OK!");
            }
            Console.WriteLine();
            /*----------------------------- (A) -----------------------------*/
            /*----------------------------- (B) -----------------------------*/
            int x, y, i = 0 , w = 1;
            Console.WriteLine("Enter number for starting word:");
            x = int.Parse(Console.ReadLine());
            Console.WriteLine("Enter number of words to print:");
            y = int.Parse(Console.ReadLine());

            while (i < str.Length)
            {
                
                if (x == w)
                {
                    
                    for (int j = 1;j <= y; j++)
                    {
                        if (str[i] == ' ') 
                            i++;
                        else if (i == str.Length)
                        {
                            Console.WriteLine("words missing");
                            break;
                        }
                        while (str[i] != ' ')
                        {
                            Console.Write(str[i]);
                            i++;
                        }
                        Console.WriteLine();
                    }
                    break;
                }
                else if (i > str.Length)
                {
                    Console.WriteLine($"word {x} dos not exist");
                    break;
                }
                else
                {
                    while (str[i] != ' ')
                    {
                        if (i == str.Length)
                            break;
                        i++;  
                    }
                    w++;      
                }
            }

            /*----------------------------- (B) -----------------------------*/
        }
    }
}
