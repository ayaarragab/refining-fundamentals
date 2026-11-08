using System;

namespace Main
{
    internal class Program
    {

        static void Main(string[] args)
        {
            int[ , ] array2d = new int[2, 2] { {1, 2 }, { 1, 3} };
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    Console.Write(array2d[i, j] + " ");
                }
                Console.WriteLine();
            }
        }
    }
}
