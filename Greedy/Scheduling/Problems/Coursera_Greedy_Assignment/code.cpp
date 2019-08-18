// Greedy

#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>
#include <functional>

using namespace std;

char inputFile[] = "input.txt";

vector<tuple<int,int>> jobs;
function<bool(tuple<int,int>,tuple<int,int>)> greedy1 = [](auto a, auto b)->bool{
    if (get<0>(a)-get<1>(a) == (get<0>(b)-get<1>(b))) {
        return get<0>(a) > get<0>(b);
    } else {
        return (get<0>(a)-get<1>(a)) > (get<0>(b)-get<1>(b));
    }
};
function<bool(tuple<int,int>,tuple<int,int>)> greedy2 = [](auto a, auto b)->bool{
    return ((float)get<0>(a)/get<1>(a)) > ((float)get<0>(b)/get<1>(b));
};

int main(){
    FILE* pfile = fopen(inputFile, "r");
    int size;
    fscanf(pfile, "%d\n", &size);
    while(size--) {
        int weight, length;
        fscanf(pfile, "%d %d\n", &weight, &length);
        jobs.push_back(make_tuple(weight, length));
    }
    fclose(pfile);
    
    sort(jobs.begin(), jobs.end(), greedy1);
    
    long long int result = 0;
    int length = 0;
    for(auto job : jobs) {
        length += get<1>(job);
        result += get<0>(job)*length;
    }
    printf("%lld\n", result);
    
    return 0;
}
