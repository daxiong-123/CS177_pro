#include<iostream>
#include<string.h>
#include<algorithm>
#include<string>
#include"LF_map.h"

class bwt_item
{
private:
    string str;
    int index;
public:
    string get_str();
    int get_idx();
    bool operator<(bwt_item& item);
    bool operator>(bwt_item& item);
    bool operator==(bwt_item& item);
    void set_value(const string _str, const int _index);
};

void bwt_transform(int *suffix_array, char *bwt, const string &ref_str);
void reverse_bwt(char *bwt, string *s, int str_len, LF_map* map);
