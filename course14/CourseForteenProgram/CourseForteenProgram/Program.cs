using System;

namespace CourseForteenProgram
{
    internal class Program
    {
        static int factorial(int num)
        {
            if (num == 1)
                return 1;
            return num * factorial(num - 1);
        }
        static void Main(string[] args)
        {
            int num;
            Console.WriteLine("Enter a number to get its factorial:");
            num = int.Parse(Console.ReadLine());
            Console.WriteLine(factorial(num));
        }
    }
}
