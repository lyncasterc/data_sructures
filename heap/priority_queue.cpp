#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue 
{
    private:
        vector<int> data;


    public:
        bool is_empty() const { return data.empty(); }

        void insert(int value)
        {
            data.push_back(value);
            int i = data.size() - 1;

            while (i > 0 && value > data[(i - 1) / 2])
            {
                data[i] = data[(i - 1) / 2];
                i = (i - 1) / 2;
            }
            data[i] = value;
        }

        int size() const { return data.size(); }

        int top() const { return data[0]; }

        void swap_keys(int i, int j)
        {
            int temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }

        void pop()
        {
            int i, j, length;
            length = data.size();
            data[0] = data.back();
            data.pop_back();
            i = 0;
            j = 2 * i + 1;

            while (j < length - 1)
            {
                if(data[j] < data[j + 1])
                { j++; }

                if (data[j] > data[i])
                {
                    swap_keys(i, j);
                    i = j;
                    j = 2 * i + 1;
                }
                else
                {  break; }
            }
        }
        
};

int main()
{
    PriorityQueue pq;
    pq.insert(10);
    pq.insert(20);
    pq.insert(30);
    pq.insert(40);
    pq.insert(50);
    cout << pq.size() << endl;

    cout << pq.top() << endl;

    pq.pop();

    cout << pq.top() << endl;
}