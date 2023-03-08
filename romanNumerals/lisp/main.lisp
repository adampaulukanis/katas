(defpackage #:roman-numerals
  (:use :cl)
  (:export :from-number))

(in-package #:roman-numerals)

(defun from-number (n)
  (if (= n 0)
      ""
      (format nil "~@R" n)))
