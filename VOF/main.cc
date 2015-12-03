#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include <boost/tuple/tuple.hpp>
#include "gnuplot-iostream/gnuplot-iostream.h"
#include "vof.cxx"
#include "upwind.cxx"

double gaussian(double x)
{
    x -= 2;
    return exp(-x*x);
}

double slot(double x)
{
        if(x>= 1 && x<=2)
            return 1;
        else
            return 0;
}

double sqr(double x)
	{return x*x;}

using namespace std;

int main()
{
    time_t tbeginGlob, tendGlob, tbegin, tend;
    
    double val_t=5., val_space_x=10., val_space_y=5., a=1.;
    int res_t=50, res_x=100, res_y=50;
    double *u0;
    double *u;
    u0 = new double [res_x];
    u = new double [res_x];

    // Start global timer
    tbeginGlob = time(NULL);

    // INIT OF u0
    for(int i=0; i < res_x; i++)
    {
        double x = i * (val_space_x/res_x);
        u0[i] = 2*slot(x);
    }
    
    // INIT OF u0
    for(int i=0; i < res_x; i++)
    {
        double x = i * (val_space_x/res_x);
        u0[i] = gaussian(x);
    }
    
/*    cout << endl;
    cout << "La condition de CFL impose un nombre de points en temps superieur a " << time/(a*(space_x/res_x)) << endl;
    cout << "Choix du nbr de pts en temps : ";
    cin >> res_t;
    cout << endl;*/

    Vof Vof1(val_space_y, val_space_x, res_t, res_x); // Constrution of VOF
    Upwind SchemeUpwind(val_t, val_space_x, res_y, res_x, a, u0); // Constrution of the scheme
    
    SchemeUpwind.WriteUini(u0, "Uini.dat");
    
    // Start timer
    tbegin = time(NULL);

    // PRINCIPAL TIME LOOP
    for (int n=0; n < res_t; n++)
    {
        SchemeUpwind.Iterate(); 
        SchemeUpwind.WriteSol(n, "SolUpwind.dat");
        SchemeUpwind.WriteAnimSol(n);
    }
    
     // End timer
    tend = time(NULL);
    u = SchemeUpwind.GetU(); 

    // Compute execution time

    cout << "Execution time : " << difftime(tend, tbegin) << "s" << endl;

    Gnuplot gp;
    //gp << "set palette rgbformulae 33,13,10\n";
    //gp << "splot 'SolUpwind.dat' with pm3d\n";

    
    Vof1.DrawArray(u);
    Vof1.AddDepth(1);
    //Vof1.DrawArray(u);
    Vof1.WriteTable("TableVOF.dat");

	gp << "load \"vofmap.gnu\"\n";

    // End global timer
    tendGlob = time(NULL);
    cout << "Global execution time : " << difftime(tendGlob, tbeginGlob) << "s" << endl;

    return 0;
}


