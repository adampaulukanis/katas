(defpackage :cl-gol/tests/it-game
  (:use :cl :fiveam :cl-gol/src/game)
  (:export #:run!
           #:all-tests
           #:nil))
(in-package :cl-gol/tests/it-game)

(def-suite it-game
           :description "Integration tests for Game of Life")

(in-suite it-game)


(defparameter *grid1* #(#(0 0 0)
                        #(0 1 0)
                        #(0 0 0)))
(defparameter *grid1-expected* #(#(0 0 0)
                                 #(0 0 0)
                                 #(0 0 0)))

(test sc1
  "Scenario 1"
  (is (equalp  (game:next-gen *grid1*) *grid1-expected* )))

(run! 'sc1)
