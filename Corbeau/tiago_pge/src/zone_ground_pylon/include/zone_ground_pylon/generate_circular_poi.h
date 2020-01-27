#include <ros/ros.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

namespace zone_ground_pylon
{
    class Generate_circular_poi
    {
    public:
        std::vector <std::vector<double> > generate_circle(int numOfPoints, double radius, 
            double posOriX, double posOriY, double posOriZ  );
        std::array<double,4> get_pt_proche(std::vector <std::vector<double> > cercle, 
            std::array<double,3> pointProche );
        std::vector <std::vector<double> > bestChemin(std::vector <std::vector<double> > cercle,
            std::array<double,4> pointEntree, 
            std::array<double,4> pointSortie);
        std::vector <std::vector<double> > generate_traj_2pt_from_circle(
            std::vector <std::vector<double> > cercle, std::array<double,3> pointOrigine,
            std::array<double,3> pointGoal);  
    };
}
