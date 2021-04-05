package main

import "fmt"

// 字符串精简,给定一个字符串 连续相同的字符串抵消，一直这样执行。
// 例如： abccdbaabdbac 最后为c 1、找到相同的字符串，然后相当于回文的处理。
func CleanSeq(src string) (dst string) {
	dst = src
	// 开始找连续相同的字符串
	begin := -1
	end := 0
	for end < len(dst) {
		if begin < 0 || src[begin] != src[end] {
			begin++
		}
		end++
		// 找到了连续相同子串之后,第一个不相同的字符串
		if begin >= 0 && end-begin > 1 && src[begin] != src[end] {
			// 查找回文
			begin--
			for begin >= 0 && src[begin] == src[end] {
				begin--
				end++
			}
			if begin >= 0 {
				dst = dst[0:begin] + dst[end:]
			} else {
				dst = dst[end:]
			}
			begin = -1
			end = 0
			//fmt.Println(dst)
		}

	}
	return dst
}

func main() {
	fmt.Println(CleanSeq("abdbaabdbac"))

}
