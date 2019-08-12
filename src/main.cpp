#include <iostream>

#include <SampleClass.hpp>
#include <Containers/Vector.hpp>

void tryMyStlLibrary()
{
    SampleClass a1[10] =
    {
        SampleClass(1,"Num1"),
        SampleClass(2,"Num2"),
        SampleClass(3,"Num3"),
        SampleClass(4,"Num4"),
        SampleClass(5,"Num5"),
        SampleClass(6,"Num6"),
        SampleClass(7,"Num7"),
        SampleClass(8,"Num8"),
        SampleClass(9,"Num9"),
        SampleClass(10,"Num10"),
    };

}

int main(int /*argc*/, char** /*argv*/)
{
    std::cout << "\nThis is just a library";
    tryMyStlLibrary();

    std::cout << "\nEnd\n";
    return 0;
}
