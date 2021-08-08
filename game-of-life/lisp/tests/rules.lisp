(defpackage :cl-gol/tests/rules
  (:use :cl :fiveam :cl-gol/src/rules)
  (:export #:run!
           #:all-tests
           #:nil))

(in-package :cl-gol/tests/rules)

(def-suite rules-tests
           :description "Unit tests for rules")

(in-suite rules-tests)

(test alivep-test
  (is (= (rules:alivep 1 0) 0))
  (is (= (rules:alivep 1 1) 0))
  (is (= (rules:alivep 1 2) 1))
  (is (= (rules:alivep 1 3) 1))
  (is (= (rules:alivep 1 4) 0))
  (is (= (rules:alivep 1 5) 0))
  (is (= (rules:alivep 1 6) 0))
  (is (= (rules:alivep 0 3) 1))
  )

(run! 'alivep-test)
