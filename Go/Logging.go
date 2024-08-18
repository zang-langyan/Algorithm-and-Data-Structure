package main

import (
  "fmt"
)

type logger interface {
  Info(s...any);
  Warning(s...any);
  Error(s...any)
}

type logging bool

func (recv logging) Info(s...any){
  fmt.Print("\033[1;37m")
  fmt.Print(s...)
  fmt.Println("\033[0m")
}

func (recv logging) Error(s...any){
  fmt.Print("\033[1;31m")
  fmt.Print(s...)
  fmt.Println("\033[0m")
}

func (recv logging) Warning(s...any){
  fmt.Print("\033[1;33m")
  fmt.Print(s...)
  fmt.Println("\033[0m")
}

var COLOR_MAP map[string]string = map[string]string{
  "red":    "31",
  "green":  "32",
  "yellow": "33",
  "blue":   "34",
  "magenta":"35",
  "cyan":   "36",
  "white":  "37",
}

var IDX_COLOR_MAP []string = []string{
  "red",
  "green",
  "yellow",
  "blue",
  "magenta",
  "cyan",
  "white",
};

func print(color string, s...any){
  pre := "\033[1;" + COLOR_MAP[color] + "m"
  suf := "\033[0m"
  fmt.Print(pre)
  fmt.Print(s...)
  fmt.Println(suf)
}
