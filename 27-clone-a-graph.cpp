#include <bits/stdc++.h>
using namespace std;

struct UndirectedGraphNode {
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : label(x){};
};

UndirectedGraphNode *
dfs(UndirectedGraphNode *node,
    map<UndirectedGraphNode *, UndirectedGraphNode *>& oldToNew) {
  if (oldToNew[node])
    return oldToNew[node];
  UndirectedGraphNode *copy = new UndirectedGraphNode(node->label);
  oldToNew[node] = copy;
  for (auto nod : node->neighbors) {
    copy->neighbors.push_back(dfs(nod, oldToNew));
  }
  return copy;
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
  if (!node)
    return node;
  map<UndirectedGraphNode *, UndirectedGraphNode *> oldToNew;
  return dfs(node, oldToNew);
}
