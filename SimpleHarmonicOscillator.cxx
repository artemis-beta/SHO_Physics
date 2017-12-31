//======================================================================//
//                      Simple Harmonic Oscillator                      //
//  Classes for simulating a mass on a spring with the option of adding //
//  a value for coefficient of damping.                                 //
//                                                                      //
//  author   :   Kristian Zarebski                                      //
//  date     :   last modified  2017-12-31                              //
//                                                                      //
//======================================================================//

#include "SimpleHarmonicOscillator.hxx"
#include <cmath>
#include <iostream>


// Initialise the components of the SpringMass class and create output
SpringMass::SpringMass(double mass, double spg_const, double damp_coef)
{
    _spg_const = spg_const;
    _mass = mass;
    _damp_coef = damp_coef;
    _ang_vel = pow(_spg_const/_mass, 0.5);
    std::ofstream out_file("SHO_m_"+std::to_string(_mass)+"_k_"\
    +std::to_string(_spg_const)+"_b_"+std::to_string(_damp_coef)+".txt");
    out_file.close();
}

// Insert Data Point Into Output File for amplitude at given time
void SpringMass::_record_data(double time, double amplitude)
{
    std::ofstream out_file("SHO_m_"+std::to_string(_mass)+"_k_"\
    +std::to_string(_spg_const)+"_b_"+std::to_string(_damp_coef)+".txt",
    std::ios::out | std::ios::app);
    
    out_file << time << "\t" << amplitude << std::endl;
    out_file.close();
}

// Calculate the amplitude of displacement at a given time
double SpringMass::_get_displacement(double time)
{
    double _dis = exp(-1*(_damp_coef*time)/(2*_mass))*_initial_dis;
    dis *= cos(_ang_vel*time);

    return _dis;
}

// Set initial displacement (and release the mass!)
void SpringMass::displace(double amplitude, double time)
{
    _initial_dis = amplitude;

    for(int i{0}; i<=10*time; ++i)
    {
        _record_data(i/10., _get_displacement(i/10.));
    }
}

// Return the angular velocity omega = sqrt(k/m)
double SpringMass::getAngularVelocity()
{
    return _ang_vel;
}