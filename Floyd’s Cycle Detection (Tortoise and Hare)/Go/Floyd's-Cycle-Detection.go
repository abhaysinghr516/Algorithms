package main

import "fmt"

type Node struct {
	data int
	next *Node
}

func hasCycle(head *Node) bool {
	slow := head
	fast := head

	for fast != nil && fast.next != nil {
		slow = slow.next
		fast = fast.next.next

		if slow == fast {
			return true
		}
	}
	return false
}

func main() {
	head := &Node{1, nil}
	head.next = &Node{2, nil}
	head.next.next = &Node{3, nil}
	head.next.next.next = &Node{4, nil}
	head.next.next.next.next = head.next // creates cycle

	if hasCycle(head) {
		fmt.Println("Cycle detected")
	} else {
		fmt.Println("No cycle")
	}
}
