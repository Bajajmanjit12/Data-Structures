#include<iostream>
#include<iomanip>
using namespace std;

class OBST{
    int n;
    string key[10];
    float p[10],q[11];
    float w[11][11],c[11][11];
    int r[11][11];

    public:
    void accept();
    void calculate();
    void display();
     void showTree(int i, int j, string parent, string direction);

};

void OBST ::accept(){
    cout<<"\nEnter the number of keys:";
    cin >>n;

    cout<<"\nEnter the values of keys:";
    for(int i=0;i<n;i++)
    {
        cin>>key[i];
    }

    cout<<"\nEnter successful search probabilities(p):";
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    cout<<"\nEnter unsuccessful search probabilities(q):";
    for(int i=0;i<=n;i++)
    {
        cin>>q[i];
    }
}

void OBST ::calculate()
{
    for(int i=0;i<=n;i++)
    {
        w[i][i]=q[i];
        c[i][i]=0;
        r[i][i]=0;
    }

    for(int len =1;len <=n;len++)
    {
        for(int i=0;i<= n-len;i++)
        {
            int j=i+len;
            
            w[i][j]=p[j-1] + q[j]+w[i][j-1];
            
            float mincost=999;
            int root = 0;
            
            for(int k=i+1;k<=j;k++){
                float cost = c[i][k-1]+c[k][j];
                
                if(cost < mincost){
                    mincost = cost;
                    root = k;
                }
            }
            
            c[i][j] = w[i][j] +mincost;
            r[i][j] = root;
        }
    }

}

void OBST::display() {
    cout << fixed << setprecision(2);

    cout << "\nMatrix W (Weights):\n";
    for (int gap = 0; gap <= n; gap++) {
        for (int i = 0; i <= n - gap; i++) {
            int j = i + gap;
            cout << "W[" << i << "][" << j << "] = " << w[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nMatrix C (Costs):\n";
    for (int gap = 0; gap <= n; gap++) {
        for (int i = 0; i <= n - gap; i++) {
            int j = i + gap;
            cout << "C[" << i << "][" << j << "] = " << c[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nMatrix R (Roots):\n";
    for (int gap = 0; gap <= n; gap++) {
        for (int i = 0; i <= n - gap; i++) {
            int j = i + gap;
            cout << "R[" << i << "][" << j << "] = " << r[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nMinimum cost of Optimal BST = " << c[0][n] << endl;

    showTree(0,n,"none","root");
}

void OBST::showTree(int i, int j, string parent, string direction) {
    int rootIndex = r[i][j];
    if (rootIndex == 0 || rootIndex == -1)
        return;

    string currKey = key[rootIndex - 1];
    cout << currKey << " is the " << direction << " of " << parent << endl;

    showTree(i, rootIndex - 1, currKey, "Left");
    showTree(rootIndex, j, currKey, "Right");
}


int main()
{
    OBST t;
    t.accept();
    t.calculate();
    t.display();
  
    return 0;
}