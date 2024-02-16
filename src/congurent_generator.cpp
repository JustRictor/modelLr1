#include "congurent_generator.hpp"

randGen::Congurent::Congurent(double seed,
                              uint16_t A, uint16_t C)
    : A_(A)
    , C_(C)
    , R_(seed)
{

}

double randGen::Congurent::rand()
{
    R_ = std::fmod(A_*R_+C_, M_);
    static double whole;
    R_ = std::modf(R_,&whole);
    return R_;
}

randGen::GeneratorType randGen::Congurent::getType()
{
    return GeneratorType::Congurent;
}
