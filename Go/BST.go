/* Careful! Go's nil pointer does not have an assignable address */
package main

type BST struct {
  val   int;
  left  *BST;
  right *BST;
}

func main() {
  var Logger logger = logging(false)
  var root *BST = &BST{-1, nil, nil}
  var node Tree = root
  values := []int{60,55,78,96,13,15,17,29,36}

  for _, v := range values {
    node.Insert(v)
    Logger.Error(v)
  }

  Logger.Warning(root.left, root.right)

  node.Traverse(1)
}

func (node *BST) Insert(val int) {
  if val > node.val {
    if node.right == nil {
      node.right = &BST{val, nil, nil}
      return
    }
    node.right.Insert(val)
  } else {
    if node.left == nil {
      node.left = &BST{val, nil, nil}
      return
    }
    node.left.Insert(val)
  }
}

func (node *BST) Search(target int) Tree {
  if node == nil {
    return nil
  }

  if node.val < target {
    return node.right.Search(target)
  } else if node.val > target {
    return node.left.Search(target)
  }

  return node
}

func (node *BST) DeleteNode(target int) Tree {
  if node == nil {
    return nil
  }

  if node.val < target {
    bridging, _ := node.right.DeleteNode(target).(*BST)
    node.right = bridging 
  } else if node.val > target{
    bridging, _ := node.left.DeleteNode(target).(*BST)
    node.left = bridging 
  }

  if node.left == nil && node.right == nil {
    return nil
  } else if node.left == nil && node.right != nil {
    return node.right
  } else if node.left != nil && node.right == nil {
    return node.left
  } else {
    /* 1. Add Right Tree To the Left */
    var cur *BST = node.left
    for cur.right != nil {
      cur = cur.right
    }
    cur.right = node.right
    return node.left

    /* 2. Add Right Tree To the Left */
    // var cur *BST = node.right
    // for cur.left != nil {
    //   cur = cur.left
    // }
    // cur.left = node.left
    // return node.right
  } 
}

func (node *BST) Traverse(t int) {
  if node == nil {
    return
  }

  var Logger logger = logging(false)
  if t == 1 { // Pre-Traverse
    Logger.Info(node.val) 
    node.left.Traverse(t)
    node.right.Traverse(t)
  } else if t == 2 { // Mid-Traverse
    node.left.Traverse(t)
    Logger.Info(node.val) 
    node.right.Traverse(t)
  } else if t == 3 { // Post-Traverse
    node.left.Traverse(t)
    node.right.Traverse(t)
    Logger.Info(node.val) 
  }

}
