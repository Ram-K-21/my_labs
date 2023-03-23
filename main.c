#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct el_sum{
    double amount;
    int count_el;
};

int Sum(FILE* fin, struct el_sum* d){
    double sum = 0, el = 0;
    int count_el = 0, count_str = 0;
    char c;
    while(!feof(fin)){
        fscanf(fin, "%lf%c", &el, &c);
        sum += el;
        count_el++;
        if(c == '\n'){
            d[count_str].amount = sum;
            d[count_str].count_el = count_el;
            count_str++;
            sum = 0;
            count_el = 0;
        }
    }
    d[count_str].amount = sum;
    d[count_str].count_el = count_el;
    return count_str;
}

int max(struct el_sum* d, int n){
    int mx = 0;
    for(int line = 0; line < n; line++){
        mx = fmax(mx, d[line].count_el);
    }
    return mx;
}

double** sort_mas(double** dictionary, int n, int max){
    for(int i = 1; i <= n; i++){
        for(int k = n; k >= i; k--){
            if(dictionary[k - 1][0] > dictionary[k][0]){
                for(int q = 0; q <= max + 1; q++){
                    double temp = dictionary[k - 1][q];
                    dictionary[k - 1][q] = dictionary[k][q];
                    dictionary[k][q] = temp;
                }
            }
        }
    }
    return dictionary;
}

double** writting_to_mas(FILE* fin, struct el_sum* d, int n, int mx){
    double** dictionary = (double**)malloc(n * sizeof(double*));
    for(int line = 0; line <= n; line++){
        dictionary[line] = (double*)malloc(mx * sizeof(double));
    }
    for(int line = 0; line <= n; line++){
        dictionary[line][0] = d[line].amount;
        dictionary[line][1] = d[line].count_el;
    }
    double el = 0;
    int count_el = 2, line = 0;
    char c;
    while(!feof(fin)){
        fscanf(fin, "%lf%c", &el, &c);
        dictionary[line][count_el] = el;
        count_el++;
        if(c == '\n'){
            line++;
            count_el = 2;
        }
    }
    return dictionary;
}

void writting_to_file(double** dictionary, int n){
    FILE* fout = fopen("file_out.txt", "w");
    for(int line = 0; line <= n; line++){
        int len_str = dictionary[line][1] + 1;
        for(int i = 2; i <= len_str; i++){
            if(i == len_str){
                fprintf(fout, "%lf\n", dictionary[line][i]);
            }
            else{
                fprintf(fout, "%lf ", dictionary[line][i]);
            }
        }
    }
    fclose(fout);
}

int main()
{
    FILE* fin;
    fin = fopen("file_in.txt", "r");
    struct el_sum d[100];
    int n = Sum(fin, d);
    int mx = max(d, n);
    fseek(fin, 0, SEEK_SET);
    double** dictionary = writting_to_mas(fin, d, n, mx);
    double ** sort_dictionary = sort_mas(dictionary, n, mx);
    fclose(fin);
    FILE* fout;
    writting_to_file(sort_dictionary, n);
    return 0;
}
