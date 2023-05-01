#include <stdio.h>

/*From
https://www.thecrazyprogrammer.com/2014/03/kruskalAlgos-algorithm-for-finding-min*/

#define MAX 30

typedef struct edge {
  int u, v, w;
} edge;

typedef struct edge_L {
  edge data[MAX];
  int n;
} edge_L;

edge_L eList;

int Graph[MAX][MAX], n;
edge_L spanList;

int find(int belongs[], int vertexno) { return (belongs[vertexno]); }

void union1(int belongs[], int c1, int c2) {
  for (int i = 0; i < n; i++) {
    if (belongs[i] == c2) {
      belongs[i] = c1;
    }
  }
}

void swap(edge *a, edge *b) {
  edge temp = *a;
  *a = *b;
  *b = temp;
}

void sort() {
  for (int i = 1; i < eList.n; i++) {
    for (int j = 0; j < eList.n - 1; j++) {
      if (eList.data[j].w > eList.data[j + 1].w) {
        swap(&eList.data[j], &eList.data[j + 1]);
      }
    }
  }
}

void print() {
  int cost = 0;
  printf("\n\nVertex       Goes To         Weight");
  for (int i = 0; i < spanList.n; i++) {
    printf("\n   %c\t\t%c\t\t%d", spanList.data[i].v + 65,
           spanList.data[i].u + 65, spanList.data[i].w);
    cost = cost + spanList.data[i].w;
  }
  printf("\n\nCost of the spanning tree: %d", cost);
}

void kruskalAlgo() {
  int belongs[MAX], cno1, cno2;
  eList.n = 0;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (Graph[i][j] != 0) {
        eList.data[eList.n].u = i;
        eList.data[eList.n].v = j;
        eList.data[eList.n].w = Graph[i][j];
        eList.n++;
      }
    }
  }
  sort();
  for (int i = 0; i < n; i++) {
    belongs[i] = i;
  }
  spanList.n = 0;
  for (int i = 0; i < eList.n; i++) {
    cno1 = find(belongs, eList.data[i].u);
    cno2 = find(belongs, eList.data[i].v);
    if (cno1 != cno2) {
      spanList.data[spanList.n] = eList.data[i];
      spanList.n = spanList.n + 1;
      union1(belongs, cno1, cno2);
    }
  }
}

void main() {
  printf("\nEnter number of vertices: ");
  scanf("%d", &n);
  printf("\nEnter the adjacency matrix (weights from point to point):\n\n");
  printf("   ");
  for (int i = 0; i < n; i++) {
    printf("%c ", i + 65);
    if (i + 1 == n) {
      printf("\n");
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%c: ", i + 65);
    for (int j = 0; j < n; j++) {
      scanf("%d", &Graph[i][j]);
    }
  }
  kruskalAlgo();
  print();
}