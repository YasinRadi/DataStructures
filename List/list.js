
class List {

  constructor() {
    this._size = 0
    this._capacity = 1
    this.items = [0]
  }

  add(item) {
    if (++this._size > this._capacity) {
      const tmp = new Array(this._capacity)
      for (let i = 0; i < this._size - 1; i++) {
        tmp[i] = this.items[i]
      }

      this.items = tmp;
    }

    this.items[this._size - 1] = item;
  }

  display() {
    return `[ ${this.items.slice(0, this._size).join(', ')} ]`
  }

  size() {
    return this._size
  }

  get(idx) {
    return this.checkIndex(idx) 
      ? this.items[idx]
      : undefined
  }

  indexOf(item) {
    for (let i = 0; i < this._size; i++) {
      if (item === this.items[i]) {
        return i
      }
    }

    return -1
  }

  removeByIndex(idx) {
    if (this.checkIndex(idx)) {
      for (let i = idx; i < this._size; i++) {
        this.items[i] = this.items[i + 1]
      }

      this.items[--this._size] = this.items[this._capacity - 1]
    }
  }

  remove(item) {
    const idx = this.indexOf(item)
    if (idx !== -1) {
      this.removeByIndex(idx)
    }
  }

  isEmpty() {
    return this._size === 0
  }

  contains(item) {
    return this.indexOf(item) !== -1
  }

  first() {
    return this.isEmpty()
      ? undefined
      : this.items[0]
  }

  last() {
    return this.isEmpty()
      ? undefined
      : this.items[this._size - 1]
  }

  set(idx, item) {
    if (this.checkIndex(idx)) {
      this.items[idx] = item
    }
  }

  capacity() {
    return this._capacity
  }

  checkIndex(idx) {
    return idx >= 0 && idx <= this._size
  }
}
