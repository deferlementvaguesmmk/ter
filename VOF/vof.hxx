using namespace std;

class Vof
{
    private:
        int nbrRow, nbrCol;
        double height, width, deltaH, deltaW;
        double **Table;
        vector<double> h;
        
    public:
        Vof(); // Default constructor 
        Vof(double, double, int, int); // Constructor with dimensions and sizes

        void AllocTable();  // ALLOCATE Table with nbrRow and nbrCol 
        void ClearTable(); // CLEAR Table 
        
        void Update(); // Update the F function
        void DispTable(); // DISPLAY Table 
        void WriteTable(string);

        void DrawFunction(); // Draw a function
        void DrawArray(double *array); // Draw an array
        void AddDepth(double);
    
/*        vector<vector<double>> Get_phi(int, int);*/
        double Get_h(int);
        void SetH(int, double);
};