#include <stdio.h>
#include <stdlib.h>

typedef struct AdjListNode {
  int node;
  struct AdjListNode *next;
} AdjListNode;

typedef struct AdjList {
  struct AdjListNode *head;
} AdjList;

typedef struct Graph {
  int num;
  struct AdjList *array;
} Graph;

struct AdjListNode *newnode (int node){
  AdjListNode *new_node = (AdjListNode*)malloc(sizeof(AdjListNode));
  new_node->node = node;
  new_node->next = NULL;
  return new_node;
}

void add_edge (Graph *graph, int src, int dest){
  AdjListNode *new_node_added = newnode(dest);
  new_node_added->next = graph->array[src].head;
  graph->array[src].head = new_node_added;

  new_node_added = newnode(src);
  new_node_added->next = graph->array[dest].head;
  graph->array[dest].head = new_node_added;
}

struct Graph *newGraph (int num_of_vertices){
  Graph *new_graph = (Graph*)malloc(sizeof(Graph));
  new_graph->num = num_of_vertices;
  new_graph->array = (AdjList*)malloc(num_of_vertices*sizeof(AdjList));
  int i = 0;
  for (i;i<num_of_vertices;++i){
    new_graph->array[i].head = NULL;
  }
  return new_graph;
}

void printGraph(struct Graph* graph)
{
    int temp;
    for (temp = 0; temp < graph->num; ++temp)
    {
        struct AdjListNode* node1 = graph->array[temp].head;
        printf("\n Adjacency list of vertex %d\n head ", temp);
        while (node1)
        {
            printf("-> %d", node1->node);
            node1 = node1->next;
        }
        printf("\n");
    }
}

int main()
{
    // create the graph given in above fugure
    int V = 5;
    struct Graph* graph = newGraph(V);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 4);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);

    // print the adjacency list representation of the above graph
    printGraph(graph);

    return 0;
}
