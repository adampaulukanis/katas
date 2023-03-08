(defpackage #:test-roman-numerals
  (:use :cl :roman-numerals))

(defun generate-list ()
  (loop for i from 0 to 3999
        do
        (progn
          (princ i)
          (princ " ")
          (princ (from-number i))
          (fresh-line))))

(with-open-file (*standard-output*
                  "roman-numbers-list.txt"
                  :direction :output
                  :if-exists :supersede)
  (funcall #'generate-list))
