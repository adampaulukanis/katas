(defpackage #:katas/multiple-of-3-or-5
  (:use #:cl)
  (:export #:solution))

(in-package #:katas/multiple-of-3-or-5)

(defun three-or-five (number)
  (or (= 0 (mod number 3)) (= 0 (mod number 5))))

(defun solution (number)
  (loop for x from 1 below number
        if (three-or-five x)
        sum x))


;;;; Tests
(solution 10)
(= (solution 10) 23)
(= (solution 20) 78)
(= (solution 200) 9168)
(= (solution -1) 0)
(= (solution 0) 0)
(= (solution 1) 0)
(= (solution 2) 0)
(= (solution 3) 0)
(= (solution 4) 3)
(= (solution 5) 3)
(= (solution 6) 8)
