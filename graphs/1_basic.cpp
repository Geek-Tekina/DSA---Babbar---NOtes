#include <iostream>
#include <vector>
using namespace std;

/*
there are two ways for initialising graphs
with number of nodes given @compile time and @run time

1. for compile time, an array of vectors can bse used    i.e vector...[]
2. but for run time, we use a vector of pointers, which points to a memory block for now, 
    but in constructor we specify the number of pointers there will be i.e. adjList = new vector<int>[size];
*/

class GraphFixed {
    int matrix[5][5];
    vector<int> list[5];
    public:
        GraphFixed(){
            for(int i=0 ; i<5 ; ++i)
                for(int j=0 ; j<5 ; ++j)
                    matrix[i][j] = 0;
        }
        void addEdge(int source, int dest){
            matrix[source][dest] = 1;
            matrix[dest][source] = 1;
            list[source].push_back(dest);
            list[dest].push_back(source);
        }
        void print(){
            for(int i=0 ;  i < 5 ; ++i){
                cout << "\nfor node " << i << ", ";
                for(auto conNodes : list[i])
                    cout << conNodes << " ";
            }
            cout << "\n-------\n";
            for(int i=0 ;  i < 5 ; ++i){
                for(int j=0 ; j<5 ; ++j)
                    cout << matrix[i][j] << " ";
                cout << "\n";
            }
            cout << "\n-------\n";
        }
};

class GraphDyn {
    int n;
    int **mat;
    // list is pointing to fist vector, later we will specify array for this list.
    vector<int> *list;   
    public:
        GraphDyn(int nodes){
            mat = new int*[nodes];
            for(int i=0 ; i<nodes ; ++i){
                mat[i] = new int[nodes];
                for(int j=0 ; j<nodes; ++j)
                    mat[i][j] = 0;
            }
            n = nodes;
            list = new vector<int>[nodes];

        }
        void addEdge(int source, int dest){
            (list + source)->push_back(dest);
            (list + dest)->push_back(source); 
        }
        void print(){
            for(int i=0 ;  i < n ; ++i){
                cout << "\nfor node " << i << ", ";
                for(auto conNodes : *(list+i))
                    cout << conNodes << " ";
            }
            cout << "\n-------\n";
            for(int i=0 ; i<n ; ++i){
                for(int j=0 ; j<n ; ++j)
                    cout << mat[i][j] << " ";
                cout << "\n";
            }
        }
};

int main(){
    GraphFixed g1 = GraphFixed();
    g1.addEdge(1,2);
    g1.addEdge(2,4);
    g1.addEdge(0,3);
    g1.addEdge(0,1);
    // g1.print();

    GraphDyn g2 = GraphDyn(5);
    g2.addEdge(1,2);
    g2.addEdge(2,4);
    g2.addEdge(0,3);
    g2.addEdge(0,1);
    g2.print();
    return 0;
}