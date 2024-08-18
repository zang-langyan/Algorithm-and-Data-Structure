package main

type ListNode struct {
  val int;
  nxt *ListNode;
}

var Logger logger = logging(false);

func (r *ListNode) append(v int) {
  node := r
  for node.nxt != nil{
    node = node.nxt
  }
  node.nxt = &ListNode{v, nil}
}

func main() {
  root := &ListNode{-1, nil}
  for i := range 7{
    root.append(i)
  }

  node := root
  for node != nil {
    Logger.Info("Node: ", node.val)
    node = node.nxt
  }
}

