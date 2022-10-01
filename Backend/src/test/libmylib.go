package main

/*
  #include "../../includes/config/Connect.hpp"
  #include "../../app/config/Connect.cpp"
*/
import "C"

import (
	"fmt"
)

//export say
func say(text *C.char) {
	fmt.Println(C.GoString(text))
}

func main() {
	t := Connect{}
}
