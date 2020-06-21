/**
* https://www.algospot.com/judge/problem/read/FENCE
* 실행시간: 40ms
 */

package main

import (
	"container/list"
	"fmt"
)

var fences [20000]int
var numFences int

//Stack 스택
type Stack struct {
	stack *list.List
}

//Push 삽입
func (c *Stack) Push(value int) {
	c.stack.PushFront(value)
}

//Pop 추출
func (c *Stack) Pop() error {
	if c.stack.Len() > 0 {
		ele := c.stack.Front()
		c.stack.Remove(ele)
		return nil
	}
	return fmt.Errorf("Pop Error: Queue is empty")
}

//Front 조회
func (c *Stack) Front() (int, error) {
	if c.stack.Len() > 0 {
		if val, ok := c.stack.Front().Value.(int); ok {
			return val, nil
		}
		return 0, fmt.Errorf("Peep Error: Queue Datatype is incorrect")
	}
	return 0, fmt.Errorf("Peep Error: Queue is empty")
}

//Empty 비어있는지 여부
func (c *Stack) Empty() bool {
	return c.stack.Len() == 0
}

func findMaxSizeFence() int {
	var maxSquareSize int = 0
	stk := &Stack{
		stack: list.New(),
	}
	fences[numFences] = 0

	for i := 0; i <= numFences; i++ {
		for stk.Empty() == false {
			pos, _ := stk.Front()
			if fences[pos] >= fences[i] {
				stk.Pop()
				var width int = 0
				if stk.Empty() {
					width = i
				} else {
					nextPos, _ := stk.Front()
					width = i - nextPos - 1
				}
				squareSize := width * fences[pos]
				if squareSize > maxSquareSize {
					maxSquareSize = squareSize
				}
			} else {
				break
			}
		}

		stk.Push(i)
	}

	return maxSquareSize
}

func main() {
	var numTests int = 0
	fmt.Scan(&numTests)

	for numTests > 0 {
		//INFO: 울타리 개수 입력
		fmt.Scan(&numFences)

		for i := 0; i < numFences; i++ {
			fmt.Scan(&fences[i])
		}

		maxSquareSize := findMaxSizeFence()

		fmt.Println(maxSquareSize)

		numTests--
	}
}
