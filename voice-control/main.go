package main

import (
	"log"
	"os"

	"./server"
	"github.com/sirupsen/logrus"
)

func main() {
	logrus.SetLevel(logrus.DebugLevel)
	log.SetOutput(logrus.New().WriterLevel(logrus.DebugLevel))
	if err := server.Run(); err != nil {
		logrus.Error(err)
		os.Exit(1)
	}
}
