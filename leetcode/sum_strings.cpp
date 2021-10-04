#include <iostream>
#include <string>

//only for positive numbers
std::string sum_strings(const std::string& a, const std::string& b)
{
    if(a.size() == 0 && b.size() == 0)
    {
        return "0";
    }

    std::string result, str_sum;
    int a_index = a.size() - 1;
    int b_index = b.size() - 1;
    int largest_index = std::max(a_index, b_index);
    int a_num, b_num, sum, carry = 0;

    while(largest_index >= 0)
    {
        a_num = (a_index >= 0) ? a[a_index] - '0' : 0;
        b_num = (b_index >= 0) ? b[b_index] - '0' : 0;
        sum = a_num + b_num + carry;
        carry = 0;
        str_sum = std::to_string(sum);

        if(str_sum.size() == 2 && largest_index > 0)
        {
            result.insert(0, std::string(1, str_sum[1]));
            carry = str_sum[0] - '0';
        }
        else
        {
            result.insert(0, str_sum);
        }

        a_index--;
        b_index--;
        largest_index--;  
    }

    return result;
}


int main()
{
    std::string num = sum_strings("1", "10");
    std::cout << num;

}