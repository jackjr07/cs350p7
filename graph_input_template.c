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

int main()
{
  input_graph() ;// N, A{}{}  
  //printf("A[1][2]: %d\n", A[1][0]);
  print_graph() ;

    sortmore();
    printSort();

}

