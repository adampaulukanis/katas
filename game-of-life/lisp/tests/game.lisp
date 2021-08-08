(defpackage :cl-gol/tests/game
  (:use :cl :fiveam :cl-mock :cl-gol/src/game)
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
  (with-mocks ()

              (answer (rules:alivep 0 1) 0)
              (answer (rules:alivep 0 2) 0)
              (answer (rules:alivep 0 3) 1)
              (answer (rules:alivep 1 2) 1)

              (answer (grid:neighbour-count *testgrid* 0 0) 1)
              (answer (grid:neighbour-count *testgrid* 0 1) 3)
              (answer (grid:neighbour-count *testgrid* 0 2) 2)
              (answer (grid:neighbour-count *testgrid* 1 0) 1)
              (answer (grid:neighbour-count *testgrid* 1 1) 2)
              (answer (grid:neighbour-count *testgrid* 1 2) 2)
              (answer (grid:neighbour-count *testgrid* 2 0) 1)
              (answer (grid:neighbour-count *testgrid* 2 1) 2)
              (answer (grid:neighbour-count *testgrid* 2 2) 2)

              (is (equalp (game:next-gen *testgrid*) *testgrid-expected*))

              (is (= (length (invocations 'rules:alivep)) 9))
              (is (= (length (invocations 'grid:neighbour-count)) 9))))

(run! 'next-gen-tests)
