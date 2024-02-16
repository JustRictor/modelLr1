#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <algorithm>

#include "metrics.hpp"
#include "myrandom.hpp"

void toFile(std::ofstream& stream, std::vector<double> const& arr);
void printMetrics(std::ostream& stream, randGen::Generator* gen);
std::string getMetrics(std::vector<double> const& arr);
std::vector<double> genArray(randGen::Generator* gen, size_t size);

int main()
{
    randGen::Congurent congurent;
    randGen::Fibonacci fibonacci;
    randGen::Mersenne  mersenne;

    printMetrics(std::cout,&congurent);
    printMetrics(std::cout,&fibonacci);
    printMetrics(std::cout,&mersenne);

    std::ofstream file("out.csv");
    file.precision(48);
    for(size_t i : {1'000,5'000,10'000})
        toFile( file, genArray(&congurent,i) );
    for(size_t i : {1'000,5'000,10'000})
        toFile( file, genArray(&fibonacci,i) );
    for(size_t i : {1'000,5'000,10'000})
        toFile( file, genArray(&mersenne,i) );
    return 0;
}


void toFile(std::ofstream& stream, std::vector<double> const& arr)
{
    std::for_each(arr.begin(), arr.end(),
                  [&stream](auto num){
        stream << num << ", ";
    });
    stream << std::endl;
}


void printMetrics(std::ostream& stream, randGen::Generator* gen)
{
    static const std::unordered_map<randGen::GeneratorType, std::string>
            genTypeToStr
    {
        { randGen::GeneratorType::Congurent , "congurent generator" },
        { randGen::GeneratorType::Fibonacci , "fibbonacci generator" },
        { randGen::GeneratorType::Mersenne  , "mersenne generator" }
    };
    stream << "\n\t\tFor " << genTypeToStr.at(gen->getType())
           << std::endl;
    for(size_t i : {1'000,5'000,10'000})
    {
        stream << "\tFor " << i << "\n"
               << getMetrics( genArray(gen,i) )
               << "\n" << std::endl;
    }
}


std::string getMetrics(std::vector<double> const& arr)
{
    std::string metrics{};
    metrics += std::string("Expectation: ")
            + std::to_string(metrics::expectation(arr)) + "\n";
    metrics += std::string("Varience:    ")
            + std::to_string(metrics::varience(arr)) + "\n";
    metrics += std::string("Deviation:   ")
            + std::to_string(metrics::deviation(arr));
    return metrics;
}



std::vector<double> genArray(randGen::Generator* gen, size_t size)
{
    std::vector<double> arr{}; arr.reserve(size);
    while(size--)
        arr.push_back(gen->rand());
    return arr;
}
