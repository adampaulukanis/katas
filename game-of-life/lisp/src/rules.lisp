(defpackage :cl-gol/src/rules
  (:use :cl)
  (:nicknames :rules)
  (:export :alivep))

(in-package :cl-gol/src/rules)

(defun alivep (state neighbour-count)
  (cond
    ((and (= state 1) (or (= neighbour-count 2)
                          (= neighbour-count 3))) 1)
    ((and (= state 0) (= neighbour-count 3)) 1)
    (t 0)))
