#include "SimpleHarmonicOscillator.hxx"
#include <iostream>

int main(void)
{
    SpringMass SHO(0.5,1.5, 0.3);
    std::cout << SHO.getEquilibriumPosition() << std::endl;
    SHO.displace(0.2);
}