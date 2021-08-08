(defpackage :cl-gol/tests/grid
  (:use :cl :fiveam :cl-gol/src/grid)
  (:export #:run!
           #:all-tests
           #:nil))

(in-package :cl-gol/tests/grid)

(def-suite grid-tests
           :description "Unit tests for grid")

(defparameter *grid1* #(#(0 1)
                        #(1 1)))

(test count-1
  (is (= (grid:neighbour-count *grid1* 0 0) 3))
  (is (= (grid:neighbour-count *grid1* 0 1) 2))
  (is (= (grid:neighbour-count *grid1* 1 0) 2))
  (is (= (grid:neighbour-count *grid1* 1 1) 2))
)

;; Add more tests, bigger grids

(run! 'count-1)
