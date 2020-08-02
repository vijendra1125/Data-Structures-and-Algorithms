#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

class Node;

class Node
{
public:
  int key;
  int level = 1;
  Node *parent;
  std::vector<Node *> children;

  Node()
  {
    this->parent = NULL;
  }

  void setParent(Node *theParent)
  {
    parent = theParent;
    parent->children.push_back(this);
  }
};

int breadth_wise_height(std::vector<Node> n, int root_idx)
{
  std::queue<Node> q;
  q.push(n[root_idx]);
  int max_height = 1;

  while (!q.empty())
  {
    for (auto it = q.front().children.begin(); it != q.front().children.end(); ++it)
    {
      if ((*(*it)).level == 1)
      {
        (*(*it)).level = q.front().level + 1;
      }
      q.push(*(*it));
    }
    max_height = std::max(max_height, q.back().level);
    q.pop();
  }
  return max_height;
}

int main_with_large_stack_space()
{
  std::ios_base::sync_with_stdio(0);
  int n;
  std::cin >> n;

  std::vector<Node> nodes;
  nodes.resize(n);
  int root_index;
  for (int child_index = 0; child_index < n; child_index++)
  {
    int parent_index;
    std::cin >> parent_index;
    if (parent_index >= 0)
      nodes[child_index].setParent(&nodes[parent_index]);
    else
      root_index = child_index;
    nodes[child_index].key = child_index;
  }

  // Replace this code with a faster implementation
  int maxHeight = 0;
  /*
  for (int leaf_index = 0; leaf_index < n; leaf_index++)
  {
    int height = 0;
    for (Node *v = &nodes[leaf_index]; v != NULL; v = v->parent)
      height++;
    maxHeight = std::max(maxHeight, height);
  }
  std::cout << "Naive: " << maxHeight << std::endl;
  */

  maxHeight = breadth_wise_height(nodes, root_index);
  std::cout << maxHeight << std::endl;
  return 0;
}

int main(int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024; // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
    if (rl.rlim_cur < kStackSize)
    {
      rl.rlim_cur = kStackSize;
      result = setrlimit(RLIMIT_STACK, &rl);
      if (result != 0)
      {
        std::cerr << "setrlimit returned result = " << result << std::endl;
      }
    }
  }

#endif
  return main_with_large_stack_space();
}
