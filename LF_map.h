#include<string>
#include<string.h>
using namespace std;
class LF_map
{
private:
    int *A;
    int *T;
    int *C;
    int *G;
    int cap;
    int less_A;
    int less_T;
    int less_C;
    int less_G;
public:
    LF_map(int str_len, string s);
    ~LF_map();
    int get_value(char mode, int index);
    void init_table(char *bwt);
};