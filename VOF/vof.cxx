#include "vof.hxx"

double gaussian(double);
double slot(double);
double sqr(double x);

Vof::Vof() // Default contructor  
{
    
}

Vof::Vof(double heightGivn, double widthGivn, int nbrRowGivn, int nbrColGivn) // Constructor with dimensions and size
{
    height = heightGivn;
    width = widthGivn;
    nbrRow = nbrRowGivn;
    nbrCol = nbrColGivn;
    deltaH = height/nbrRow;
    deltaW = width/nbrCol;
    
    this->Vof::AllocTable();
    this->Vof::ClearTable();
}

void Vof::AllocTable() // DYNAMIC ALLOCATATION OF Table
{
    Table = new double* [nbrRow];
    for (int i=0; i < nbrRow; i++)
        Table[i] = new double[nbrCol];
}

void Vof::ClearTable() // INITIALISATION OF Table (fill with 0)
{ 
    for (int i=0; i < nbrRow; i++)
        for (int j=0; j < nbrCol; j++)
            Table[i][j] = 0;
}

void Vof::Update() // Update the F function
{ 
    
}

void Vof::DrawFunction() // Draw a function
{ 
    for (int i=0; i < nbrRow; i++)
        for (int j=0; j < nbrCol; j++)
        {
            if(i*deltaH > slot(j*deltaW))
                Table[i][j] = 0;
            else
                Table[i][j] = 1;
        }
}

void Vof::DrawArray(double *array) // Draw an array
{ 
    for (int i=0; i < nbrRow; i++)
        for (int j=0; j < nbrCol; j++)
        {
            if(i*deltaH > array[j])
                Table[i][j] = 0;
            else
                Table[i][j] = 1;
        }
}

void Vof::AddDepth(double depth) // Fill bottom cells with fluid
{
    if(depth > 0 && depth < height)
    {
        double res = fmod(depth,deltaH);
        int quo = (depth-res)/deltaH;    

        // Add the depth over the existing table
        for (int i=0; i <= quo+1; i++) 
        {
                for (int j=0; j < nbrCol; j++)
                    if (i!=quo+1)
                        Table[i][j] += 1;
                    else
                        Table[quo+1][j] += res/deltaH;
        }    

        // Push up the extra (>1) to the upper cell
        for (int i=0; i < nbrRow-1; i++) 
        {
            for (int j=0; j < nbrCol; j++)
            {
                if (Table[i][j] > 1)
                {
                    Table[i+1][j] += Table[i][j] - 1;
                    Table[i][j] = 1;
                }
            }
        }
    }
    else
    {
        cout << "Value sent to AddDepth is incorrect." << endl;
    }
}

void Vof::DispTable() // DISPLAY Table 
{
  for (int i=0; i < nbrRow; i++)
  {
    for (int j=0; j < nbrCol; j++)
        cout << Table[i][j] << " ";
    cout << endl;
  }
}

void Vof::WriteTable(string name)
{
    ofstream file_out(name);
    for (int i = 0; i < nbrRow; i++)
    {
        for (int j = 0; j < nbrCol; j++)
            file_out << Table[i][j] << ' ';
        
        file_out << '\n';
    }

    file_out.close();
}

/*vector<vector<double>> Vof::Get_phi(int i, int j)
{
    return row[i][j];
}*/

double Vof::Get_h(int xi) // Return the value of H for the xi column
{
    return h[xi];
}

void Vof::SetH(int xi, double val)
{
    h[xi] = val;
}
        
