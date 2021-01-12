#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {
    
    //float ;
    int nn = (n - 1), aa, bb, cc;
    for(int i = 0; i < n; ++i){
        for(int j =0; j < nn; ++j){
            if((sqrt(( ((tr[j].a + tr[j].b + tr[j].c)/2.0) ) * ( (((tr[j].a + tr[j].b + tr[j].c)/2.0)) - tr[j].a) * ( (((tr[j].a + tr[j].b + tr[j].c)/2.0)) - tr[j].b) * ( (((tr[j].a + tr[j].b + tr[j].c)/2.0)) - tr[j].c) )) > (sqrt(( ((tr[j + 1].a + tr[j + 1].b + tr[j + 1].c)/2.0) ) * ( (((tr[j + 1].a + tr[j + 1].b + tr[j + 1].c)/2.0)) - tr[j + 1].a) * ( (((tr[j + 1].a + tr[j + 1].b + tr[j + 1].c)/2.0)) - tr[j + 1].b) * ( (((tr[j + 1].a + tr[j + 1].b + tr[j + 1].c)/2.0)) - tr[j + 1].c) ))){
                aa = tr[j].a;
                bb = tr[j].b;
                cc = tr[j].c;
                tr[j].a = tr[j + 1].a;
                tr[j].b = tr[j + 1].b;
                tr[j].c = tr[j + 1].c;
                tr[j + 1].a = aa;
                tr[j + 1].b = bb;
                tr[j + 1].c = cc;

            }
        }
    }

	/**
	* Sort an array a of the length n
	*/
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = (triangle *)malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}