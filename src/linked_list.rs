use std::fmt::Display;

type ListNode<T> = Option<Box<Node<T>>>;

struct Node<T> {
    // Data held by the node
    data: T,

    // Pointer to the next Node
    next: ListNode<T>,
}

impl <T: Copy> Node<T> where T: Display {
    fn new(v: T) -> Node<T> {
        Node::<T> {
            data: v,
            next: None,
        }
    }
}

pub struct LinkedList<T> {
    // Head of the list
    head: ListNode<T>,

    // Length of the list
    length: usize,
}

impl <T: Copy> LinkedList<T> where T: Display + {
    pub fn new() -> LinkedList<T> {
        LinkedList::<T> {
            head: None,
            length: 0,
        }
    }

    fn checkIndexBounds(&self, idx: usize) -> bool {
        idx <= self.length
    }

    pub fn add(&mut self, v: T) {
        let mut new_node: Box<Node<T>> = Box::new(Node::new(v));
        self.head = Some(new_node);
        self.length += 1;
    }

    pub fn display(&mut self) {
        let mut cur_node = self.head.take();
        while let Some(mut boxed_node) = cur_node {
            print!("{} ", boxed_node.data);
            cur_node = boxed_node.next.take();
        }
    }
}