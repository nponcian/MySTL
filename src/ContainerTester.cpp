#include <ContainerTester.hpp>

#include <string>

#include <SampleClass.hpp>
#include <Containers/Set.hpp>
#include <Containers/Vector.hpp>

namespace src
{
namespace
{

SampleClassInt sampleClassInt[] =
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

SampleClassIntAndStr sampleClassIntAndStr[] =
{
    SampleClassIntAndStr(0,"Num0"),
    SampleClassIntAndStr(1,"Num1"),
    SampleClassIntAndStr(2,"Num2"),
    SampleClassIntAndStr(3,"Num3"),
    SampleClassIntAndStr(4,"Num4"),
    SampleClassIntAndStr(5,"Num5"),
    SampleClassIntAndStr(6,"Num6"),
    SampleClassIntAndStr(7,"Num7"),
    SampleClassIntAndStr(8,"Num8"),
    SampleClassIntAndStr(9,"Num9"),
};

void testContainerOnVector()
{
    mystl::vector<SampleClassInt> vec;

    vec.push_back(sampleClassInt[0]);
    vec.push_back(sampleClassInt[1]);
    vec.push_back(sampleClassInt[2]);
    printUsingBeginToEndUsingLessCompare(vec);

    vec.push_back(sampleClassInt[3]);
    vec.push_back(sampleClassInt[4]);
    vec.push_back(sampleClassInt[5]);
    printUsingConstBeginToEndUsingLessCompare(vec);

    vec.push_back(sampleClassInt[6]);
    vec.push_back(sampleClassInt[7]);
    vec.push_back(sampleClassInt[8]);
    printUsingRangeBasedForLoop(vec);

    vec.push_back(sampleClassInt[9]);
    vec.push_back(sampleClassInt[0]);
    vec.push_back(sampleClassInt[1]);
    printUsingConstRangeBasedForLoop(vec);
}

void testContainerOnSet()
{
    mystl::set<double> myset;

    myset.insert(50);
    myset.insert(45);
    myset.insert(40);
    myset.insert(47);
    myset.insert(46);
    myset.insert(55);
    myset.insert(47);
    myset.insert(56);
    myset.insert(51);
    myset.insert(48);
    myset.insert(46);
    myset.insert(47.5);
    myset.insert(46.5);
    myset.insert(45.5);
    myset.insert(54);

    std::cout << "\n upper_bound " << *myset.upper_bound(47);
    std::cout << "\n upper_bound " << *myset.upper_bound(46.5);
    std::cout << "\n upper_bound " << *myset.upper_bound(43);
    std::cout << "\n upper_bound " << *myset.upper_bound(48);
    std::cout << "\n upper_bound " << *myset.upper_bound(54);
    std::cout << "\n upper_bound " << *myset.upper_bound(52);
    std::cout << "\n upper_bound " << *myset.upper_bound(46.6);
    std::cout << "\n upper_bound " << *myset.upper_bound(20);
    std::cout << "\n upper_bound " << *myset.upper_bound(50);
    std::cout << "\n upper_bound " << myset.upper_bound(57);
    std::cout << "\n upper_bound " << *myset.upper_bound(47.5);
    std::cout << "\n upper_bound " << *myset.upper_bound(46);
}

} // namespace


void testContainer()
{
    testContainerOnVector();
    testContainerOnSet();
}

} // namespace src
