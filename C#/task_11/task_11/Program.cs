using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task_11
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string country = "1France 2Germany 3USA 4Canada";
            string capital = "1 paris 2 berlin 3 washington 4 ottawa";
            string help = "";
            Console.WriteLine("Please select a country:");
            Console.WriteLine(".1. France .2. Germany .3. USA .4. Canada");
            int choice = int.Parse(Console.ReadLine()) , i = 0, w = 1;
            Console.WriteLine("Please write down capital city's name");
            string answer = Console.ReadLine();
            int k = capital[capital.IndexOf(answer.ToLower()) -2];
            //while (i < capital.Length)
            //{
            //    if (capital[i] == ' ')
            //    {
            //        if (w == choice)
            //            break;
            //        w++;
            //    }
            //    if (i == capital.Length)
            //        break;
            //    i++; 
            //}
            //for (i--; i >= 0 && capital[i] != ' '; i--) ;
            //i++;
            //while ( capital[i] != ' ' && i < capital.Length)
            //{
            //    help += capital[i];
            //    if (i == capital.Length - 1)
            //        break;
            //    else
            //        i++;    
            //}
            Console.WriteLine(capital.IndexOf(answer.ToLower()));
            Console.WriteLine(k);
            if (choice == k)
                Console.WriteLine("You are Right!");
            else Console.WriteLine("You are Wrong!");
        }
    }
}
