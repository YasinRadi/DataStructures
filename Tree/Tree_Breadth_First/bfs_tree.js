
class Node {
  
  constructor(data) {
    this.data = data
    this.left = null
    this.right = null
  }
}

class BFSTree {

  constructor() {
    this.root = null
  }

  _insertHelper(root, node) {
    if (!root) {
      root = node
      return node
    }

    if (node.data < root.data) {
      root.left = this._insertHelper(root.left, node)
    } else if (node.data > root.data) {
      root.right = this._insertHelper(root.right, node)
    }

    return root
  }

  _inorderHelper(node) {
    if (!node) {
      return
    }

    this._inorderHelper(node.left)
    console.log(`${node.data} `)
    this._inorderHelper(node.right)
  }

  _levelOrderHelper(node) {
    if (!node) {
      return
    }

    const q = []
    q.push(node)

    while (q.length > 0) {
      let tmpNode = q.shift()
      console.log(`${tmpNode.data} `)

      if (tmpNode.left) {
        q.push(tmpNode.left)
      }

      if (tmpNode.right) {
        q.push(tmpNode.right)
      }
    }
  }

  insert(data) {
    this.root = this._insertHelper(this.root, new Node(data))
  }

  inorder() {
    this._inorderHelper(this.root)
    console.log()
  }

  levelOrder() {
    this._levelOrderHelper(this.root)
    console.log()    
  }
}
