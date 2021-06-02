#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
         // for usleep


#define INF  1000000
   // infinity

// The adjacency matrix for the graph :
int N ; // number of nodes (vertices)
int A[100][100] ; // adjacency matrix of the graph
struct node{
    int r, c, weight;
} node[100];

struct table{
    int r, c, weight;
} table[100];


int input_graph()
{
  int r,c ;
  char w[10] ;

  scanf("%d",&N) ;
  
  // scan the first row of labels....not used
  for (c = 0 ; c < N ; c++) {
    scanf("%s",w) ;
  }
  

  for (r = 0 ; r < N ; r++) {
    scanf("%s",w) ; // label ... not used
    for (c = 0 ; c < N ; c++) {
      scanf("%s",w) ;
      if (w[0] == '-') {
	A[r][c] = -1 ;
      } else {
	A[r][c] = atoi(w) ;// ascii to integer
      }
      
    }
  }
  
}
int print_graph()
{
  int r,c ;

  printf("\n%d\n\n",N) ;
  
  printf("  ") ;
  for (c = 0 ; c < N ; c++) {
    printf("   %c",c+'A') ;
  }
 
  printf("\n") ;  
  
  for (r = 0 ; r < N ; r++) {
    printf("%c  ",r+'A') ;
    for (c = 0 ; c < N ; c++) {
      if (A[r][c] == -1) {
	printf("  - ") ;
      } else {
	printf("%3d ",A[r][c]) ;
      }
    }
    printf("\n") ;
  }
  printf("\n") ;  
}


int checkMax(){
    int k =0;
    for(int i=0; i< N; ++i){
        for(int j=0; j<N; ++j){
            if(A[i][j] > k){
                k = A[i][j];
            }
        }
    }
return k;
}

int checkRC(int r, int c){
    int i =0;
    while(node[i].weight != 0){
        if(node[i].c == r && node[i].r ==c) return 0;
        ++i;
    }
    return 1;
}

int sortmore(){
    int hold  = 1;
    int nodeI = 0;
    int max = checkMax();
    while(hold <= max){
        for(int r = 0; r < N; ++r){
            for(int c = 0; c < N; ++c){
                if(A[r][c] == hold){
                    if(checkRC(r,c) != 0){
                        node[nodeI].r = r;
                        node[nodeI].c = c;
                        node[nodeI].weight = A[r][c];
                        ++nodeI;
                    }
                }
            }
        }
    ++hold;
    }
}


void printSort(){
    int i = 0;
    while(node[i].weight != 0){
        printf("Sort: %d-Row || %d-Col || %d-weight\n", node[i].r, node[i].c, node[i].weight);
        ++i;
    }
}

int cycle(struct table curr, int FF){
    //check parent
    int hold = 0;
    int hold2 = 0;
    for(int i =0; i< N; ++i){
        if(curr.c == table[i].r || curr.c == table[i].c){
            if(curr.r != table[i].r){
                ++hold;
                if(hold == FF){
                    return 2;
                }
            }if(curr.c != table[i].c){
                ++hold;
                if(hold == FF){
                    return 2;
                }
            }
        }
    }
}

void printTable(){
    int result = 0;
    printf("The minimal spanning tree\n");
    for(int i =0; i < N-1; ++i){
        printf("Node: %d - %d\n", table[i].r, table[i].c);
        result += table[i].weight;
    }
    printf("Result: %d\n", result);
}
/*
    D E
    D H
    I F
    A B
    D C
    I G
    I E
    B C // Not C
    I H // make C
*/
int chooseSort(){
    int result = 0;
    int i = 0;
    int j = 0;
    int FF = sqrt(N); //Pattern that found while doing this program. if(the number of HIT is greater than square root of N, that is repeat as a cycle
    //if start = N-1 ->stop
    while(j<N-1){
        table[j].r = node[i].r;
        table[j].c = node[i].c;
        table[j].weight = node[i].weight;
        int test = cycle(table[j], FF);
        if(test == 2){
            --j;
        }
        //printf("%d - %d!!\n", table[j].r, table[j].c);
        ++i; ++j;
    };
    printTable();
}

int main()
{
  input_graph() ;// N, A{}{}  
  print_graph() ;

    sortmore();
    printSort();
    chooseSort();

}

