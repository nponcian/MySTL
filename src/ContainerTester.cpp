#include <ContainerTester.hpp>

#include <string>

#include <SampleClass.hpp>
#include <Containers/Vector.hpp>

namespace src
{

void testContainer()
{
    SampleClassInt sampleClass[] =
    {
        SampleClassInt(0),
        SampleClassInt(1),
        SampleClassInt(2),
        SampleClassInt(3),
        SampleClassInt(4),
        SampleClassInt(5),
        SampleClassInt(6),
        SampleClassInt(7),
        SampleClassInt(8),
        SampleClassInt(9),
    };
    // SampleClassIntAndStr sampleClass[] =
    // {
    //     SampleClassIntAndStr(0,"Num0"),
    //     SampleClassIntAndStr(1,"Num1"),
    //     SampleClassIntAndStr(2,"Num2"),
    //     SampleClassIntAndStr(3,"Num3"),
    //     SampleClassIntAndStr(4,"Num4"),
    //     SampleClassIntAndStr(5,"Num5"),
    //     SampleClassIntAndStr(6,"Num6"),
    //     SampleClassIntAndStr(7,"Num7"),
    //     SampleClassIntAndStr(8,"Num8"),
    //     SampleClassIntAndStr(9,"Num9"),
    // };

    // Put your code here, remember to clean it up!

    mystl::vector<SampleClassInt> vec;
    printUsingAtAndSize(vec);

    vec.push_back(sampleClass[0]);
    vec.push_back(sampleClass[1]);
    vec.push_back(sampleClass[2]);
    printUsingBracketAndSize(vec);

    vec.push_back(sampleClass[3]);
    vec.push_back(sampleClass[4]);
    vec.push_back(sampleClass[5]);
    printUsingAtAndSize(vec);

    vec.push_back(sampleClass[6]);
    vec.push_back(sampleClass[7]);
    vec.push_back(sampleClass[8]);
    printUsingBracketAndSize(vec);

    vec.push_back(sampleClass[9]);
    vec.push_back(sampleClass[0]);
    vec.push_back(sampleClass[1]);
    printUsingAtAndSize(vec);

    // End of code
}

} // namespace src