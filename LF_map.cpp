#include "LF_map.h"

LF_map::LF_map(int str_len, string s):cap(str_len){
    A = new int [str_len];
    T = new int [str_len];
    C = new int [str_len];
    G = new int [str_len];
    memset(A,0,str_len);
    memset(T,0,str_len);
    memset(C,0,str_len);
    memset(G,0,str_len);

    less_A = 0;
    less_C = 0;
    less_G = 0;
    less_T = 0;
    for(unsigned int i = 0; i<s.size();i++){
        if(s[i] == 'A'){
            less_C++;
            less_T++;
            less_G++;
        }
        else if(s[i] == 'C'){
            less_T++;
            less_G++;
        }
        else if(s[i] == 'G'){
            less_T++;
        } 
    }
}

LF_map::~LF_map(){
    delete[] A;
    delete[] T;
    delete[] C;
    delete[] G;
}

int LF_map::get_value(char mode, int index){
    if(mode == 'A') return A[index];
    else if(mode == 'T') return T[index];
    else if(mode == 'C') return C[index];
    else if(mode == 'G') return G[index];
    else return 0;
}

void LF_map::init_table(char *bwt){
    if(bwt[0] == 'A') A[0]++;
    else if(bwt[0] == 'T') T[0]++;
    else if(bwt[0] == 'C') C[0]++;
    else if(bwt[0] == 'G') G[0]++;

    for(int i = 1; i<cap; i++){
        if(bwt[i] == 'A'){
            A[i] = A[i-1] + 1;
            T[i] = T[i-1];
            C[i] = C[i-1];
            G[i] = G[i-1];
        }
        else if(bwt[i] == 'T'){
            A[i] = A[i-1];
            T[i] = T[i-1] + 1;
            C[i] = C[i-1];
            G[i] = G[i-1];
        }
        else if(bwt[i] == 'C'){
            A[i] = A[i-1];
            T[i] = T[i-1];
            C[i] = C[i-1] + 1;
            G[i] = G[i-1];
        }
        else if(bwt[i] == 'G'){
            A[i] = A[i-1];
            T[i] = T[i-1];
            C[i] = C[i-1];
            G[i] = G[i-1] + 1;
        }
        else{
            A[i] = A[i-1];
            T[i] = T[i-1];
            C[i] = C[i-1];
            G[i] = G[i-1];
        }
    }
}

int LF_map::get_less(char mode){
    if(mode <= 'A') return less_A;
    else if('A' < mode and mode <= 'C') return less_C;
    else if('C' < mode and mode <= 'G') return less_G;
    else if('G' < mode and mode <= 'T') return less_T;
    else return 0;
}