using namespace std;

class Upwind
{
    private:
        int pts_t, pts_x;
        double time, space_x, delta_t, delta_x, a, sigma;
        double *u, *tn, *xi;        
    
    public:
        Upwind(); // Default contructor
        Upwind(double, double, int, int, double, double *);
    
        void Iterate();
        double * GetU();
        void WriteSol(int, string);
        void WriteUini(double *, string);
        void WriteAnimSol(int);

        ~Upwind();
};
