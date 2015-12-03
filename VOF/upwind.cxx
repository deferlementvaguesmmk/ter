#include "upwind.hxx"

Upwind::Upwind() // Default contructor
{
    
}

Upwind::Upwind(double timeGivn, double space_xGivn, int pts_tGivn, int pts_xGivn, double aGivn, double *u0)
{
    time = timeGivn;
    space_x = space_xGivn;
    pts_t = pts_tGivn;
    pts_x = pts_xGivn;
    a = aGivn;
        
    delta_t = time/pts_t;
    delta_x = space_x/pts_x;
    sigma = delta_t/delta_x;
    int i;
    
    // DYNAMIC ALLOCATATIONS
    u = new double [pts_x];
    tn = new double [pts_t];
    xi = new double [pts_x];
        
    for(i=0; i < pts_x; i++) // SET OF INIT CONDITION
        u[i] = u0[i];

    for (i=0; i < pts_t; i++) // TIME DISCRETIZATION
         tn[i] = i * delta_t;

    for (i=0; i < pts_x; i++) // SPACE DISCRETIZATION
         xi[i] = i * delta_x;
}

void Upwind::Iterate()
{
    double u_new[pts_x];
    for (int i=1; i < pts_x; i++) // SPACE LOOP
        u_new[i] = u[i] - a * sigma * (u[i]-u[i-1]);

    for(int i=0; i < pts_x; i++)
        u[i] = u_new[i];
}

double * Upwind::GetU()
{
    return u;
}

void Upwind::WriteSol(int n, string name)
{
    ofstream file;
    if(n==0)
        file.open(name);
    else
        file.open(name, ofstream::app);
    for (int i = 0; i < pts_x; i++)
    {
        file << tn[n] << ' ' << xi[i] << ' ' << u[i] << '\n';
    }
    file << '\n';
    file.close();
}

void Upwind::WriteUini(double *u0, string name)
{
    ofstream file;
    file.open(name);
    for (int i = 0; i < pts_x; i++)
    {
        file << xi[i] << ' ' << u0[i] << '\n';
    }
    file << '\n';
    file.close();
}

void Upwind::WriteAnimSol(int n)
{
        ofstream file_out("anim//Un" + to_string(n) + ".dat");
        for (int i = 0; i < pts_x; i++)
            file_out << xi[i] << ' ' << u[i] << '\n';
        
        file_out << '\n';
        file_out.close();
}

Upwind::~Upwind()
{
    delete u;
    delete tn;
    delete xi; 
}