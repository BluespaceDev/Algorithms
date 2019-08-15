// 과제4 2-SUM

#include <cstdio>
#include <unordered_map>

using namespace std;

char inputFile[] = "/Users/hongseobshin/Desktop/Hugo/content/Algorithms/Data_Structure/Hash/Problems/CourseraAssignment3/input.txt";

unordered_map<long long int, bool> myhash;

int main(){
    FILE* pfile = fopen(inputFile, "r");
    while(!feof(pfile)){
        long long int value;
        fscanf(pfile, "%lld\n", &value);
        myhash[value] = true;
    }
    fclose(pfile);
    
    int finded_count = 0;
    for(int t = -10000; t <= 10000; ++t) {
        printf("t : %d\n", t);
        for(auto v : myhash) {
            long long int x = v.first;
            long long int y = t - x;
            if (auto iter = myhash.find(y); iter != myhash.end()) {
                //printf("%d + %d = %d\n", x, y, t);
                finded_count++;
                break;
            }
        }
    }
    
    printf("%d\n", finded_count);
    
    return 0;
}