#ifndef SIMPLEHARMONICOSCILLATOR_HXX
#define SIMPLEHARMONICOSCILLATOR_HXX

#include <cmath>
#include <fstream>

const double g = 9.81;

// SpringMass Class declaration, class calculates the displacement of a mass
// of magnitude 'm' on a spring with a spring constant 'k'. Results of 
// oscillatory motion for a given time period are then written to an output file
class SpringMass
{
    private:
        double _mass = 0;                   // Mass of weight 'm'
        double _damp_coef = 0;              // Coefficient of Damping 'b'
        double _spg_const = 0;              // Spring constant 'k'
        double _initial_dis = 0;            // Initial displacement
        double _ang_vel = 0;                // Angular velocity 'omega'
        double _get_displacement(double);   // Get the displacement at time 't'
        void _record_data(double, double);  // Write data point to output file
    public:
        // Class arguments and structure
        SpringMass(double mass, double spg_const, double damp_coef=0);

        // Start simulation with weight displaced by a given value, write for
        // time period of 10 seconds by default unless specified
        void displace(double amplitude, double time=10);
        
        // Get the value of the angular velocity
        double getAngularVelocity();
};

#endif