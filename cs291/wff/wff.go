// Karl Ramberg
// 10-18-19

package main

import (
	"fmt"
	"strings"
)

const TargetSize int = 100
const Seed string = "W"
func main() {
	replacements := []string{"F", "T", "A", "B", "C", "W=W", "W>W", "W&W", "W+W", "~W", "(W)"}
	queue := []string{Seed}
	wffs := make([]string, 0)

	for len(queue) > 0 && len(wffs) < TargetSize {
		// take the first off the queue
		candidate := queue[0]

		// find the first W
		for index, character := range candidate {
			if character == 'W' {
				// replace W with each replacement
				for _, replacement := range replacements {
					candidate := candidate[:index] + replacement + candidate[index+1:]

					// if there is more to be replaced, put it back on the queue
					if strings.Contains(candidate, "W") {
						queue = append(queue, candidate)
					} else if isUnique(&wffs, candidate) && len(wffs) < TargetSize {
						wffs = append(wffs, candidate)
						fmt.Print(candidate, "\n")
					}

				}
				queue = queue[1:] // remove the first element of the queue
				break
			}
		}
	}
	fmt.Print("Queue was ", len(queue), " elements long\n")
}

func isUnique(list *[]string, formula string) bool {
	// if already in the list
	for _, val := range *list {
		if val == formula {
			return false;
		}
	}

	aFound := false
	bFound := false
	for _, character := range formula {
		if character == 'A' {
			aFound = true
		}

		if character == 'B' {
			bFound = true
		}

		// if there is a B without an A
		if character == 'B' && !aFound {
			return false;
		}

		// if there is a C without a B
		if character == 'C' && !bFound {
			return false;
		}
	}

	return true
}