using System;

namespace CourseForteenProgram
{
    internal class Program
    {
        struct stStudent
        {
            public string FirstName;
            public string LastName;
        }

        static void Main(string[] args)
        {

            //A struct object can be created with or without the new operator,
            //same as primitive type variables.

            stStudent Student;
            stStudent Student2 = new stStudent();


            Student.FirstName = "Aya";
            Student.LastName = "Ragab";


            Console.WriteLine(Student.FirstName);
            Console.WriteLine(Student.LastName);


            Student2.FirstName = "Ayaa";
            Student2.LastName = "R.";


            Console.WriteLine(Student2.FirstName);
            Console.WriteLine(Student2.LastName);

            Console.ReadKey();

        }

    }
}
