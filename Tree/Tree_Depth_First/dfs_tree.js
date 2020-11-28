
class Node {
  constructor(data) {
    this.data = data
    this.left = null
    this.right = null
  }
}

class DFSTree {
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

  _postOrderHelper(node) {
    if (!node) {
      return
    }

    this._postOrderHelper(node.left)
    this._postOrderHelper(node.right)
    console.log(`${node.data} `)
  }

  _inOrderHelper(node) {
    if (!node) {
      return
    }

    this._inOrderHelper(node.left)
    console.log(`${node.data} `)
    this._inOrderHelper(node.right)
  }

  _preOrderHelper(node) {
    if (!node) {
      return
    }

    console.log(`${node.data} `)
    this._preOrderHelper(node.left)
    this._preOrderHelper(node.right)
  }

  postOrder() {
    this._postOrderHelper(this.root)
    console.log()
  }

  preOrder() {
    this._preOrderHelper(this.root)
    console.log()
  }

  inOrder() {
    this._inOrderHelper(this.root)
    console.log()
  }

  insert(data) {
    this.root = this._insertHelper(this.root, new Node(data))
  }
}
