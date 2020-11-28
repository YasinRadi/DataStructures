
const COLOR = Object.freeze({
  RED: Symbol("red"),
  BLACK: Symbol("black")
})

class Node {
  constructor(data) {
    this.data = data
    this.color = null
    this.left = null
    this.right = null
    this.parent = null
  }
}


class RedBlackTree {
  constructor() {
    this.root = null
  }

  _bstInsert(root, node) {
    if (!root) {
      return node
    }

    if (node.data < root.data) {
      root.left = this._bstInsert(root.left, node)
      root.left.parent = root
    } else if (node.data > root.data) {
      root.right = this._bstInsert(root.right, node)
      root.right.parent = root
    }

    return root
  }

  _inOrderHelper(node) {
    if (!node) {
      return
    }

    this._inOrderHelper(node.left)
    console.log(`${node.data} `)
    this._inOrderHelper(node.right)
  }

  _levelOrderHelper(node) {
    if (!node) {
      return
    }

    const q = []
    q.push(node)

    while (q.length) {
      let tmpNode = q.shift()
      console.log(`${node.data} `)

      if (tmpNode.left) {
        q.push(tmpNode.left)
      }

      if (tmpNode.right) {
        q.push(tmpNode.right)
      }
    }
  }

  rotateLeft(node) {
    let rightNode = node.right
    node.right = rightNode.left

    if (node.right) {
      node.right.parent = node
    }

    rightNode.parent = node.parent

    if (!node.parent) {
      this.root = rightNode
    } else if (node === node.parent.left) {
      node.parent.left = rightNode
    } else {
      node.parent.right = rightNode
    }

    rightNode.left = node
    node.parent = rightNode
  }

  rotateRight(node) {
    let leftNode = node.left
    node.left = leftNode.right

    if (node.left) {
      node.left.parent = node
    }

    leftNode.parent = node.parent

    if (!node.parent) {
      this.root = leftNode
    } else if (node === node.parent.left) {
      node.parent.left = leftNode
    } else {
      node.parent.right = leftNode
    }

    leftNode.right = node
    node.parent = leftNode
  }

  fixViolation(node) {
    let parentNode = null
    let grandParentNode = null

    while (node !== this.root && node.color === COLOR.RED
      && node.parent.color === COLOR.RED) {
        parentNode = node.parent
        grandParentNode = parentNode.parent

        if (parentNode === grandParentNode.left) {
          let uncleNode = grandParentNode.right

          if (uncleNode && uncleNode.color === COLOR.RED) {
            grandParentNode.color = COLOR.RED
            parentNode.color = COLOR.BLACK
            uncleNode.color = COLOR.BLACK
          } else {
            if (node === parentNode.right) {
              this.rotateLeft(parentNode)
              node = parentNode
              parentNode = node.parent
            }

            this.rotateRight(grandParentNode)
            const tmpColor = parentNode.color
            parentNode.color = grandParentNode.color
            grandParentNode.color = tmpColor
            node = parentNode
          }
        } else {
          if (node === parentNode.left) {
            this.rotateRight(parentNode)
            node = parentNode
            parentNode = node.parent
          }

          this.rotateLeft(grandParentNode)
          const tmpColor = parentNode.color
          parentNode.color = grandParentNode.color
          grandParentNode.color = tmpColor
          node = parentNode
        }
      }

      this.root.color = COLOR.BLACK
  }

  insert(data) {
    let node = new Node(data)
    this.root = this._bstInsert(this.root, node)
    this.fixViolation(node)
  }

  inOrder() {
    this._inOrderHelper(this.root)
    console.log()
  }

  levelOrder() {
    this._levelOrderHelper(this.root)
    console.log()
  }
}
