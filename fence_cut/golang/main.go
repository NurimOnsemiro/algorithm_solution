/**
* https://www.algospot.com/judge/problem/read/FENCE
* 실행시간: 672ms
 */

package main

import (
	"bufio"
	"fmt"
	"os"
)

//INFO: 스택 사용으로 최대 크기 + 1 위치를 접근할 수 있음
var fences [20001]int
var numFences int
var stk Stack

//Stack 스택
type Stack struct {
	//INFO: 0 인덱스는 비워두기 때문에 뒤에 한 개 더 필요함
	stack [20001]int
	top   int
}

//Push 스택에 값 삽입
func (c *Stack) Push(value int) {
	c.top++
	c.stack[c.top] = value
}

//Pop 스택에서 값 추출
func (c *Stack) Pop() {
	if c.top == 0 {
		return
	}
	c.stack[c.top] = 0
	c.top--
}

//Front 스택에서 값 조회
func (c *Stack) Front() (int, error) {
	if c.top == 0 {
		return 0, fmt.Errorf("Stack is empty")
	}

	return c.stack[c.top], nil
}

//Empty 스택 비어있는지 여부
func (c *Stack) Empty() bool {
	if c.top == 0 {
		return true
	}
	return false
}

//Clear 스택 초기화
func (c *Stack) Clear() {
	c.top = 0
}

func findMaxSizeFence() int {
	var maxSquareSize int = 0
	stk.top = 0
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
	r := bufio.NewReader(os.Stdin)
	var numTests int = 0
	stk = Stack{top: 0}

	fmt.Fscan(r, &numTests)

	for numTests > 0 {
		//INFO: 울타리 개수 입력
		fmt.Fscan(r, &numFences)

		for i := 0; i < numFences; i++ {
			fmt.Fscan(r, &fences[i])
		}

		maxSquareSize := findMaxSizeFence()

		fmt.Println(maxSquareSize)

		numTests--
	}
}
