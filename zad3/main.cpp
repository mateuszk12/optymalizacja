#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

std::string multiply (std::string x, std::string y) {

    int x_int = stoi(x);
    int y_int = stoi(y);
    return std::to_string(x_int * y_int);;
}
void addZeros(std::string* num, int n,bool atbegin=false) {
        for(int i = 0 ; i < n; i++)
        {
            if (atbegin)
            {
                *num = "0"+*num;
            } else
            {
                *num += "0";
            }
        }

}
std::string nWithZeros(std::string* num, int n,bool atbegin=false)
{
    std::string res = *num;
    addZeros(&res,n,atbegin);
    return res;
}
std::string add(std::string str1, std::string str2) {
    if(str1.size() > str2.size()) {
        addZeros(&str2,str1.size()-str2.size(),1);
    }
    int n2 = str2.size();
    std::string result;
    int over = 0;
    int one = 0;
    int num;
    for (int i = n2-1; i>=0;i--)
    {
        num = std::atoi(str1.substr(i,1).c_str())+std::atoi(str2.substr(i,1).c_str());
        one = num%10;
        result += std::to_string(one+over);
        over = num/10;
    }
    std::reverse(result.begin(), result.end());
    return result;
}
std::string subtract(const std::string& num1, const std::string& num2) {
    int n1 = num1.size();
    int n2 = num2.size();
    if (n1 < n2 || (n1 == n2 && num1 < num2)) {
        std::cerr << "Error: The result of subtraction would be negative: " <<num1<<" "<<num2<<" "<< std::endl;
        return "0";
    }
    std::string result;
    int borrow = 0;
    for (int i = 0; i < n1; ++i) {
        int digit1 = num1[n1 - 1 - i] - '0';
        int digit2 = (i < n2) ? num2[n2 - 1 - i] - '0' : 0;
        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.insert(result.begin(), diff + '0');
    }
    size_t start = result.find_first_not_of('0');
    return (start != std::string::npos) ? result.substr(start) : "0";
}

std::string karatsuba (std::string x, std::string y) {

    int xlen = x.size();
    int ylen = y.size();
    if (xlen <= 1 || ylen<=1)
    {
        return multiply(x,y);
    }
    int size = std::max(xlen,ylen);
    std::cout<<"size: "<<size<<"\n";
    std::string h1 = x.substr(0, size/2);
    std::string l1 = x.substr(size/2,size);
    std::string h2 = y.substr(0, size/2);
    std::string l2 = y.substr(size/2,size);

    std::string z0 = karatsuba(h1,l1);
    std::string z1 = karatsuba(l1,l2);
    std::string z2 = subtract(karatsuba(add(l1,h1), add(l2,h2)),add(z1,z0));

    std::string substracted = (subtract(subtract(z1,z2),z0));
    std::string z2o = nWithZeros(&z2,size);
    std::string so = nWithZeros(&substracted,size/2);

    return add(add(z2o,so),z0);
}



int main () {

    std::string x;
    std::string y;
    getline(std::cin, x);
    getline(std::cin, y);
    std::cout << subtract(x,y) << "\n";
    std::cout << karatsuba(x,y) << "\n";
}