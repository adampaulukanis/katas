(defpackage :cl-gol/tests/game
  (:use :cl :fiveam :cl-mock :cl-gol/src/game) ;; import
  (:export #:run!
           #:all-tests
           #:nil))

(in-package :cl-gol/tests/game)

(def-suite game-tests
           :description "Unit tests for game")

(in-suite game-tests)

(defparameter *testgrid* #(#(0 0 1)
                           #(0 1 1)
                           #(0 0 0)))

(defparameter *testgrid-expected* #(#(0 1 1)
                                     #(0 1 1)
                                     #(0 0 0)))

(test next-gen-tests
  (is (equalp (game:next-gen *testgrid*) *testgrid-expected*)))

(run! 'next-gen-tests)
