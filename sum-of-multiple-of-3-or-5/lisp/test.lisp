(in-package #:cl-user)
(defpackage #:katas/tests/multiple-of-3-or-5
  (:use #:cl
        #:rove
        #:katas/multiple-of-3-or-5))
(in-package #:katas/tests/multiple-of-3-or-5)

(deftest test-solution
  (testing "basic tests"
    (ok (= (solution 10) 23))
    (ok (= (solution 20) 78))
    (ok (= (solution 200) 9168)))
  (testing "smallest cases"
    (ok (= (solution -1) 0))
    (ok (= (solution 0) 0))
    (ok (= (solution 1) 0))
    (ok (= (solution 2) 0))
    (ok (= (solution 3) 0))
    (ok (= (solution 4) 3))
    (ok (= (solution 5) 3))
    (ok (= (solution 6) 8))
    ))
