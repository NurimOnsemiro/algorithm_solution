/**
* https://www.algospot.com/judge/problem/read/FENCE
* 실행시간: 2400ms
 */

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const maxStackSize int = 20001

//INFO: 스택 사용으로 최대 크기 + 1 위치를 접근할 수 있음
var fences [maxStackSize]int
var numFences int

var stack [maxStackSize]int
var top int

func stackClear() {
	top = 0
}

func stackPush(value int) {
	top++
	stack[top] = value
}

func stackPop() {
	if top == 0 {
		return
	}
	stack[top] = 0
	top--
}

func stackFront() int {
	if top == 0 {
		return 0
	}
	return stack[top]
}

func stackEmpty() bool {
	if top == 0 {
		return true
	}
	return false
}

func findMaxSizeFence() int {
	var maxSquareSize int = 0
	fences[numFences] = 0

	for i := 0; i <= numFences; i++ {
		for stackEmpty() == false {
			pos := stackFront()
			if fences[pos] >= fences[i] {
				stackPop()
				var width int = 0
				if stackEmpty() {
					width = i
				} else {
					nextPos := stackFront()
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

		stackPush(i)
	}

	return maxSquareSize
}

func main() {
	var numTests int = 0
	var maxSquareSize int = 0
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()

	numTests, _ = strconv.Atoi(scanner.Text())

	for numTests > 0 {
		stackClear()
		//INFO: 울타리 개수 입력
		scanner.Scan()
		numFences, _ = strconv.Atoi(scanner.Text())

		scanner.Scan()

		arr := strings.Split(scanner.Text(), " ")

		for idx, val := range arr {
			var result int
			result, _ = strconv.Atoi(val)
			fences[idx] = result
		}

		maxSquareSize = findMaxSizeFence()

		fmt.Fprintln(os.Stdout, maxSquareSize)

		numTests--
	}
}
