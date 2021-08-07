#include <iostream>
#include <array>
#include <queue>
#include <list>

using std:: cout;
using std:: endl;
using std:: queue;

void bfs(int start_vtx, int adj_matrix[][7], int num_of_vtx)
{
    queue<int>q;
    int visited_arr[7] = {0};

    q.emplace(start_vtx);
    visited_arr[start_vtx] = 1;
    cout << start_vtx << endl;

    while(!q.empty())
    {
        int cur_vtx = q.front();
        q.pop();

        for (int con_vtx = 0; con_vtx < num_of_vtx; con_vtx++)
        {   
            // if the current vertex is connected to other vertices
            
            // which have not been visited
            if(adj_matrix[cur_vtx][con_vtx] == 1 && visited_arr[con_vtx] == 0)
            {
                cout << con_vtx << endl;
                q.emplace(con_vtx);
                visited_arr[con_vtx] = 1;
            }
        }
    }
}


int main()
{
    int adj_matrix[7][7] = { {0,1,1,1,0,0,0},
                            {1,0,1,0,0,0,0}, 
                            {1,1,0,1,1,0,0},
                            {1,0,1,0,1,0,0},
                            {0,0,1,1,0,1,1}, 
                            {0,0,0,0,1,0,0},
                            {0,0,0,0,1,0,0} };


    bfs(0, adj_matrix, 7); // 0 1 2 3 4 5 6 
}
