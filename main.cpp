//Homework 9

/*
 *  Filename:           main.cpp
 * 
 *  Purpose:            The purpose of this program is to find the maximum
 *                      volume of a cone using the radius_R input by the 
 *                      user. The radius R represents the radius of a circle 
 *                      after a section of a circle has been removed (arc
 *                      length represented by the variable arc_x). The
 *                      program will then determine the maximum value of the
 *                      volume (volume_vMAX), and the required arc length to
 *                      be removed (arc_x). The program will output the 
 *                      radius of the cut circle (radius_R), the length
 *                      of the arc to be removed, and the maximum volume.
 * 
 * 
 *  Author:             Zachary Charles Stewart
 *  Student ID:         105903414
 *  Date:               1/24/2017 17:13 PST
 */

#include<iostream>
#include<cstdlib>
#include<cmath>
#include<iomanip>

using namespace std;

//Named constant for pi and step size
//I love pecan pie
const double pecanPie = 3.141592654;
const double step_size = 0.001;

int main(int argc, char** argv) 
{
    //Declare variables
    double radius_R, radius_r, volume_v, volume_vMAX, height_h, arc_x;
    double circ_R, circ_r;
    
    //Prompt user for input and store to radius_R
    cout << "Please enter the radius of the circular waxed paper: " << endl;
    cin >> radius_R;
    cout << endl;
    
     //Initialize variables to initial conditions of cone.
    arc_x = 0;
    radius_r = 0;
    height_h = radius_R;   
    volume_vMAX = 0;
    
    //Test volumes for all possibilities to find max. This starts when
    //the radius_r of the cone is zero, and ends when the height_h is zero.
    //When the radius_r is zero, the height_h is the same as the radius_R.
    //The radius_r is then incremented by the designated step size, and 
    //the volume_v is tested against the max volume_vMAX. The arc_x is 
    //then determined by subtracting circ_c from circ_C 
    //(arc_x = circ_C - circ_c). 
    //The program will then output the desired arc_x to be removed with the 
    //given radius_R. It will also output the max volume_vMAX.
    
    while(radius_r < radius_R)
    {
        //Determine current volume
        volume_v = (1.0 / 3.0) * pecanPie * pow(radius_r, 2) * height_h;
        //Compare to volume_vMAX
        if(volume_v > volume_vMAX)
        {
            //If true, volume_vMAX is now volume_v
            volume_vMAX = volume_v;
            circ_R = 2 * pecanPie * radius_R;
            circ_r = 2 * pecanPie * radius_r;
            //Determine length of x removed (arc_x)
            arc_x = circ_R - circ_r;            
        }
        //Increment radius_R by step_size
        radius_r = radius_r + step_size;
        //Determine new height_h using right triangle properties of 
        //trigonometry.
        height_h = sqrt((pow(radius_R, 2)) - (pow(radius_r, 2)));
    }
    
    //Output data to the user
    cout << fixed << showpoint << setprecision(2) << "Using circular "
            "waxed paper with a radius of " << radius_R << " in," << endl;
    cout << "the length of the removed sector should be " << arc_x << " in."
         << endl;
    cout << "The maximum volume will then be " << volume_vMAX << " in^3."
         << endl;

    //Terminate program upon successful completion
    exit(EXIT_SUCCESS);
}

