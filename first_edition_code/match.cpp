#include "match.h"

void exact_match(const string origin, char *bwt, const string s, LF_map* map, int *sa){
    char c = s.back();
    int sp = map->get_less(c)+1;
    int ep = map->get_less(c+1);
    int match_length = s.size();
    int match_time = 0;

    for(;sp<=ep; sp++){
        bool match = false;
        int i = match_length - 2;
        int index = sp;

        while(bwt[index] == s[i]){
            index = map->get_less(bwt[index]) + map->get_value(bwt[index],index);
            i--;
            if(i < 0){
                match = true;
                match_time++;
                break;
            }
        }
        if(match){
            printf("Find Match %d :\n", match_time);
            cout << origin << endl;
            for(int i =0; i < sa[index]; i++) printf(" ");
            cout << s << endl;
        }
    }
 
}