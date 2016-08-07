import java.io.*;
import java.util.*;

// Considering that this is a directed graph
// When an edge is added it is only added to 
// the adjancey list of the source node

class Graph {
  private int n;
  private LinkedList<Integer>[] adj_list;

  Graph (int number){
    n = number;
    adj_list = new LinkedList[n];
    for (int i=0;i<n;++i){
      adj_list[i] = new LinkedList();
    }
  }

  void add_edge_graph (int src, int dest){
    adj_list[src].add(dest);
  }

  void breadth_first_search (int source){
    boolean[] visited = new boolean[n];
    Queue<Integer> myqueue = new LinkedList<Integer>();
    visited[source] = true;
    myqueue.add(source);
    while (myqueue.size() != 0){
      source = myqueue.poll();
      System.out.print(source+" ");
      Iterator<Integer> i = adj_list[source].listIterator();
      while (i.hasNext()){
        int n = i.next();
        if (!visited[n]){
          visited[n] = true;
          myqueue.add(n);
        }
      }
    }
  }

  public static void main (String args[]){
    Graph graph1 = new Graph(4);
    graph1.add_edge_graph(0,1);
    graph1.add_edge_graph(0,2);
    graph1.add_edge_graph(1,2);
    graph1.add_edge_graph(2,0);
    graph1.add_edge_graph(2,3);
    graph1.add_edge_graph(3,3);

    graph1.breadth_first_search(2);
  }
}
