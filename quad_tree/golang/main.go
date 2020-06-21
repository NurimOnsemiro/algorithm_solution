/**
 * https://www.algospot.com/judge/problem/read/QUADTREE
 * 실행시간: 40ms
 */

package main

import (
	"fmt"
)

var str string
var temp [1000]byte
var arr [1000]byte
var dataLength int

//INFO: 쿼드트리 계산함수
func findQuadtree(currIndex *int) int {
	var head byte = arr[*currIndex]
	*currIndex++

	//INFO: 바이트 문자가 w 또는 b 인 경우
	if head == 'w' || head == 'b' {
		return 1
	}

	var startPos int = *currIndex

	var upperLeftLength int = findQuadtree(currIndex)
	var upperRightLength int = findQuadtree(currIndex)
	var lowerLeftLength int = findQuadtree(currIndex)
	var lowerRightLength int = findQuadtree(currIndex)

	var upperLength int = upperLeftLength + upperRightLength
	var lowerLength int = lowerLeftLength + lowerRightLength
	var upperEndPos int = startPos + upperLength
	var lowerStartPos int = upperEndPos
	var lowerEndPos int = lowerStartPos + lowerLength
	var newUpperStartPos int = startPos + lowerLength

	if upperLength > lowerLength {
		copy(temp[0:], arr[startPos:upperEndPos])
		copy(arr[startPos:], arr[lowerStartPos:lowerEndPos])
		copy(arr[newUpperStartPos:], temp[0:upperLength])
	} else {
		copy(temp[0:], arr[lowerStartPos:lowerEndPos])
		copy(arr[newUpperStartPos:], arr[startPos:upperEndPos])
		copy(arr[startPos:], temp[0:lowerLength])
	}

	//INFO: 같은 수준의 전체 문자길이 반환
	var totalLength int = upperLength + lowerLength + 1
	return totalLength
}

func main() {
	var numTests int = 0
	fmt.Scan(&numTests)

	for numTests > 0 {
		//INFO: 문자열 입력
		fmt.Scan(&str)
		//INFO: 문자열 길이 반환 (ASCII만 가능)
		dataLength = len(str)

		//INFO: 문자열을 바이트 배열에 복사
		copy(arr[:], str)

		var currIndex int = 0
		findQuadtree(&currIndex)

		//INFO: 바이트 배열을 문자열로 변환
		str = string(arr[0:dataLength])
		fmt.Println(str)

		numTests--
	}
}
