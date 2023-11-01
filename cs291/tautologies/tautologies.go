package main

import (
	"fmt"
	"strings"
)

const TargetSize int = 1000
const Seed string = "W"
var currentToken rune
var currentTokenIndex int
var currentExpression string
func main() {
	replacements := []string{"F", "T", "A", "B", "C", "W=W", "W>W", "W&W", "W+W", "~W", "(W)"}
	queue := []string{Seed}
	wffs := make([]string, 0)

	numberGenerated := 0
	for len(queue) > 0 && numberGenerated < TargetSize {
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
					} else if isUnique(&wffs, candidate) {
						wffs = append(wffs, candidate)

						// replace A's and B's with T's and F's
						var expression1 string
						expression1 = strings.Replace(candidate, "A", "T", -1)
						expression1 = strings.Replace(expression1, "B", "T", -1)

						var expression2 string
						expression2 = strings.Replace(candidate, "A", "T", -1)
						expression2 = strings.Replace(expression2, "B", "F", -1)

						var expression3 string
						expression3 = strings.Replace(candidate, "A", "F", -1)
						expression3 = strings.Replace(expression3, "B", "T", -1)

						var expression4 string
						expression4 = strings.Replace(candidate, "A", "F", -1)
						expression4 = strings.Replace(expression4, "B", "F", -1)

						// parse each and check if a tautology
						if isTrue(expression1) && isTrue(expression2) && isTrue(expression3) && isTrue(expression4) {
							numberGenerated++
							fmt.Print(candidate, "\n")
						}
					}
				}
				queue = queue[1:] // remove the first element of the queue
				break
			}
		}
	}
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

func isTrue(candidate string) bool {
	currentExpression = candidate
	currentTokenIndex = 0
	currentToken = rune(currentExpression[currentTokenIndex])
	return B()
}

func getNextToken() {
	currentTokenIndex++
	if currentTokenIndex < len(currentExpression) {
		currentToken = rune(currentExpression[currentTokenIndex])
	} else {
		currentToken = '$'
	}
}

func B() bool {
	return E()
}

func E() bool {
	temp := I()
	return EPrime(temp)
}

func EPrime(incoming bool) bool {
	if currentToken == '=' {
		getNextToken();
		temp := I();
		return EPrime(incoming == temp)
	}
	return incoming;
}

func I() bool {
	temp := D()
	return IPrime(temp)
}

func IPrime(incoming bool) bool {
	if currentToken == '>' {
		getNextToken()
		temp := D()
		return IPrime(!incoming || temp)
	}
	return incoming
}

func D() bool {
	temp := C()
	return DPrime(temp)
}

func DPrime(incoming bool) bool {
	if currentToken == '+' {
		getNextToken()
		temp := C()
		return DPrime(incoming || temp)
	}
	return incoming
}

func C() bool {
	temp := A()
	return CPrime(temp)
}

func CPrime(incoming bool) bool {
	if currentToken == '&' {
		getNextToken()
		temp := A()
		return CPrime(incoming && temp)
	}
	return incoming
}

func A() bool {
	if currentToken == '~' {
		getNextToken()
		temp := A()
		return !temp
	} else if currentToken == 'T' {
		getNextToken()
		return true
	} else if currentToken == 'F' {
		getNextToken()
		return false
	} else if currentToken == '(' {
		getNextToken()
		temp := B()
		if currentToken == ')' {
			getNextToken()
			return temp
		}
	}
	return false
}
