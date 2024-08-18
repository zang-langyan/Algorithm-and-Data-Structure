package main

type Tree interface {
  Insert(val int);
  Search(val int) Tree;
  DeleteNode(val int) Tree;
  Traverse(t int); /* Traverse Type: 1. Pre-traverse, 2. Mid-traverse, 3. Post-traverse */
}
